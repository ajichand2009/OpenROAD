// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2020-2025, The OpenROAD Authors

// Generator Code Begin Cpp
#include "dbTechLayerCutSpacingTableDefRule.h"

#include <cstdint>
#include <cstring>
#include <map>
#include <string>

#include "dbDatabase.h"
#include "dbTable.h"
#include "dbTable.hpp"
#include "dbTechLayer.h"
#include "odb/db.h"
// User Code Begin Includes
#include "dbTech.h"
#include "dbTechLayerCutClassRule.h"
// User Code End Includes
namespace odb {
template class dbTable<_dbTechLayerCutSpacingTableDefRule>;

bool _dbTechLayerCutSpacingTableDefRule::operator==(
    const _dbTechLayerCutSpacingTableDefRule& rhs) const
{
  if (flags_.default_valid_ != rhs.flags_.default_valid_) {
    return false;
  }
  if (flags_.same_mask_ != rhs.flags_.same_mask_) {
    return false;
  }
  if (flags_.same_net_ != rhs.flags_.same_net_) {
    return false;
  }
  if (flags_.same_metal_ != rhs.flags_.same_metal_) {
    return false;
  }
  if (flags_.same_via_ != rhs.flags_.same_via_) {
    return false;
  }
  if (flags_.layer_valid_ != rhs.flags_.layer_valid_) {
    return false;
  }
  if (flags_.no_stack_ != rhs.flags_.no_stack_) {
    return false;
  }
  if (flags_.non_zero_enclosure_ != rhs.flags_.non_zero_enclosure_) {
    return false;
  }
  if (flags_.prl_for_aligned_cut_ != rhs.flags_.prl_for_aligned_cut_) {
    return false;
  }
  if (flags_.center_to_center_valid_ != rhs.flags_.center_to_center_valid_) {
    return false;
  }
  if (flags_.center_and_edge_valid_ != rhs.flags_.center_and_edge_valid_) {
    return false;
  }
  if (flags_.no_prl_ != rhs.flags_.no_prl_) {
    return false;
  }
  if (flags_.prl_valid_ != rhs.flags_.prl_valid_) {
    return false;
  }
  if (flags_.max_x_y_ != rhs.flags_.max_x_y_) {
    return false;
  }
  if (flags_.end_extension_valid_ != rhs.flags_.end_extension_valid_) {
    return false;
  }
  if (flags_.side_extension_valid_ != rhs.flags_.side_extension_valid_) {
    return false;
  }
  if (flags_.exact_aligned_spacing_valid_
      != rhs.flags_.exact_aligned_spacing_valid_) {
    return false;
  }
  if (flags_.horizontal_ != rhs.flags_.horizontal_) {
    return false;
  }
  if (flags_.prl_horizontal_ != rhs.flags_.prl_horizontal_) {
    return false;
  }
  if (flags_.vertical_ != rhs.flags_.vertical_) {
    return false;
  }
  if (flags_.prl_vertical_ != rhs.flags_.prl_vertical_) {
    return false;
  }
  if (flags_.non_opposite_enclosure_spacing_valid_
      != rhs.flags_.non_opposite_enclosure_spacing_valid_) {
    return false;
  }
  if (flags_.opposite_enclosure_resize_spacing_valid_
      != rhs.flags_.opposite_enclosure_resize_spacing_valid_) {
    return false;
  }
  if (default_ != rhs.default_) {
    return false;
  }
  if (second_layer_ != rhs.second_layer_) {
    return false;
  }
  if (prl_ != rhs.prl_) {
    return false;
  }
  if (extension_ != rhs.extension_) {
    return false;
  }

  return true;
}

bool _dbTechLayerCutSpacingTableDefRule::operator<(
    const _dbTechLayerCutSpacingTableDefRule& rhs) const
{
  return true;
}

_dbTechLayerCutSpacingTableDefRule::_dbTechLayerCutSpacingTableDefRule(
    _dbDatabase* db)
{
  flags_ = {};
  default_ = 0;
  prl_ = 0;
  extension_ = 0;
}

dbIStream& operator>>(dbIStream& stream,
                      _dbTechLayerCutSpacingTableDefRule& obj)
{
  uint32_t flags_bit_field;
  stream >> flags_bit_field;
  static_assert(sizeof(obj.flags_) == sizeof(flags_bit_field));
  std::memcpy(&obj.flags_, &flags_bit_field, sizeof(flags_bit_field));
  stream >> obj.default_;
  stream >> obj.second_layer_;
  stream >> obj.prl_for_aligned_cut_tbl_;
  stream >> obj.center_to_center_tbl_;
  stream >> obj.center_and_edge_tbl_;
  stream >> obj.prl_;
  stream >> obj.prl_tbl_;
  stream >> obj.extension_;
  stream >> obj.end_extension_tbl_;
  stream >> obj.side_extension_tbl_;
  stream >> obj.exact_aligned_spacing_tbl_;
  stream >> obj.non_opp_enc_spacing_tbl_;
  stream >> obj.opp_enc_spacing_tbl_;
  stream >> obj.spacing_tbl_;
  stream >> obj.row_map_;
  stream >> obj.col_map_;
  return stream;
}

dbOStream& operator<<(dbOStream& stream,
                      const _dbTechLayerCutSpacingTableDefRule& obj)
{
  uint32_t flags_bit_field;
  static_assert(sizeof(obj.flags_) == sizeof(flags_bit_field));
  std::memcpy(&flags_bit_field, &obj.flags_, sizeof(obj.flags_));
  stream << flags_bit_field;
  stream << obj.default_;
  stream << obj.second_layer_;
  stream << obj.prl_for_aligned_cut_tbl_;
  stream << obj.center_to_center_tbl_;
  stream << obj.center_and_edge_tbl_;
  stream << obj.prl_;
  stream << obj.prl_tbl_;
  stream << obj.extension_;
  stream << obj.end_extension_tbl_;
  stream << obj.side_extension_tbl_;
  stream << obj.exact_aligned_spacing_tbl_;
  stream << obj.non_opp_enc_spacing_tbl_;
  stream << obj.opp_enc_spacing_tbl_;
  stream << obj.spacing_tbl_;
  stream << obj.row_map_;
  stream << obj.col_map_;
  return stream;
}

void _dbTechLayerCutSpacingTableDefRule::collectMemInfo(MemInfo& info)
{
  info.cnt++;
  info.size += sizeof(*this);

  // User Code Begin collectMemInfo
  info.children_["prl_for_aligned_cut_tbl_"].add(prl_for_aligned_cut_tbl_);
  info.children_["center_to_center_tbl_"].add(center_to_center_tbl_);
  info.children_["center_and_edge_tbl_"].add(center_and_edge_tbl_);
  info.children_["prl_tbl_"].add(prl_tbl_);
  info.children_["end_extension_tbl_"].add(end_extension_tbl_);
  info.children_["side_extension_tbl_"].add(side_extension_tbl_);
  info.children_["exact_aligned_spacing_tbl_"].add(exact_aligned_spacing_tbl_);
  info.children_["non_opp_enc_spacing_tbl_"].add(non_opp_enc_spacing_tbl_);
  info.children_["opp_enc_spacing_tbl_"].add(opp_enc_spacing_tbl_);
  info.children_["spacing_tbl_"].add(spacing_tbl_);
  info.children_["row_map_"].add(row_map_);
  info.children_["col_map_"].add(col_map_);
  // User Code End collectMemInfo
}

////////////////////////////////////////////////////////////////////
//
// dbTechLayerCutSpacingTableDefRule - Methods
//
////////////////////////////////////////////////////////////////////

void dbTechLayerCutSpacingTableDefRule::setDefault(int spacing)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->default_ = spacing;
}

