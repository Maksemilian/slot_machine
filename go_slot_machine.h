#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "go_wheel.h"

class BlinkButton;

class SlotMachine : public GameObject
{
    static const int MIN_WHEEL_SPEED = 50;
    static const int MAX_WHEEL_SPEED = 200;
    static const int TIME_BLINK_BUTTON = 400;
  public:
    SlotMachine(int countWheel, int countTokensInWheel);

    void start();
    void stop();
    void onPressEvent(int x, int y)override;

    inline int countWheel()
    {
        return  static_cast<int>(_wheels.size());
    }
    inline std::vector<Wheel>& wheels()
    {
        return _wheels;
    }
    inline BlinkButton& startButton()
    {
        return  *_startButton;
    }
  private:
    void genearateRandomVirtualWheelValue();
  private:
    std::vector<Wheel> _wheels;
    BlinkButton* _startButton;
};
#endif // SLOTMACHINE_H
