#include "ro_slot_machine.h"
#include "go_slot_machine.h"
#include "go_wheel.h"

void SlotMachineRenderable::render(Renderer &renderer,SlotMachine *slotMachine)
{
    //если колеса вращаются
    renderBackgraund(renderer);
    renderer._m_x1=renderer._marginLeft;
    renderer._m_y1=renderer._h-renderer._marginTop;
    auto &wheels=slotMachine->wheels();
//        std::cout<<"SM:"<<wheels.size()<<wheels[0].countTokens()<<std::endl;

    for(auto &wheel:wheels)
    {
//            std::cout<<"SM_W:"<<&wheel<<" "<<wheel.getRenderable()
//                    <<wheel.countTokens()<<std::endl;
        wheel.getRenderable()->render(renderer);
     renderer._m_x1+=renderer._tokenSize+renderer._spaceBetweenWheelW;
    }
//        иначе определяется выйгрыш
}

void SlotMachineRenderable::renderBackgraund(Renderer &renderer)
{

    glBindTexture(GL_TEXTURE_2D,renderer._txBack);
    Rect _rect(0,renderer._h,
               renderer._w,
               renderer._h);
    Rect tx(0,0,1,1);
    glBegin(GL_QUADS);

    glTexCoord2fv(tx.topLeft());
    glVertex3fv(_rect.bottomLeft());
//        cout<<"begin"<<endl;
//        cout<<_rect.bottomLeft()<<_rect.bottomLeft()<<endl;

    glTexCoord2fv(tx.topRight());
    glVertex3fv(_rect.bottomRight());
//        cout<<_rect.bottomRight()<<_rect.bottomRight()<<endl;

    glTexCoord2fv(tx.bottomRight());
    glVertex3fv(_rect.topRight());
//        cout<<tx.bottomRight()<<_rect.topRight()<<endl;

    glTexCoord2fv(tx.bottomLeft());
    glVertex3fv(_rect.topLeft());
//        cout<<tx.bottomLeft()<<_rect.topLeft()<<endl;/
//        cout<<"end"<<endl;
    glEnd();
}
