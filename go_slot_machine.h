#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "go_wheel.h"

class SlotMachine
        :public GameObject
{
    static const int MIN_WHEEL_SPEED=50;
    static const int MAX_WHEEL_SPEED=200;
    static const int TIME_STOP_WHEEL = 5;
public:
    SlotMachine(int countWheel,int countTokensInWheel);
    SlotMachine(const std::vector<Wheel> &wheels);
    void start();
    void stop();
    int countWheel(){return  _wheels.size();}
    inline std::vector<Wheel> &wheels() {return _wheels;}
private:
    void waitForStopWheel();
private:
    std::vector<Wheel> _wheels;
    Timer _wheelStopingTimer;
};
#endif // SLOTMACHINE_H
