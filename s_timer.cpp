#include "s_timer.h"


Timer::Timer(): _quit(true) {}

void Timer::recursiveTimeout(std::chrono::milliseconds delay,
                             std::function<void ()> callback,
                             bool asynchronous )
{
    if (asynchronous)
    {
        std::thread([ = ]()
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            callback();
            if(!_quit)
            {
                recursiveTimeout(std::chrono::milliseconds(delay), callback);
            }
        }).detach();
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        callback();
    }
}

void Timer::singleTimeout(std::chrono::milliseconds delay,
                          std::function<void ()> callback,
                          bool asynchronous )
{
    if (asynchronous)
    {
        std::thread([ = ]()
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            callback();
        }).detach();
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        callback();
    }
}