int dbTechLayerCutSpacingTableDefRule::getDefault() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  return obj->default_;
}

void dbTechLayerCutSpacingTableDefRule::setSecondLayer(
    dbTechLayer* second_layer)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->second_layer_ = second_layer->getImpl()->getOID();
}

void dbTechLayerCutSpacingTableDefRule::setPrl(int prl)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->prl_ = prl;
}

int dbTechLayerCutSpacingTableDefRule::getPrl() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  return obj->prl_;
}

void dbTechLayerCutSpacingTableDefRule::setExtension(int extension)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->extension_ = extension;
}

int dbTechLayerCutSpacingTableDefRule::getExtension() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  return obj->extension_;
}

void dbTechLayerCutSpacingTableDefRule::setDefaultValid(bool default_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.default_valid_ = default_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isDefaultValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.default_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setSameMask(bool same_mask)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.same_mask_ = same_mask;
}

bool dbTechLayerCutSpacingTableDefRule::isSameMask() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.same_mask_;
}

void dbTechLayerCutSpacingTableDefRule::setSameNet(bool same_net)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.same_net_ = same_net;
}

bool dbTechLayerCutSpacingTableDefRule::isSameNet() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.same_net_;
}

void dbTechLayerCutSpacingTableDefRule::setSameMetal(bool same_metal)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.same_metal_ = same_metal;
}

bool dbTechLayerCutSpacingTableDefRule::isSameMetal() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.same_metal_;
}

