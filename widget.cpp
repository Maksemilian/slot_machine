#include "widget.h"

Widget::Widget(){}

Widget::Widget(GLuint texture,GLfloat w,GLfloat h)
    :
      _texture(texture),
      _rect(0,0,w,h)
{
//std::cout<<"Widget_TEX:"<<texture<<std::endl;
}

void Widget::draw()
{
//    std::cout<<"Widget_DRAW:"<<_texture<<std::endl;
    //TODO если задается текстура то цвет ей нельзя задать
    glBindTexture(GL_TEXTURE_2D,_texture);
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
