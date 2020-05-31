#ifndef FPS_H
#define FPS_H

#include <chrono>

//TODO перенести реализацию в сpp
class Time
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Time() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

class FPS
{
public:
    FPS():
        _lastTime(0.0),
        _fps(0.0),
        _framesPerSecond(0)
    {

    }
    void reset()
    {
        _lastTime = 0.0;
        _fps = 0;
        _framesPerSecond = 0;
        _time.reset();
    }

    void CalculateFrameRate()
    {
        double currentTime = _time.elapsed();
        ++_framesPerSecond;
        if(currentTime - _lastTime > 1.0f)
        {
//            std::cout<<"TIME:"<<currentTime<<"-"<<_lastTime
//                    <<" FPS:"<<_fps<<std::endl;
            _lastTime = currentTime;
            _fps = _framesPerSecond;
            _framesPerSecond = 0;
        }
    }
    unsigned short fps(){return _fps;}
private:
    Time _time;
    double _lastTime;
    unsigned short _fps;
    unsigned short _framesPerSecond ;
};

#endif // FPS_H
