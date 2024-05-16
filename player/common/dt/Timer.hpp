#pragma once

#include "common/logger/Logging.hpp"
#include <chrono>
#include <cstdint>
#include <glibmm/main.h>       // TODO: remove dependency
#include <sigc++/connection.h> // TODO: remove dependency
#include <type_traits>

class Timer : public sigc::trackable {
public:
  Timer() = default;
  ~Timer();

  template <typename T>
  void startOnce(std::chrono::duration<int64_t, T> duration,
                 std::function<void()> handler) {
    startImpl(duration, handler);
  }

  template <typename T>
  void start(std::chrono::duration<int64_t, T> duration,
             std::function<bool()> handler) {
    startImpl(duration, handler);
  }

  void stop();
  bool active() const;

private:
  template <typename T, typename Handler>
  void startImpl(std::chrono::duration<int64_t, T> duration, Handler handler) {
    stop();

    auto seconds =
        std::chrono::duration_cast<std::chrono::seconds>(duration).count();
    Log::debug("[Timer] startImpl seconds: {}", seconds);
    timerConnection_ = Glib::signal_timeout().connect_seconds(
        [=]() { return onTimeout(handler); }, seconds);
  }

  template <typename Handler> bool onTimeout(Handler handler) {
    if constexpr (std::is_same_v<decltype(handler()), void>) {
      handler();
      return false;
    } else {
      return handler();
    }
  }

private:
  sigc::connection timerConnection_;
};
