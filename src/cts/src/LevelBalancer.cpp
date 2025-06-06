// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2019-2025, The OpenROAD Authors

#include "LevelBalancer.h"

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "Clock.h"
#include "CtsOptions.h"
#include "TreeBuilder.h"
#include "cts/TritonCTS.h"
#include "odb/db.h"

namespace cts {

using utl::CTS;

void LevelBalancer::run()
{
  debugPrint(logger_, CTS, "levelizer", 1, "Computing Max Tree Depth");
  const unsigned maxTreeDepth = computeMaxTreeDepth(root_);
  logger_->info(CTS, 93, "Fixing tree levels for max depth {}", maxTreeDepth);
  levelBufCount_ = 0;
  fixTreeLevels(root_, 0, maxTreeDepth);
}

unsigned LevelBalancer::computeMaxTreeDepth(TreeBuilder* parent)
{
  unsigned maxDepth = 0;
  for (const auto& child : parent->getChildren()) {
    // also count itself - non sink inst
    const unsigned depth = computeMaxTreeDepth(child) + 1;
    odb::dbObject* driverPin = child->getClock().getDriverPin();
    if (driverPin && driverPin->getObjectType() == odb::dbITermObj) {
      odb::dbInst* drivingInst
          = (static_cast<odb::dbITerm*>(driverPin))->getInst();
      debugPrint(logger_,
                 CTS,
                 "levelizer",
                 1,
                 "Downstream depth is {} from driver {}",
                 depth,
                 child->getClock().getName());
      cgcLevelMap_[drivingInst] = std::make_pair(depth, child);
    }
    if (depth > maxDepth) {
      maxDepth = depth;
    }
  }
  return parent->getTreeBufLevels() + maxDepth;
}

void LevelBalancer::addBufferLevels(TreeBuilder* builder,
                                    const std::vector<ClockInst*>& cluster,
                                    ClockSubNet* driverNet,
                                    const unsigned bufLevels,
                                    const std::string& nameSuffix)
{
  ClockSubNet* prevLevelSubNet = driverNet;

  // Compute driver, receiver locations
  double totalX = 0, totalY = 0;
  for (ClockInst* clockInstObj : cluster) {
    totalX += clockInstObj->getX();
    totalY += clockInstObj->getY();
  }
  const double centroidX = totalX / cluster.size();
  const double centroidY = totalY / cluster.size();
  const int driverX = prevLevelSubNet->getDriver()->getX();
  const int driverY = prevLevelSubNet->getDriver()->getY();

  for (unsigned level = 0; level < bufLevels; level++) {
    // Add buffer
    double x
        = (driverX
           + (centroidX - driverX) * (double) (level + 1) / (bufLevels + 1))
          / wireSegmentUnit_;
    double y
        = (driverY
           + (centroidY - driverY) * (double) (level + 1) / (bufLevels + 1))
          / wireSegmentUnit_;
    Point<double> bufferLoc(x, y);
    Point<double> legalBufferLoc
        = builder->legalizeOneBuffer(bufferLoc, options_->getSinkBuffer());
    ClockInst& levelBuffer = builder->getClock().addClockBuffer(
        "clkbuf_level_" + std::to_string(level) + "_" + nameSuffix
            + std::to_string(levelBufCount_),
        options_->getSinkBuffer(),
        legalBufferLoc.getX() * wireSegmentUnit_,
        legalBufferLoc.getY() * wireSegmentUnit_);
    builder->commitLoc(legalBufferLoc);
    builder->addTreeLevelBuffer(&levelBuffer);

    // Add Net
    ClockSubNet* levelSubNet = &(builder->getClock().addSubNet(
        "clknet_level_" + std::to_string(level) + "_" + nameSuffix
        + std::to_string(levelBufCount_)));
    levelBufCount_++;
    // Connect to driving and driven nets
    prevLevelSubNet->addInst(levelBuffer);
    levelSubNet->addInst(levelBuffer);
    prevLevelSubNet->setLeafLevel(false);
    prevLevelSubNet = levelSubNet;
  }
  // Add sinks to leaf buffer
  for (ClockInst* clockInstObj : cluster) {
    prevLevelSubNet->addInst(*clockInstObj);
  }
  prevLevelSubNet->setLeafLevel(true);
}

void LevelBalancer::fixTreeLevels(TreeBuilder* builder,
                                  const unsigned parentDepth,
                                  const unsigned maxTreeDepth)
{
  const unsigned currLevel = builder->getTreeBufLevels() + parentDepth;
  if (currLevel >= maxTreeDepth) {
    return;
  }

  logger_->report(
      "Fixing from level {} (parent={} + current={}) to max {} for driver {}",
      parentDepth + builder->getTreeBufLevels(),
      parentDepth,
      builder->getTreeBufLevels(),
      maxTreeDepth,
      builder->getClock().getName());
  unsigned clusterCnt = 0;
  builder->getClock().forEachSubNet([&](ClockSubNet& subNet) {
    std::map<unsigned, std::vector<ClockInst*>> subClusters;
    std::set<ClockInst*> instsToRemove;
    subNet.forEachSink([&](ClockInst* clkInst) {
      if (!clkInst->getDbInputPin()) {
        return;
      }
      odb::dbInst* inst = clkInst->getDbInputPin()->getInst();
      if (cgcLevelMap_.find(inst) == cgcLevelMap_.end()) {
        subClusters[currLevel].emplace_back(clkInst);
      } else {
        subClusters[cgcLevelMap_[inst].first + currLevel].emplace_back(clkInst);
      }
      instsToRemove.insert(clkInst);
    });
    if (subClusters.empty()) {
      return;
    }

    clusterCnt++;
    subNet.removeSinks(std::move(instsToRemove));
    subNet.setLeafLevel(false);
    unsigned subClusterCnt = 0;
    for (const auto& cluster : subClusters) {
      const unsigned clusterLevel = cluster.first;
      const unsigned bufLevels = maxTreeDepth - clusterLevel;
      subClusterCnt++;
      const std::string suffix
          = std::to_string(subClusterCnt) + "_" + std::to_string(clusterCnt);
      debugPrint(logger_,
                 CTS,
                 "levelizer",
                 1,
                 "Adding buffer levels: {} to net {} with {} subClusters",
                 bufLevels,
                 subNet.getName(),
                 subClusterCnt);
      addBufferLevels(builder, cluster.second, &subNet, bufLevels, suffix);

      if (currLevel != clusterLevel) {
        for (ClockInst* clockInstObj : cluster.second) {
          fixTreeLevels(
              cgcLevelMap_[clockInstObj->getDbInputPin()->getInst()].second,
              currLevel + bufLevels + 1,
              maxTreeDepth);
        }
      }
    }
  });
}
}  // namespace cts
