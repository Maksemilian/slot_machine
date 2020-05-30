#ifndef BUTTON_H
#define BUTTON_H

#include "widget.h"

class Button :public Widget
{
public:
    Button();
    Button(GLuint texture,GLfloat x,GLfloat y,
           GLfloat w,GLfloat h);

//    Button(GLfloat x,GLfloat y,
//           GLfloat w,GLfloat h);

    bool containsPoint(int x,int y) const
      {
        return (x>rect().topLeft().x() && y<rect().topLeft().y())&&
                (x<rect().topLeft().x()+rect().with() && y>rect().topLeft().y()-height());
      }

//    void draw();
//    inline const Rect& rect(){return _rect;}
//    inline GLfloat height(){return  _rect.height();}
//    inline GLfloat width(){return  _rect.with();}
//    inline void setGeometry(GLfloat x,GLfloat y,GLfloat w,GLfloat h){
//        _rect.setGeometry(x,y,w,h);
//    }
//private:
//    Rect _rect;
//    GLuint _tex;

};

#endif // BUTTON_H
