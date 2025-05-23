// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2019-2025, The OpenROAD Authors

#include "odb/dbViaParams.h"

#include "odb/db.h"

namespace odb {

////////////////////////////////////////////////////////////////////
//
// _dbViaParams - Methods
//
////////////////////////////////////////////////////////////////////

bool _dbViaParams::operator==(const _dbViaParams& rhs) const
{
  if (_x_cut_size != rhs._x_cut_size) {
    return false;
  }

  if (_y_cut_size != rhs._y_cut_size) {
    return false;
  }

  if (_x_cut_spacing != rhs._x_cut_spacing) {
    return false;
  }

  if (_y_cut_spacing != rhs._y_cut_spacing) {
    return false;
  }

  if (_x_top_enclosure != rhs._x_top_enclosure) {
    return false;
  }

  if (_y_top_enclosure != rhs._y_top_enclosure) {
    return false;
  }

  if (_x_bot_enclosure != rhs._x_bot_enclosure) {
    return false;
  }

  if (_y_bot_enclosure != rhs._y_bot_enclosure) {
    return false;
  }

  if (_num_cut_rows != rhs._num_cut_rows) {
    return false;
  }

  if (_num_cut_cols != rhs._num_cut_cols) {
    return false;
  }

  if (_x_origin != rhs._x_origin) {
    return false;
  }

  if (_y_origin != rhs._y_origin) {
    return false;
  }

  if (_x_top_offset != rhs._x_top_offset) {
    return false;
  }

  if (_y_top_offset != rhs._y_top_offset) {
    return false;
  }

  if (_x_bot_offset != rhs._x_bot_offset) {
    return false;
  }

  if (_y_bot_offset != rhs._y_bot_offset) {
    return false;
  }

  if (_top_layer != rhs._top_layer) {
    return false;
  }

  if (_cut_layer != rhs._cut_layer) {
    return false;
  }

  if (_bot_layer != rhs._bot_layer) {
    return false;
  }

  return true;
}

_dbViaParams::_dbViaParams(const _dbViaParams& v)
    : _x_cut_size(v._x_cut_size),
      _y_cut_size(v._y_cut_size),
      _x_cut_spacing(v._x_cut_spacing),
      _y_cut_spacing(v._y_cut_spacing),
      _x_top_enclosure(v._x_top_enclosure),
      _y_top_enclosure(v._y_top_enclosure),
      _x_bot_enclosure(v._x_bot_enclosure),
      _y_bot_enclosure(v._y_bot_enclosure),
      _num_cut_rows(v._num_cut_rows),
      _num_cut_cols(v._num_cut_cols),
      _x_origin(v._x_origin),
      _y_origin(v._y_origin),
      _x_top_offset(v._x_top_offset),
      _y_top_offset(v._y_top_offset),
      _x_bot_offset(v._x_bot_offset),
      _y_bot_offset(v._y_bot_offset),
      _top_layer(v._top_layer),
      _cut_layer(v._cut_layer),
      _bot_layer(v._bot_layer)
{
}

_dbViaParams::_dbViaParams()
{
  _x_cut_size = 0;
  _y_cut_size = 0;
  _x_cut_spacing = 0;
  _y_cut_spacing = 0;
  _x_top_enclosure = 0;
  _y_top_enclosure = 0;
  _x_bot_enclosure = 0;
  _y_bot_enclosure = 0;
  _num_cut_rows = 1;
  _num_cut_cols = 1;
  _x_origin = 0;
  _y_origin = 0;
  _x_top_offset = 0;
  _y_top_offset = 0;
  _x_bot_offset = 0;
  _y_bot_offset = 0;
}

_dbViaParams::~_dbViaParams()
{
}

dbOStream& operator<<(dbOStream& stream, const _dbViaParams& v)
{
  stream << v._x_cut_size;
  stream << v._y_cut_size;
  stream << v._x_cut_spacing;
  stream << v._y_cut_spacing;
  stream << v._x_top_enclosure;
  stream << v._y_top_enclosure;
  stream << v._x_bot_enclosure;
  stream << v._y_bot_enclosure;
  stream << v._num_cut_rows;
  stream << v._num_cut_cols;
  stream << v._x_origin;
  stream << v._y_origin;
  stream << v._x_top_offset;
  stream << v._y_top_offset;
  stream << v._x_bot_offset;
  stream << v._y_bot_offset;
  stream << v._top_layer;
  stream << v._cut_layer;
  stream << v._bot_layer;
  return stream;
}

dbIStream& operator>>(dbIStream& stream, _dbViaParams& v)
{
  stream >> v._x_cut_size;
  stream >> v._y_cut_size;
  stream >> v._x_cut_spacing;
  stream >> v._y_cut_spacing;
  stream >> v._x_top_enclosure;
  stream >> v._y_top_enclosure;
  stream >> v._x_bot_enclosure;
  stream >> v._y_bot_enclosure;
  stream >> v._num_cut_rows;
  stream >> v._num_cut_cols;
  stream >> v._x_origin;
  stream >> v._y_origin;
  stream >> v._x_top_offset;
  stream >> v._y_top_offset;
  stream >> v._x_bot_offset;
  stream >> v._y_bot_offset;
  stream >> v._top_layer;
  stream >> v._cut_layer;
  stream >> v._bot_layer;
  return stream;
}

////////////////////////////////////////////////////////////////////
//
// dbViaParams - Methods
//
////////////////////////////////////////////////////////////////////

dbViaParams::dbViaParams() : _tech(nullptr)
{
}

dbViaParams::dbViaParams(const dbViaParams& p) : _dbViaParams(p), _tech(p._tech)
{
}

dbViaParams::dbViaParams(const _dbViaParams& p)
    : _dbViaParams(p), _tech(nullptr)
{
}

dbViaParams::~dbViaParams()
{
}

int dbViaParams::getXCutSize() const
{
  return _x_cut_size;
}

int dbViaParams::getYCutSize() const
{
  return _y_cut_size;
}

int dbViaParams::getXCutSpacing() const
{
  return _x_cut_spacing;
}

int dbViaParams::getYCutSpacing() const
{
  return _y_cut_spacing;
}

int dbViaParams::getXTopEnclosure() const
{
  return _x_top_enclosure;
}

int dbViaParams::getYTopEnclosure() const
{
  return _y_top_enclosure;
}

int dbViaParams::getXBottomEnclosure() const
{
  return _x_bot_enclosure;
}

int dbViaParams::getYBottomEnclosure() const
{
  return _y_bot_enclosure;
}

int dbViaParams::getNumCutRows() const
{
  return _num_cut_rows;
}

int dbViaParams::getNumCutCols() const
{
  return _num_cut_cols;
}

int dbViaParams::getXOrigin() const
{
  return _x_origin;
}

int dbViaParams::getYOrigin() const
{
  return _y_origin;
}

int dbViaParams::getXTopOffset() const
{
  return _x_top_offset;
}

int dbViaParams::getYTopOffset() const
{
  return _y_top_offset;
}

int dbViaParams::getXBottomOffset() const
{
  return _x_bot_offset;
}

int dbViaParams::getYBottomOffset() const
{
  return _y_bot_offset;
}

dbTechLayer* dbViaParams::getTopLayer() const
{
  if (_tech == nullptr) {
    return nullptr;
  }

  return dbTechLayer::getTechLayer(_tech, _top_layer);
}

dbTechLayer* dbViaParams::getCutLayer() const
{
  if (_tech == nullptr) {
    return nullptr;
  }

  return dbTechLayer::getTechLayer(_tech, _cut_layer);
}

dbTechLayer* dbViaParams::getBottomLayer() const
{
  if (_tech == nullptr) {
    return nullptr;
  }

  return dbTechLayer::getTechLayer(_tech, _bot_layer);
}

void dbViaParams::setXCutSize(int value)
{
  _x_cut_size = value;
}

void dbViaParams::setYCutSize(int value)
{
  _y_cut_size = value;
}

void dbViaParams::setXCutSpacing(int value)
{
  _x_cut_spacing = value;
}

void dbViaParams::setYCutSpacing(int value)
{
  _y_cut_spacing = value;
}

void dbViaParams::setXTopEnclosure(int value)
{
  _x_top_enclosure = value;
}

void dbViaParams::setYTopEnclosure(int value)
{
  _y_top_enclosure = value;
}

void dbViaParams::setXBottomEnclosure(int value)
{
  _x_bot_enclosure = value;
}

void dbViaParams::setYBottomEnclosure(int value)
{
  _y_bot_enclosure = value;
}

void dbViaParams::setNumCutRows(int value)
{
  _num_cut_rows = value;
}

void dbViaParams::setNumCutCols(int value)
{
  _num_cut_cols = value;
}

void dbViaParams::setXOrigin(int value)
{
  _x_origin = value;
}

void dbViaParams::setYOrigin(int value)
{
  _y_origin = value;
}

void dbViaParams::setXTopOffset(int value)
{
  _x_top_offset = value;
}

void dbViaParams::setYTopOffset(int value)
{
  _y_top_offset = value;
}

void dbViaParams::setXBottomOffset(int value)
{
  _x_bot_offset = value;
}

void dbViaParams::setYBottomOffset(int value)
{
  _y_bot_offset = value;
}

void dbViaParams::setTopLayer(dbTechLayer* layer)
{
  if (_tech == nullptr) {
    _tech = layer->getTech();
  }

  assert(_tech == layer->getTech());
  _top_layer = layer->getId();
}

void dbViaParams::setCutLayer(dbTechLayer* layer)
{
  if (_tech == nullptr) {
    _tech = layer->getTech();
  }

  assert(_tech == layer->getTech());
  _cut_layer = layer->getId();
}

void dbViaParams::setBottomLayer(dbTechLayer* layer)
{
  if (_tech == nullptr) {
    _tech = layer->getTech();
  }

  assert(_tech == layer->getTech());
  _bot_layer = layer->getId();
}

}  // namespace odb
