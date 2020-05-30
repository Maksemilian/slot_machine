#include "geometry.h"
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

Rect::Rect():_w(0.0),_h(0.0)
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

void Rect::setGeometry(GLfloat x,GLfloat y,GLfloat w,GLfloat h){
    _topLeft=Vertex(x,y);
    _topRight=Vertex(x+w,y);

    _bottomLeft=Vertex(x,y-h);
    _bottomRight=Vertex(x+w,y-h);
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
