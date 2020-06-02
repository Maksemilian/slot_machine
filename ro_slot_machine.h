#ifndef RO_SLOT_MACHINE_H
#define RO_SLOT_MACHINE_H


#include "ro_renderable_object.h"

class SlotMachine;
class Renderer;
#include "s_geometry.h"
class SlotMachineRenderable:public RenderableObject<SlotMachine>
{
public:
    SlotMachineRenderable(SlotMachine *slotMachine):
        RenderableObject<SlotMachine>(slotMachine)
    {

    }
    virtual void render(Renderer &renderer,SlotMachine *slotMachine)override;
};
#endif // RO_SLOT_MACHINE_H
