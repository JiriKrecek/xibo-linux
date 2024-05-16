#pragma once

#include "stat/records/LayoutRecord.hpp"
#include "stat/records/MediaRecord.hpp"

namespace Stats {
class RecordVisitor {
public:
  virtual ~RecordVisitor() = default;
  virtual void visit(const LayoutRecord &record) = 0;
  virtual void visit(const MediaRecord &record) = 0;
};
} // namespace Stats
