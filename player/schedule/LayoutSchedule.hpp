#pragma once

#include "common/fs/FilePath.hpp"
#include "schedule/ScheduleItem.hpp"

struct LayoutSchedule {
  static LayoutSchedule fromFile(const FilePath &path);
  static LayoutSchedule fromString(const std::string &string);
  void toFile(const FilePath &path) const;

  DateTime generatedTime;
  LayoutDependants globalDependants;
  LayoutList regularLayouts;
  LayoutList overlayLayouts;
  DefaultScheduledLayout defaultLayout;
};

bool operator==(const LayoutSchedule &first, const LayoutSchedule &second);
bool operator!=(const LayoutSchedule &first, const LayoutSchedule &second);
