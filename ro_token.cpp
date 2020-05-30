#include "ro_token.h"
#include "renderer.h"
#include "go_token.h"

#include <geometry.h>
void TokenRenderable:: render(Renderer& renderer, Token* token)
{
    Rect _rect(renderer._m_x1,
               renderer._m_y1,
               renderer._tokenSize,
               renderer._tokenSize);

    //если символ не подсвечен
    glBindTexture(GL_TEXTURE_2D,
                  renderer._tokenTextures[token->getId()]);
//        std::cout<<token->getId()<<" "
//                <<renderer._tokenTextures[token->getId()]<<std::endl;

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
