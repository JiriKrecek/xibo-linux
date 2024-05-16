#pragma once

#include <string>
#include <vector>

#include "common/dt/DateTime.hpp"

using LayoutDependants = std::vector<std::string>;
using LayoutId = int;

struct DefaultScheduledLayout {
  LayoutId id;
  LayoutDependants dependants;
};

struct ScheduledLayout {
  int scheduleId;
  LayoutId id;
  int priority;
  DateTime startDT;
  DateTime endDT;
  LayoutDependants dependants;
};

using LayoutList = std::vector<ScheduledLayout>;

const LayoutId EmptyLayoutId = 0;
const int DefaultScheduleId = 0;

bool operator==(const DefaultScheduledLayout &first,
                const DefaultScheduledLayout &second);
bool operator!=(const DefaultScheduledLayout &first,
                const DefaultScheduledLayout &second);

bool operator==(const ScheduledLayout &first, const ScheduledLayout &second);
bool operator!=(const ScheduledLayout &first, const ScheduledLayout &second);
