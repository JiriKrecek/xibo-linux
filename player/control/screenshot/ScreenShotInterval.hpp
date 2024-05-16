#pragma once

#include "cms/xmds/XmdsRequestSender.hpp"
#include "common/dt/Timer.hpp"
#include "control/screenshot/ScreenShoter.hpp"
#include "control/widgets/Window.hpp"

#include <memory>

class ScreenShotInterval {
public:
  ScreenShotInterval(XmdsRequestSender &sender, Xibo::Window &window);

  void updateInterval(int interval);
  void takeScreenShot();

private:
  void restartTimer();
  void submitScreenShot(const std::string &screenShot);

private:
  XmdsRequestSender &sender_;
  std::unique_ptr<ScreenShoter> screenShoter_;
  int interval_;
  Timer timer_;
};
