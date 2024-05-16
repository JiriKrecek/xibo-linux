#pragma once

#include "stat/PlayingTime.hpp"

namespace Stats {
class RecordVisitor;
const int InvalidId = -1;

class Record {
public:
  virtual ~Record() = default;
  virtual void apply(RecordVisitor &visitor) = 0;

  int scheduleId() const;
  int parentId() const;
  int id() const;
  DateTime started() const;
  DateTime finished() const;
  int count() const;

  long duration() const;

protected:
  Record(int scheduleId, int id, const PlayingTime &interval, int count);
  Record(int scheduleId, int parentId, int id, const PlayingTime &interval,
         int count);

private:
  int scheduleId_;
  int parentId_;
  int id_;
  PlayingTime interval_;
  int count_;
};

} // namespace Stats
