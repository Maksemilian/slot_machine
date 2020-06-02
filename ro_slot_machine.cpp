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
    GLfloat slotMachineW = slotMachine->rect().with();
    GLfloat slotMachineH = slotMachine->rect().height();

    GLfloat marginLeft;
    GLfloat marginRight;

    GLfloat marginTop;
    GLfloat marginBottom;

    //вычисляется как процентное соотношение от размеров игрового автомата
    marginTop = slotMachineH * 12 / 100;
    marginBottom = slotMachineH * 40 / 100;

    marginLeft = slotMachineW * 18 / 100;
    marginRight = marginLeft;

    GLfloat tokenFieldW = slotMachineW - marginLeft - marginRight;
    GLfloat tokenFieldH = slotMachineH - marginTop - marginBottom;

    GLfloat startButtonW;
    GLfloat startButtonH;

    GLfloat xPosButton;
    GLfloat yPosButton;

    startButtonW = slotMachineW * 12 / 100;
    startButtonH = startButtonW;

    xPosButton = slotMachineW - startButtonW;
    yPosButton = startButtonH;
    slotMachine->startButton().setRect({xPosButton, yPosButton,
                                        startButtonW,
                                        startButtonH});
    //draw background
    drawTextureRect({0, slotMachineH, slotMachineW, slotMachineH}, renderer._txBack);

    slotMachine->startButton().getRenderable()->render(renderer);

    Rect fieldsForWheelRect(marginLeft,
                            slotMachineH - marginTop,
                            tokenFieldW,
                            tokenFieldH);

    GLfloat fielsForWheelX = fieldsForWheelRect.topLeft().x();
    GLfloat fielsForWheelY = fieldsForWheelRect.topLeft().y();

    GLfloat fielsForWheelW = fieldsForWheelRect.with() / slotMachine->countWheel();

    GLfloat fielsForWheelH = fieldsForWheelRect.height();

    GLfloat spaceBetweenWheel = fielsForWheelW / slotMachine->countWheel();

    Rect wheelRect(fielsForWheelX, fielsForWheelY, fielsForWheelW - spaceBetweenWheel, fielsForWheelH);

    auto& wheels = slotMachine->wheels();
    for(auto& wheel : wheels)
    {
        wheel.setRect(wheelRect);
        wheel.getRenderable()->render(renderer);

        wheelRect.setX(wheelRect.with() + spaceBetweenWheel);
    }
}

