#ifndef DRUM_H
#define DRUM_H

#include "go_token.h"
#include "s_timer.h"
#include <vector>

class Wheel
        :public GameObject
{
public:
    Wheel(int countTones);
    Wheel(const std::vector<Token> &tokens);
    Wheel(const Wheel &lhs);
    Wheel &operator=(const Wheel &lhs);
    void startSpin();
    void stopSpin();

    inline void setSpeed(int speed){_speedSpin=speed;}
    inline int getSpeed(){return  _speedSpin;}


    inline bool isStop(){return  _stop;}
    inline size_t countTokens(){return _tokens.size();}
    inline std::vector<Token>& tokens(){return _tokens;}

private:
    void spin();
private:
    std::vector<Token>_tokens;
    int _speedSpin;
    bool _stop;
    Timer _whellSpinTimer;
};



#endif // DRUM_H
