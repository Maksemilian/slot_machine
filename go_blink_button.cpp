#include "go_blink_button.h"
#include "ro_blink_button.h"

BlinkButton::BlinkButton():
    GameObject (new RenderableBlinkButton(this)),
    _status(false) {}

void BlinkButton::setTime(int ms)
{
    _timer.start();
    _timer.recursiveTimeout(std::chrono::milliseconds(ms),
                            [this]()
    {
        this->setBlinkStatus(!_status);
    });
}
