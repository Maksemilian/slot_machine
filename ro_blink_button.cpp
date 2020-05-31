#include "ro_blink_button.h"
#include "geometry.h"

#include "renderer.h"
#include "go_blink_button.h"

RenderableBlinkButton::RenderableBlinkButton(BlinkButton *blinkButton)
    :RenderableObject<BlinkButton> (blinkButton)
{

}

void RenderableBlinkButton::render(Renderer &renderer, BlinkButton *blinkButton)
{

    if(!blinkButton->blinkStatus()){
        glBindTexture(GL_TEXTURE_2D,renderer._blinkButtonTexture.first);
    }
    else {
        glBindTexture(GL_TEXTURE_2D,renderer._blinkButtonTexture.second);
    }

    Rect _rect(renderer.xPosButton,
               renderer.yPosButton,
               renderer.startButtonW,
               renderer.startButtonH);

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
