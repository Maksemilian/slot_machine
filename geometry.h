#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <GL/gl.h>
#include <iostream>

class Vertex
{
public:
    Vertex();
    Vertex(GLfloat x,GLfloat y,GLfloat z=0.0);
    Vertex(const Vertex& lhs);
    ~Vertex();
    Vertex& operator=(const Vertex &l);
    operator  GLfloat*()const{ return _v; }
    GLfloat x()const{return _x;}
    GLfloat y()const {return _y;}
    GLfloat z()const{return _z;}

    friend class Rect;
    friend std::ostream &operator<<(std::ostream &out,const Vertex &v);
private:
    GLfloat *_v;
    GLfloat _x;
    GLfloat _y;
    GLfloat _z;
};

class Rect
{
public:
    Rect();
    Rect(GLfloat x,GLfloat y,GLfloat w,GLfloat h);

    void setGeometry(GLfloat x,GLfloat y,GLfloat w,GLfloat h);

    inline GLfloat with() const {return _w;}
    inline GLfloat height() const {return  _h;}

    inline const Vertex &topRight()const{return _topRight;}
    inline const Vertex &topLeft()const {return _topLeft;}
    inline const Vertex &bottomLeft()const{return _bottomLeft;}
    inline const Vertex &bottomRight()const{return _bottomRight;}
private:
    GLfloat distance(const Vertex &v1,const Vertex &v2);
private:
    Vertex _topLeft;
    Vertex _topRight;
    Vertex _bottomLeft;
    Vertex _bottomRight;

    GLfloat _w;
    GLfloat _h;
};


#endif // GEOMETRY_H
