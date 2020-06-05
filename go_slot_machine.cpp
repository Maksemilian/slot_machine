#include "go_slot_machine.h"
#include "ro_slot_machine.h"

#include "go_blink_button.h"
#include "ro_blink_button.h"


const int SlotMachine::TIME_BLINK_BUTTON;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

SlotMachine::SlotMachine(int countWheel, int countTokensInWheel)
    : GameObject(new SlotMachineRenderable(this))
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int spinTime = 5;//sec
    for(int i = 0; i < countWheel; ++i)
    {
        _wheels.push_back({countTokensInWheel});
        _wheels[static_cast<size_t>(i)].setSpinTime(spinTime);
        ++spinTime;
    }
    _startButton = new BlinkButton;
    _startButton->setTime(TIME_BLINK_BUTTON);
}

void SlotMachine::start()
{
    genearateRandomVirtualWheelValue();
    for(auto& wheel : _wheels)
    {
        wheel.setSpinSpeed(getRandomNumber(MIN_WHEEL_SPEED, MAX_WHEEL_SPEED));
        wheel.startSpin();
    }
}

void SlotMachine::stop()
{
    for(auto& wheel : _wheels)
    {
        wheel.stopSpin();
    }
}

void SlotMachine::onPressEvent(int x, int y)
{
    GLfloat localY = rect().height() - y;

    Rect blinkButtonRect = _startButton->rect();

    if( (x > blinkButtonRect.topLeft().x() && localY < blinkButtonRect.topLeft().y()) &&
            (x < blinkButtonRect.topLeft().x() + blinkButtonRect.with() &&
             localY > blinkButtonRect.topLeft().y() - blinkButtonRect.height()))
    {
        start();
    }
}

void SlotMachine::genearateRandomVirtualWheelValue()
{
    for(auto& wheel : _wheels)
    {
        int randomNum = getRandomNumber(0, wheel.countTokens() - 1);

        int virtualValue = randomNum % wheel.countTokens();
        wheel.findTokenForStop(virtualValue);
    }
}
