#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <GL/gl.h>
#include <iostream>

class Vertex
{
    enum XYZ
    {
        X = 0,
        Y = 1,
        Z = 2,
        COUNT_AXIS = 3
    };
  public:
    Vertex();
    Vertex(GLfloat x, GLfloat y, GLfloat z = 0.0);
    Vertex(const Vertex& lhs);
    ~Vertex();
    Vertex& operator=(const Vertex& l);
    operator  GLfloat* ()const
    {
        return _v;
    }
    GLfloat x()const
    {
        return _x;
    }
    GLfloat y()const
    {
        return _y;
    }
    GLfloat z()const
    {
        return _z;
    }
    void setX(GLfloat x)
    {
        _x = x;
        _v[XYZ::X] = x;
    }
    void setY(GLfloat y)
    {
        _y = y;
        _v[XYZ::Y] = y;
    }

    friend class Rect;
    friend std::ostream& operator<<(std::ostream& out, const Vertex& v);
  private:
    GLfloat* _v;
    GLfloat _x;
    GLfloat _y;
    GLfloat _z;
};

class Rect
{
  public:
    Rect();
    Rect(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
    Rect(const Rect& lhs);
    void setGeometry(GLfloat x, GLfloat y, GLfloat w, GLfloat h);

    inline GLfloat with() const
    {
        return _w;
    }
    inline GLfloat height() const
    {
        return  _h;
    }

    inline const Vertex& topRight()const
    {
        return _topRight;
    }
    inline const Vertex& topLeft()const
    {
        return _topLeft;
    }
    inline const Vertex& bottomLeft()const
    {
        return _bottomLeft;
    }
    inline const Vertex& bottomRight()const
    {
        return _bottomRight;
    }
    //перемещает Rect на y от текущей позиции y
    void setY(GLfloat y);

    //перемещает Rect на x от текущей позиции x
    void setX(GLfloat x);

    friend std::ostream& operator<<(std::ostream& out, const Rect& v);

  private:
    Vertex _topLeft;
    Vertex _topRight;
    Vertex _bottomLeft;
    Vertex _bottomRight;

    GLfloat _w;
    GLfloat _h;
};

void drawTextureRect(const Rect& rect, GLuint texture);
#endif // GEOMETRY_H
