#include "button.h"

Button::Button(){}

//Button::Button(GLfloat x,GLfloat y,
//               GLfloat w,GLfloat h)
//    :_rect(x,y,w,h)
//{

//}

Button::Button(GLuint texture,GLfloat x,GLfloat y,
               GLfloat w,GLfloat h)
    :Widget(texture,w,h)
//            _rect(x,y,w,h),_tex(texture)
{
//std::cout<<"BUTTON_TEX:"<<texture<<std::endl;
setGeometry(x,y,w,h);
}

//void Button::draw()
//{
//    glBindTexture(GL_TEXTURE_2D,_tex);

////    glColor3f(1.0,0,0);
//    Rect tx(0,0,1,1);
//    glBegin(GL_QUADS);

//    //TODO указывается происходит наложение текстуры
//    //даже если не указывать текстуру
//    glTexCoord2fv(tx.topLeft());
//    glVertex3fv(_rect.bottomLeft());
////        cout<<"begin"<<endl;
////        cout<<_rect.bottomLeft()<<_rect.bottomLeft()<<endl;

//    glTexCoord2fv(tx.topRight());
//    glVertex3fv(_rect.bottomRight());
////        cout<<_rect.bottomRight()<<_rect.bottomRight()<<endl;

//    glTexCoord2fv(tx.bottomRight());
//    glVertex3fv(_rect.topRight());
////        cout<<tx.bottomRight()<<_rect.topRight()<<endl;

//    glTexCoord2fv(tx.bottomLeft());
//    glVertex3fv(_rect.topLeft());
////        cout<<tx.bottomLeft()<<_rect.topLeft()<<endl;/
////        cout<<"end"<<endl;
//    glEnd();
//}
