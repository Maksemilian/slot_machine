#include "go_slot_machine.h"
#include "ro_slot_machine.h"

#include "go_blink_button.h"
#include "ro_blink_button.h"

const int SlotMachine::TIME_STOP_WHEEL;

//SlotMachine::SlotMachine(const std::vector<Wheel> &wheels)

//    ://TODO
//      //не создвать через конструктор
//      //сначала создать данные
//      //а потом проинициал
//GameObject(new SlotMachineRenderable(this)),
//      _wheels(wheels)
//{

//}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

SlotMachine::SlotMachine(int countWheel,int countTokensInWheel
                        /* ,RenderableObject<SlotMachine>*renderable*/)
    :GameObject(new SlotMachineRenderable(this))
//    :GameObject (renderable)
{
    for(int i=0;i<countWheel;++i){
        _wheels.push_back({countTokensInWheel});
        _wheels[i].setSpeed(getRandomNumber(MIN_WHEEL_SPEED,MAX_WHEEL_SPEED));
    }
    _startButton=new BlinkButton;
    _startButton->setTime(400);
}

void SlotMachine::start()
{
    //запуск колес
    for(size_t i=0;i<_wheels.size();i++)
    {
        _wheels[i].startSpin();
    }

    //запуск таймера для проверки остановки
    _wheelStopingTimer.singleTimeout(std::chrono::seconds(TIME_STOP_WHEEL),
                          [this](){
        this->waitForStopWheel();
    });
}

void SlotMachine::waitForStopWheel()
{
    //TODO do without static var
    static unsigned int wi=0;
    //    auto it=_wheels.begin();
    _wheelStopingTimer.start();
    _wheelStopingTimer.recursiveTimeout(std::chrono::milliseconds(1000),
                             [this](){
        //        if(it!=_wheels.end())
        //            (*it)->stop();
        //        else _timerT.stop();

        //        it++;
        if(wi<_wheels.size()){
            _wheels[wi].stopSpin();
            ++wi;
        }else {
            wi=0;
            _wheelStopingTimer.stop();
        }
    });
}

//TODO сделать метод
void SlotMachine::stop()
{

}

void SlotMachine::onPressEvent(int x, int y)
{
    y=rect().height()-y;
    Rect _blinkButtonRect=_startButton->rect();
//        std::cout<<x<<" "<<y<<" || "
//                <<_blinkButtonRect.topLeft().x()<<" "
//               <<_blinkButtonRect.topLeft().y()<<" "
//              <<_blinkButtonRect.with()<<" "
//             <<_blinkButtonRect.height()<<std::endl;
    if( (x>_blinkButtonRect.topLeft().x() && y<_blinkButtonRect.topLeft().y()) &&
            (x<_blinkButtonRect.topLeft().x()+_blinkButtonRect.with() &&
             y>_blinkButtonRect.topLeft().y()-_blinkButtonRect.height()))
    {
        start();
    }
}
