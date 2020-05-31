#include "ro_slot_machine.h"
#include "go_slot_machine.h"
#include "go_wheel.h"

#include "s_geometry.h"
#include "renderer.h"

void SlotMachineRenderable::render(Renderer &renderer,SlotMachine *slotMachine)
{
    renderBackgraund(renderer);
    renderer._m_x1=renderer._marginLeft;
    renderer._m_y1=renderer._h-renderer._marginTop;
    auto &wheels=slotMachine->wheels();

    for(auto &wheel:wheels)
    {
     wheel.getRenderable()->render(renderer);
     renderer._m_x1+=renderer._tokenSize+renderer._spaceBetweenWheelW;
    }
}

void SlotMachineRenderable::renderBackgraund(Renderer &renderer)
{

    Rect rect(0,renderer._h,
               renderer._w,
               renderer._h);
   drawTextureRect(rect,renderer._txBack);
}
