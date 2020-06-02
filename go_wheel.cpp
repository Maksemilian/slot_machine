#include "go_wheel.h"
#include "ro_wheel.h"

using namespace std;


Wheel::Wheel(const std::vector<Token> &tokens)
    :  GameObject(new WheelRenderable(this)),
      _tokens(tokens),
      _stop(true)
{

}

Wheel::Wheel(const Wheel &lhs)
    :GameObject(new WheelRenderable(this))
{
    _tokens=lhs._tokens;
    _speedSpin=lhs._speedSpin;
    _stop=lhs._stop;
}

Wheel::Wheel(int countTokens)
    :  GameObject(new WheelRenderable(this)),
      _stop(true)
{

    for(int i=0;i<countTokens;++i){
        _tokens.push_back({i});
    }
}

Wheel &Wheel::operator=(const Wheel &lhs)
{
    if(this!=&lhs){
        _tokens=lhs._tokens;
        _stop=lhs._stop;
        _speedSpin=lhs._speedSpin;
//        _whellSpinTimer=lhs._whellSpinTimer;

    }
    return *this;
}

void Wheel::startSpin(){
    _stop=false;
    _whellSpinTimer.start();
    _whellSpinTimer.recursiveTimeout(std::chrono::milliseconds(_speedSpin),[this]{
        this->spin();
    });
}
void Wheel::stopSpin(){
    _stop=true;
    _whellSpinTimer.stop();
}

void Wheel::spin()
{
    if(!_stop){
//        std::cout<<"_B:"<<counter<<std::endl;
        Token last=_tokens.back();

        for (int i=_tokens.size()-1;i>0;--i)
        {
            _tokens[i]=_tokens[i-1];
//            std::cout<<counter<<"_I:"<<i<<" "<<_tokens[i].getId()<<" "<<
//                    _tokens[i-1].getId()<<std::endl;
        }

        _tokens[0]=last;
//         std::cout<<"_E:"<<counter<<std::endl;
    }
}
