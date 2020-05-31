#ifndef GO_BLINK_BUTTON_H
#define GO_BLINK_BUTTON_H

#include "s_timer.h"
#include "go_game_object.h"

class BlinkButton:
        public GameObject
{
public:
    BlinkButton();
    void setTime(int ms);
    inline void setBlinkStatus(bool status){_status=status;}
    inline bool blinkStatus(){return _status;}
private:
Timer   _timer;
std::atomic_bool _status;
};

#endif // GO_BLINK_BUTTON_H
