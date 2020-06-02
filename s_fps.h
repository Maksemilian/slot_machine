#ifndef FPS_H
#define FPS_H

#include "s_time.h"



class FPS
{
  public:
    FPS();
    void reset();

    void CalculateFrameRate();
    inline unsigned short fps()
    {
        return _fps;
    }
  private:
    Time _time;
    double _lastTime;
    unsigned short _fps;
    unsigned short _framesPerSecond ;
};

#endif // FPS_H
