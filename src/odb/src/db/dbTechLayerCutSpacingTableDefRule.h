///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (c) 2020, The Regents of the University of California
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// Generator Code Begin Header
#pragma once

#include <map>
#include <string>

#include "dbCore.h"
#include "dbVector.h"
#include "odb/odb.h"

namespace odb {
class dbIStream;
class dbOStream;
class _dbDatabase;
class _dbTechLayer;
// User Code Begin Classes
class _dbTechLayerCutClassRule;
// User Code End Classes

struct dbTechLayerCutSpacingTableDefRuleFlags
{
  bool default_valid_ : 1;
  bool same_mask_ : 1;
  bool same_net_ : 1;
  bool same_metal_ : 1;
  bool same_via_ : 1;
  bool layer_valid_ : 1;
  bool no_stack_ : 1;
  bool non_zero_enclosure_ : 1;
  bool prl_for_aligned_cut_ : 1;
  bool center_to_center_valid_ : 1;
  bool center_and_edge_valid_ : 1;
  bool no_prl_ : 1;
  bool prl_valid_ : 1;
  bool max_x_y_ : 1;
  bool end_extension_valid_ : 1;
  bool side_extension_valid_ : 1;
  bool exact_aligned_spacing_valid_ : 1;
  bool horizontal_ : 1;
  bool prl_horizontal_ : 1;
  bool vertical_ : 1;
  bool prl_vertical_ : 1;
  bool non_opposite_enclosure_spacing_valid_ : 1;
  bool opposite_enclosure_resize_spacing_valid_ : 1;
  uint spare_bits_ : 9;
};

class _dbTechLayerCutSpacingTableDefRule : public _dbObject
{
 public:
  _dbTechLayerCutSpacingTableDefRule(_dbDatabase*);

  bool operator==(const _dbTechLayerCutSpacingTableDefRule& rhs) const;
  bool operator!=(const _dbTechLayerCutSpacingTableDefRule& rhs) const
  {
    return !operator==(rhs);
  }
  bool operator<(const _dbTechLayerCutSpacingTableDefRule& rhs) const;
  void collectMemInfo(MemInfo& info);

  dbTechLayerCutSpacingTableDefRuleFlags flags_;
  int default_;
  dbId<_dbTechLayer> second_layer_;
  dbVector<std::pair<std::string, std::string>> prl_for_aligned_cut_tbl_;
  dbVector<std::pair<std::string, std::string>> center_to_center_tbl_;
  dbVector<std::pair<std::string, std::string>> center_and_edge_tbl_;
  int prl_;
  dbVector<std::tuple<std::string, std::string, int>> prl_tbl_;
  int extension_;
  dbVector<std::pair<std::string, int>> end_extension_tbl_;
  dbVector<std::pair<std::string, int>> side_extension_tbl_;
  dbVector<std::pair<std::string, int>> exact_aligned_spacing_tbl_;
  dbVector<std::pair<std::string, int>> non_opp_enc_spacing_tbl_;
  dbVector<std::tuple<std::string, int, int, int>> opp_enc_spacing_tbl_;
  dbVector<dbVector<std::pair<int, int>>> spacing_tbl_;
  std::map<std::string, uint> row_map_;
  std::map<std::string, uint> col_map_;
};
dbIStream& operator>>(dbIStream& stream,
                      _dbTechLayerCutSpacingTableDefRule& obj);
dbOStream& operator<<(dbOStream& stream,
                      const _dbTechLayerCutSpacingTableDefRule& obj);
}  // namespace odb
   // Generator Code End Header
