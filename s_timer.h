#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <thread>
#include <atomic>

class Timer
{
public:
  Timer();
  void recursiveTimeout(std::chrono::milliseconds delay,
           std::function<void ()> callback,
           bool asynchronous = true);

  void singleTimeout(std::chrono::milliseconds delay,
           std::function<void ()> callback,
           bool asynchronous = true);

  inline void start(){_quit=false; }
  inline void stop(){ _quit=true; }
private:
  std::atomic_bool _quit;
};
#endif // TIMER_H