void dbTechLayerCutSpacingTableDefRule::setSameVia(bool same_via)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.same_via_ = same_via;
}

bool dbTechLayerCutSpacingTableDefRule::isSameVia() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.same_via_;
}

void dbTechLayerCutSpacingTableDefRule::setLayerValid(bool layer_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.layer_valid_ = layer_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isLayerValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.layer_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setNoStack(bool no_stack)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.no_stack_ = no_stack;
}

bool dbTechLayerCutSpacingTableDefRule::isNoStack() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.no_stack_;
}

void dbTechLayerCutSpacingTableDefRule::setNonZeroEnclosure(
    bool non_zero_enclosure)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.non_zero_enclosure_ = non_zero_enclosure;
}

bool dbTechLayerCutSpacingTableDefRule::isNonZeroEnclosure() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.non_zero_enclosure_;
}

void dbTechLayerCutSpacingTableDefRule::setPrlForAlignedCut(
    bool prl_for_aligned_cut)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.prl_for_aligned_cut_ = prl_for_aligned_cut;
}

bool dbTechLayerCutSpacingTableDefRule::isPrlForAlignedCut() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.prl_for_aligned_cut_;
}

void dbTechLayerCutSpacingTableDefRule::setCenterToCenterValid(
    bool center_to_center_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.center_to_center_valid_ = center_to_center_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isCenterToCenterValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.center_to_center_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setCenterAndEdgeValid(
    bool center_and_edge_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.center_and_edge_valid_ = center_and_edge_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isCenterAndEdgeValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.center_and_edge_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setNoPrl(bool no_prl)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.no_prl_ = no_prl;
}

bool dbTechLayerCutSpacingTableDefRule::isNoPrl() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.no_prl_;
}

void dbTechLayerCutSpacingTableDefRule::setPrlValid(bool prl_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.prl_valid_ = prl_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isPrlValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.prl_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setMaxXY(bool max_x_y)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.max_x_y_ = max_x_y;
}

bool dbTechLayerCutSpacingTableDefRule::isMaxXY() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.max_x_y_;
}

void dbTechLayerCutSpacingTableDefRule::setEndExtensionValid(
    bool end_extension_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.end_extension_valid_ = end_extension_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isEndExtensionValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.end_extension_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setSideExtensionValid(
    bool side_extension_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.side_extension_valid_ = side_extension_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isSideExtensionValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.side_extension_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setExactAlignedSpacingValid(
    bool exact_aligned_spacing_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.exact_aligned_spacing_valid_ = exact_aligned_spacing_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isExactAlignedSpacingValid() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.exact_aligned_spacing_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setHorizontal(bool horizontal)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.horizontal_ = horizontal;
}

bool dbTechLayerCutSpacingTableDefRule::isHorizontal() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.horizontal_;
}

void dbTechLayerCutSpacingTableDefRule::setPrlHorizontal(bool prl_horizontal)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.prl_horizontal_ = prl_horizontal;
}

bool dbTechLayerCutSpacingTableDefRule::isPrlHorizontal() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.prl_horizontal_;
}

void dbTechLayerCutSpacingTableDefRule::setVertical(bool vertical)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.vertical_ = vertical;
}

bool dbTechLayerCutSpacingTableDefRule::isVertical() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.vertical_;
}

void dbTechLayerCutSpacingTableDefRule::setPrlVertical(bool prl_vertical)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.prl_vertical_ = prl_vertical;
}

bool dbTechLayerCutSpacingTableDefRule::isPrlVertical() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.prl_vertical_;
}

void dbTechLayerCutSpacingTableDefRule::setNonOppositeEnclosureSpacingValid(
    bool non_opposite_enclosure_spacing_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.non_opposite_enclosure_spacing_valid_
      = non_opposite_enclosure_spacing_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isNonOppositeEnclosureSpacingValid()
    const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.non_opposite_enclosure_spacing_valid_;
}

void dbTechLayerCutSpacingTableDefRule::setOppositeEnclosureResizeSpacingValid(
    bool opposite_enclosure_resize_spacing_valid)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  obj->flags_.opposite_enclosure_resize_spacing_valid_
      = opposite_enclosure_resize_spacing_valid;
}

bool dbTechLayerCutSpacingTableDefRule::isOppositeEnclosureResizeSpacingValid()
    const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;

  return obj->flags_.opposite_enclosure_resize_spacing_valid_;
}

// User Code Begin dbTechLayerCutSpacingTableDefRulePublicMethods
void dbTechLayerCutSpacingTableDefRule::addPrlForAlignedCutEntry(
    std::string from,
    std::string to)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->prl_for_aligned_cut_tbl_.push_back({from, to});
}

