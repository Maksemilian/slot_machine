#ifndef RO_SLOT_MACHINE_H
#define RO_SLOT_MACHINE_H


#include "ro_renderable_object.h"

class SlotMachine;
class Renderer;
class SlotMachineRenderable:public RenderableObject<SlotMachine>
{
public:
    SlotMachineRenderable(SlotMachine *slotMachine):
        RenderableObject<SlotMachine>(slotMachine)
    {
//        wBackground=new Widget(txBack._textureId,_windowWidth,_windowHeight);
//        wBackground->setGeometry(m_x1,_windowHeight,_windowWidth,_windowHeight);

    }
    virtual void render(Renderer &renderer,SlotMachine *slotMachine)override;
private:
    void renderBackgraund(Renderer &renderer);
//    Widget *wBackground;
};
#endif // RO_SLOT_MACHINE_H
