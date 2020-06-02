#ifndef DRUM_H
#define DRUM_H

#include "go_token.h"
#include "s_timer.h"
#include "s_time.h"

#include <vector>


class Wheel : public GameObject
{
  public:
    Wheel(int countTokens);
    Wheel(const std::vector<Token>& tokens);
    Wheel(const Wheel& lhs);
    Wheel& operator=(const Wheel& lhs);

    void startSpin();
    void stopSpin();

    inline void setSpinSpeed(int speed)
    {
        _spinSpeed = speed;
    }
    inline int getSpinSpeed()const
    {
        return  _spinSpeed;
    }

    inline void setSpinTime(int sec)
    {
        _spinTime = sec;
    }
    inline int getSpinTime()const
    {
        return  _spinTime;
    }

    inline bool isStop()const
    {
        return  _stop;
    }
    inline int  countTokens()const
    {
        return static_cast<int>(_tokens.size());
    }
    inline std::vector<Token>& tokens()
    {
        return _tokens;
    }

  private:
    void spin();
  private:
    std::vector<Token>_tokens;
    Timer _whellSpinTimer;
    Time _time;
    bool _stop;
    int _spinSpeed;
    int _spinTime;
};



#endif // DRUM_H
