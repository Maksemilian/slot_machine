#include "ro_wheel.h"

#include "go_wheel.h"
#include "go_token.h"

void WheelRenderable::render(Renderer& renderer, Wheel* wheel)
{
    auto &tokens = wheel->tokens();
//        std::cout<<"TS:"<<wheel<<" "<<this<<" "<<tokensSize<<" "<<wheel->countTokens()<<std::endl;
    //если колесо крутиться
     GLfloat y=renderer._m_y1;
    for(int i=0;i<renderer._countViewTokens;++i)
    {
        tokens[i].getRenderable()->render(renderer);
        renderer._m_y1-=(renderer._tokenSize+renderer._spaceBetweenWheelW);
    }
    renderer._m_y1=y;
//        иначе подсветка символов
}
