#ifndef DRUM_H
#define DRUM_H

#include "go_token.h"
#include "s_timer.h"
#include "s_time.h"

#include <vector>
#include <map>


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

    void findTokenForStop(int virtualValue);
  private:
    void spin();
  private:
    std::vector<Token>_tokens;
    Timer _wheellSpinTimer;
    Time _time;
    bool _stop;
    int _spinSpeed;
    int _spinTime;

    std::map<int, std::vector<int> >_virtualWheel;
    //TODO do without this memeber
    int _findId = 0;
};



#endif // DRUM_H
