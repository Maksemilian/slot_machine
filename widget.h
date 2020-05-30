#ifndef WIDGET_H
#define WIDGET_H

#include "geometry.h"

class Widget
{
public:
    Widget();
    //TODO сделать передачу Icon вместо Gluint
    Widget(GLuint texture,GLfloat w,GLfloat h);
    virtual void draw();
    inline const Rect& rect()const{return _rect;}
    inline GLfloat height()const{return  _rect.height();}
    inline GLfloat width()const{return  _rect.with();}
    inline void setGeometry(GLfloat x,GLfloat y,GLfloat w,GLfloat h){
        _rect.setGeometry(x,y,w,h);
    }
    void setTexture(GLuint texture){
        _texture=texture;
    }
    GLuint _texture;
    protected:
    Rect _rect;
};
#endif // WIDGET_H
