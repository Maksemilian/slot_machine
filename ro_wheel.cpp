#include "ro_wheel.h"

#include "go_wheel.h"
#include "go_token.h"
#include "renderer.h"

void WheelRenderable::render(Renderer& renderer, Wheel* wheel)
{
    auto &tokens = wheel->tokens();


     Rect &wheelRect=wheel->rect();
     GLfloat tokenW=wheel->rect().with();
     GLfloat tokenH=wheel->rect().height()/renderer._countViewTokens;

     GLfloat  spaceBetweenToken=tokenH/renderer._countViewTokens;
//             /(renderer._countViewTokens-1);
     Rect tokenRect(wheelRect.topLeft().x(),
                    wheelRect.topLeft().y(),
                    tokenW,tokenH );

//    std::cout<<"Wheel Rect:"<<wheelRect
//            <<renderer._countViewTokens<<std::endl;

    for(int i=0;i<renderer._countViewTokens;++i)
    {
        tokens[i].setRect(tokenRect);
        tokens[i].getRenderable()->render(renderer);
        tokenRect.setY(tokenRect.height()+spaceBetweenToken);
    }
}
