#include "s_geometry.h"
#include <cmath>



std::ostream &operator<<(std::ostream &out,const Vertex &v){
    out<<"v("<<v._x<<","<<v._y<<","<<v._z<<")";
    return out;
}

Vertex::Vertex():
    Vertex(0,0,0){}


Vertex::Vertex(GLfloat x,GLfloat y,GLfloat z):
    _v(new GLfloat[3]), _x(x),_y(y),_z(z)
{
    _v[0]=x;
    _v[1]=y;
    _v[2]=z;
}

Vertex::Vertex(const Vertex &lhs):
Vertex(lhs._x,lhs._y,lhs._z){}

Vertex::~Vertex(){
    delete [] _v;
}

Vertex& Vertex::operator=(const Vertex &l){
    if(this==&l){
        return *this;
    }

    _x=l._x;
    _y=l._y;
    _z=l._z;

    _v[0]=_x;
    _v[1]=_y;
    _v[2]=_z;

    return *this;
}

std::ostream &operator<<(std::ostream &out,const Rect &lhs)
{
    out<<"tl:"<<lhs._topLeft
      <<"tr:"<<lhs._topRight
     <<"bl:"<<lhs._bottomLeft
    <<"br:"<<lhs._bottomRight;
    return out;
}

Rect::Rect():Rect(0,0,0,0)
{

}

Rect::Rect(GLfloat x,GLfloat y,GLfloat w,GLfloat h):
    _topLeft(x,y),
    _topRight(x+w,y),

    _bottomLeft(x,y-h),
    _bottomRight(x+w,y-h)
{
    _w=distance(_topRight,_topLeft);
    _h=distance(_topRight,_bottomRight);
}

Rect::Rect(const Rect& lhs)
    :Rect(lhs.topLeft().x(),
          lhs.topLeft().y(),
          lhs.with(),lhs.height())
{

}

void Rect::setX(GLfloat x)
{
    _topLeft.setX(_topLeft.x()+x);
    _topRight.setX(_topRight.x()+x);

    _bottomLeft.setX(_bottomLeft.x()+x);
    _bottomRight.setX(_bottomRight.x()+x);
}

void Rect::setY(GLfloat y)
{
    _topLeft.setY(_topLeft.y()-y);
    _topRight.setY(_topRight.y()-y);

    _bottomLeft.setY(_bottomLeft.y()-y);
    _bottomRight.setY(_bottomRight.y()-y);
}

void Rect::setGeometry(GLfloat x,GLfloat y,GLfloat w,GLfloat h)
{
    _topLeft=Vertex(x,y);
    _topRight=Vertex(x+w,y);

    _bottomLeft=Vertex(x,y-h);
    _bottomRight=Vertex(x+w,y-h);

    _w=distance(_topRight,_topLeft);
    _h=distance(_topRight,_bottomRight);
//std::cout<<_topLeft<<std::endl;
    //        _topLeft._x=x;
    //        _topLeft._y=y;
    //        _topLeft.setV(x,y);

    //        _topRight._x=x+w;
    //        _topRight._y=y;
    //        _topRight.setV(x+w,y);

    //        _bottomLeft._x=x;
    //        _bottomLeft._y=y-h;
    //        _bottomLeft.setV(x,y-h);

    //        _bottomRight._x=x+w;
    //        _bottomRight._y=y-h;
    //        _bottomRight.setV(x+w,y-h);
}
//    Rect(GLfloat x,GLfloat y,GLfloat w,GLfloat h):
//        _bottomLeft(x,y),
//        _bottomRight(x+w,y),
//        _topLeft(x,y+h),
//        _topRight(x+w,y+h)
//    {
//        _w=distance(_topRight,_topLeft);
//        _h=distance(_topRight,_bottomRight);
//    }


GLfloat Rect::distance(const Vertex &v1,const Vertex &v2)
{
    return sqrt(pow(v1._x-v2._x,2)+pow(v1._y-v2._y,2)+pow(v1._z-v2._z,2));
}

void drawTextureRect(const Rect &rect,GLuint texture){
//    std::cout<<"|---"<<rect.topRight()<<" w"
//            <<rect.with()<<" h"
//           <<rect.height()
//           <<std::endl;
    glBindTexture(GL_TEXTURE_2D,
                  texture);

    Rect textureRect(0,0,1,1);
    glBegin(GL_QUADS);

    glTexCoord2fv(textureRect.topLeft());
    glVertex3fv(rect.bottomLeft());

    glTexCoord2fv(textureRect.topRight());
    glVertex3fv(rect.bottomRight());

    glTexCoord2fv(textureRect.bottomRight());
    glVertex3fv(rect.topRight());

    glTexCoord2fv(textureRect.bottomLeft());
    glVertex3fv(rect.topLeft());

    glEnd();
}
