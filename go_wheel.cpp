#include "go_wheel.h"
#include "ro_wheel.h"

Wheel::Wheel(const std::vector<Token>& tokens)
    :  GameObject(new WheelRenderable(this)),
       _tokens(tokens),
       _stop(true),
       _spinSpeed(0),
       _spinTime(0) {}

Wheel::Wheel(const Wheel& lhs)
    : GameObject(new WheelRenderable(this))
{
    _tokens = lhs._tokens;
    _stop = lhs._stop;
    _spinSpeed = lhs._spinSpeed;
    _spinTime = lhs._spinTime;
}

Wheel::Wheel(int countTokens)
    :  GameObject(new WheelRenderable(this)),
       _stop(true),
       _spinSpeed(0),
       _spinTime(0)
{
    for(int i = 0; i < countTokens; ++i)
    {
        _tokens.push_back({i});
    }
}

Wheel& Wheel::operator=(const Wheel& lhs)
{
    if(this != &lhs)
    {
        _tokens = lhs._tokens;
        _stop = lhs._stop;
        _spinSpeed = lhs._spinSpeed;
    }
    return *this;
}

void Wheel::startSpin()
{
    _time.reset();
    _stop = false;
    _whellSpinTimer.start();
    _whellSpinTimer.recursiveTimeout(std::chrono::milliseconds(_spinSpeed), [this]
    {
        if(_time.elapsed() < _spinTime)
        {
            this->spin();
        }
        else
        {
            _whellSpinTimer.stop();
        }
    });
}

void Wheel::stopSpin()
{
    _stop = true;
    _whellSpinTimer.stop();
}

void Wheel::spin()
{
    if(!_stop)
    {
        Token last = _tokens.back();

        for (size_t i = _tokens.size() - 1; i > 0; --i)
        {
            _tokens[i] = _tokens[i - 1];
        }

        _tokens[0] = last;
    }
}
