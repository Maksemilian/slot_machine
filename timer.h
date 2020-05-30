#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <thread>
#include <iostream>
#include <atomic>

//class CTimer
//{
//public:
//    CTimer():t_beg(clock()){
//    }
//    void reset(){
//        t_beg=clock();
//    }
//    double elapsed(){
//        clock_t search_time = clock() - t_beg; // искомое время
//        return  static_cast<double>(search_time)/CLOCKS_PER_SEC;
//    }
//private:
//  clock_t t_beg;
//};



class Timer
{
public:
    int c;
    Timer():
        c(0)
    {
//        _q=true;
    }
  void recursiveTimeout(std::chrono::milliseconds delay,
           std::function<void ()> callback,
           bool asynchronous = true){
  if (asynchronous) {
    std::thread([=]() {
      std::this_thread::sleep_for(std::chrono::milliseconds(delay));
//      std::cout<<"CALL_BACK"<<std::endl;
       callback();
       if(!_q)
           recursiveTimeout(std::chrono::milliseconds(delay),callback);
    }).detach();
  }
  else
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    callback();
  }
}
  void singleTimeout(std::chrono::milliseconds delay,
           std::function<void ()> callback,
           bool asynchronous = true){
  if (asynchronous)
  {
    std::thread([callback,this,delay]() {
      std::this_thread::sleep_for(std::chrono::milliseconds(delay));
//      std::cout<<"CallBack:"<<++c<<std::endl;
       callback();
    }).detach();
  }
  else
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    callback();
  }
}
  void start(){
    _q=false;
  }
  void stop()
  {
     _q=true;
  }
private:
  bool _q={true};
};
#endif // TIMER_H
