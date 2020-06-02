#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "go_wheel.h"
#include "ro_renderable_object.h"
class BlinkButton;
class SlotMachine
        :public GameObject
{
    static const int MIN_WHEEL_SPEED=50;
    static const int MAX_WHEEL_SPEED=200;
    static const int TIME_STOP_WHEEL = 5;
public:
    SlotMachine(int countWheel,int countTokensInWheel/*,
                RenderableObject<SlotMachine>*renderable=nullptr*/);

//    SlotMachine(const std::vector<Wheel> &wheels  );
    void start();
    void stop();
    int countWheel(){return  _wheels.size();}
    inline std::vector<Wheel> &wheels() {return _wheels;}
    inline BlinkButton &startButton(){return  *_startButton;}
    void onPressEvent(int x,int y)override;
private:
    void waitForStopWheel();
private:
    std::vector<Wheel> _wheels;
    Timer _wheelStopingTimer;
    BlinkButton *_startButton;
};
#endif // SLOTMACHINE_H
