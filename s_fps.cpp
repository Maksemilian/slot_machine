#include "s_fps.h"


FPS:: FPS():
    _lastTime(0.0),
    _fps(0.0),
    _framesPerSecond(0)
{

}
void FPS::reset()
{
    _lastTime = 0.0;
    _fps = 0;
    _framesPerSecond = 0;
    _time.reset();
}

void FPS::CalculateFrameRate()
{
    double currentTime = _time.elapsed();
    ++_framesPerSecond;
    if(currentTime - _lastTime > 1.0)
    {
        _lastTime = currentTime;
        _fps = _framesPerSecond;
        _framesPerSecond = 0;
    }
}