void dbTechLayerCutSpacingTableDefRule::addCenterToCenterEntry(std::string from,
                                                               std::string to)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->center_to_center_tbl_.push_back({from, to});
}

void dbTechLayerCutSpacingTableDefRule::addCenterAndEdgeEntry(std::string from,
                                                              std::string to)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->center_and_edge_tbl_.push_back({from, to});
}

void dbTechLayerCutSpacingTableDefRule::addPrlEntry(std::string from,
                                                    std::string to,
                                                    int ccPrl)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->prl_tbl_.push_back({from, to, ccPrl});
}

void dbTechLayerCutSpacingTableDefRule::addEndExtensionEntry(std::string cls,
                                                             int ext)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->end_extension_tbl_.push_back({cls, ext});
}

void dbTechLayerCutSpacingTableDefRule::addSideExtensionEntry(std::string cls,
                                                              int ext)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->side_extension_tbl_.push_back({cls, ext});
}

void dbTechLayerCutSpacingTableDefRule::addExactElignedEntry(std::string cls,
                                                             int spacing)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->exact_aligned_spacing_tbl_.push_back({cls, spacing});
}

void dbTechLayerCutSpacingTableDefRule::addNonOppEncSpacingEntry(
    std::string cls,
    int spacing)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->non_opp_enc_spacing_tbl_.push_back({cls, spacing});
}

void dbTechLayerCutSpacingTableDefRule::addOppEncSpacingEntry(std::string cls,
                                                              int rsz1,
                                                              int rsz2,
                                                              int spacing)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->opp_enc_spacing_tbl_.push_back({cls, rsz1, rsz2, spacing});
}

dbTechLayer* dbTechLayerCutSpacingTableDefRule::getSecondLayer() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  if (obj->second_layer_ == 0) {
    return nullptr;
  }
  _dbTechLayer* layer = (_dbTechLayer*) obj->getOwner();
  _dbTech* _tech = (_dbTech*) layer->getOwner();
  return (dbTechLayer*) _tech->_layer_tbl->getPtr(obj->second_layer_);
}

void dbTechLayerCutSpacingTableDefRule::setSpacingTable(
    std::vector<std::vector<std::pair<int, int>>> table,
    std::map<std::string, uint> row_map,
    std::map<std::string, uint> col_map)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  obj->row_map_ = row_map;
  obj->col_map_ = col_map;
  for (const auto& spacing : table) {
    dbVector<std::pair<int, int>> tmp;
    tmp = spacing;
    obj->spacing_tbl_.push_back(tmp);
  }
}

void dbTechLayerCutSpacingTableDefRule::getSpacingTable(
    std::vector<std::vector<std::pair<int, int>>>& table,
    std::map<std::string, uint>& row_map,
    std::map<std::string, uint>& col_map)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  row_map = obj->row_map_;
  col_map = obj->col_map_;
  table.clear();
  for (const auto& spacing : obj->spacing_tbl_) {
    table.push_back(spacing);
  }
}

int dbTechLayerCutSpacingTableDefRule::getMaxSpacing(std::string cutClass,
                                                     bool SIDE) const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  std::string classDir = cutClass;
  if (SIDE) {
    classDir += "/SIDE";
  } else {
    classDir += "/END";
  }

  if (obj->col_map_.find(classDir) == obj->col_map_.end()) {
    return obj->default_;
  }
  auto colIdx = obj->col_map_[classDir];
  auto spc = 0;
  for (const auto& row : obj->spacing_tbl_) {
    spc = std::max(spc, std::max(row[colIdx].first, row[colIdx].second));
  }
  return spc;
}

int dbTechLayerCutSpacingTableDefRule::getMaxSpacing(
    std::string cutClass1,
    std::string cutClass2,
    LOOKUP_STRATEGY strategy) const
{
  auto spc1 = getSpacing(cutClass1, true, cutClass2, true, strategy);
  auto spc2 = getSpacing(cutClass1, true, cutClass2, false, strategy);
  auto spc3 = getSpacing(cutClass1, false, cutClass2, true, strategy);
  auto spc4 = getSpacing(cutClass1, false, cutClass2, false, strategy);

  return std::max(std::max(spc1, spc2), std::max(spc3, spc4));
}

bool dbTechLayerCutSpacingTableDefRule::isCenterToCenter(std::string cutClass1,
                                                         std::string cutClass2)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  for (auto& [class1, class2] : obj->center_to_center_tbl_) {
    if ((class1 == cutClass1 || class1 == "ALL")
        && (class2 == cutClass2 || class2 == "ALL")) {
      return true;
    }
    if ((class1 == cutClass2 || class1 == "ALL")
        && (class2 == cutClass1 || class2 == "ALL")) {
      return true;
    }
  }
  return false;
}

