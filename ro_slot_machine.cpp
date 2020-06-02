#include "ro_slot_machine.h"
#include "go_slot_machine.h"
#include "go_wheel.h"

#include "go_blink_button.h"
#include "s_geometry.h"
#include "renderer_game.h"


SlotMachineRenderable::SlotMachineRenderable(SlotMachine* slotMachine):
    RenderableObject<SlotMachine>(slotMachine) { }

void SlotMachineRenderable::render(Renderer& renderer, SlotMachine* slotMachine)
{
    GLfloat _w = slotMachine->rect().with();
    GLfloat _h = slotMachine->rect().height();

    GLfloat _marginLeft;
    GLfloat _marginRight;

    GLfloat _marginTop;
    GLfloat _marginBottom;

    //вычисляется ка процентное соотношение от w и h
    _marginTop = _h * 12 / 100;
    _marginBottom = _h * 40 / 100;

    _marginLeft = _w * 18 / 100;
    _marginRight = _marginLeft;

    GLfloat tokenFieldW = _w - _marginLeft - _marginRight;
    GLfloat tokenFieldH = _h - _marginTop - _marginBottom;

    GLfloat _startButtonW;
    GLfloat _startButtonH;

    GLfloat _xPosButton;
    GLfloat _yPosButton;

    _startButtonW = _w * 12 / 100;
    _startButtonH = _startButtonW;

    _xPosButton = _w - _startButtonW;
    _yPosButton = _startButtonH;
    slotMachine->startButton().setRect({_xPosButton, _yPosButton,
                                        _startButtonW,
                                        _startButtonH});
    //draw background
    drawTextureRect({0, _h, _w, _h}, renderer._txBack);

    slotMachine->startButton().getRenderable()->render(renderer);
    Rect _fieldsForWheelRect(_marginLeft,
                             _h - _marginTop,
                             tokenFieldW,
                             tokenFieldH);

    GLfloat x = _fieldsForWheelRect.topLeft().x();
    GLfloat y = _fieldsForWheelRect.topLeft().y();

    GLfloat w = _fieldsForWheelRect.with() / slotMachine->countWheel();

    GLfloat h = _fieldsForWheelRect.height();

    GLfloat _spaceBetweenWheel = w / slotMachine->countWheel();

    Rect wheelRect(x, y, w - _spaceBetweenWheel, h);
    auto& wheels = slotMachine->wheels();
    for(auto& wheel : wheels)
    {
        wheel.setRect(wheelRect);
        wheel.getRenderable()->render(renderer);

        wheelRect.setX(wheelRect.with() + _spaceBetweenWheel);
    }


}