int dbTechLayerCutSpacingTableDefRule::getExactAlignedSpacing(
    std::string cutClass) const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  for (auto& [cls, spc] : obj->exact_aligned_spacing_tbl_) {
    if (cls == cutClass) {
      return spc;
    }
  }
  return -1;
}

bool dbTechLayerCutSpacingTableDefRule::isPrlForAlignedCutClasses(
    std::string cutClass1,
    std::string cutClass2)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  for (auto& [class1, class2] : obj->prl_for_aligned_cut_tbl_) {
    if ((class1 == cutClass1 || class1 == "ALL")
        && (class2 == cutClass2 || class2 == "ALL")) {
      return true;
    }
  }
  return false;
}

int dbTechLayerCutSpacingTableDefRule::getPrlEntry(const std::string& cutClass1,
                                                   const std::string& cutClass2)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  for (const auto& [class1, class2, prl] : obj->prl_tbl_) {
    if ((class1 == cutClass1 || class1 == "ALL")
        && (class2 == cutClass2 || class2 == "ALL")) {
      return prl;
    }
    if ((class1 == cutClass2 || class1 == "ALL")
        && (class2 == cutClass1 || class2 == "ALL")) {
      return prl;
    }
  }
  return obj->prl_;
}

bool dbTechLayerCutSpacingTableDefRule::isCenterAndEdge(std::string cutClass1,
                                                        std::string cutClass2)
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  for (auto& [class1, class2] : obj->center_and_edge_tbl_) {
    if ((class1 == cutClass1 || class1 == "ALL")
        && (class2 == cutClass2 || class2 == "ALL")) {
      return true;
    }
    if ((class1 == cutClass2 || class1 == "ALL")
        && (class2 == cutClass1 || class2 == "ALL")) {
      return true;
    }
  }
  return false;
}

int dbTechLayerCutSpacingTableDefRule::getSpacing(
    std::string c1,
    bool SIDE1,
    std::string c2,
    bool SIDE2,
    LOOKUP_STRATEGY strategy) const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  if (SIDE1) {
    c1 += "/SIDE";
  } else {
    c1 += "/END";
  }

  if (SIDE2) {
    c2 += "/SIDE";
  } else {
    c2 += "/END";
  }
  std::pair<int, int> res;
  if (obj->row_map_.find(c2) != obj->row_map_.end()
      && obj->col_map_.find(c1) != obj->col_map_.end()) {
    res = obj->spacing_tbl_[obj->row_map_[c2]][obj->col_map_[c1]];
  } else {
    res = {obj->default_, obj->default_};
  }
  switch (strategy) {
    case FIRST:
      return res.first;
    case SECOND:
      return res.second;
    case MAX:
      return std::max(res.first, res.second);
    case MIN:
      return std::min(res.first, res.second);
    default:
      return 0;
  }
}

dbTechLayer* dbTechLayerCutSpacingTableDefRule::getTechLayer() const
{
  _dbTechLayerCutSpacingTableDefRule* obj
      = (_dbTechLayerCutSpacingTableDefRule*) this;
  return (odb::dbTechLayer*) obj->getOwner();
}

dbTechLayerCutSpacingTableDefRule* dbTechLayerCutSpacingTableDefRule::create(
    dbTechLayer* parent)
{
  _dbTechLayer* _parent = (_dbTechLayer*) parent;
  _dbTechLayerCutSpacingTableDefRule* newrule
      = _parent->cut_spacing_table_def_tbl_->create();
  return ((dbTechLayerCutSpacingTableDefRule*) newrule);
}

dbTechLayerCutSpacingTableDefRule*
dbTechLayerCutSpacingTableDefRule::getTechLayerCutSpacingTableDefSubRule(
    dbTechLayer* parent,
    uint dbid)
{
  _dbTechLayer* _parent = (_dbTechLayer*) parent;
  return (dbTechLayerCutSpacingTableDefRule*)
      _parent->cut_spacing_table_def_tbl_->getPtr(dbid);
}
void dbTechLayerCutSpacingTableDefRule::destroy(
    dbTechLayerCutSpacingTableDefRule* rule)
{
  _dbTechLayer* _parent = (_dbTechLayer*) rule->getImpl()->getOwner();
  dbProperty::destroyProperties(rule);
  _parent->cut_spacing_table_def_tbl_->destroy(
      (_dbTechLayerCutSpacingTableDefRule*) rule);
}

// User Code End dbTechLayerCutSpacingTableDefRulePublicMethods
}  // namespace odb
// Generator Code End Cpp
