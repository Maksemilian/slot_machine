#include "s_geometry.h"

std::ostream& operator<<(std::ostream& out, const Vertex& v)
{
    out << "v(" << v._x << "," << v._y << "," << v._z << ")";
    return out;
}

Vertex::Vertex():
    Vertex(0, 0, 0) {}


Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z):
    _v(new GLfloat[COUNT_AXIS]), _x(x), _y(y), _z(z)
{
    _v[XYZ::X] = x;
    _v[XYZ::Y] = y;
    _v[XYZ::Z] = z;
}

Vertex::Vertex(const Vertex& lhs):
    Vertex(lhs._x, lhs._y, lhs._z) {}

Vertex::~Vertex()
{
    delete [] _v;
}

Vertex& Vertex::operator=(const Vertex& l)
{
    if(this != &l)
    {
        _x = l._x;
        _y = l._y;
        _z = l._z;

        _v[XYZ::X] = l._x;
        _v[XYZ::Y] = l._y;
        _v[XYZ::Z] = l._z;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Rect& lhs)
{
    out << "tl:" << lhs._topLeft
        << "tr:" << lhs._topRight
        << "bl:" << lhs._bottomLeft
        << "br:" << lhs._bottomRight;
    return out;
}

Rect::Rect(): Rect(0, 0, 0, 0) {}

Rect::Rect(GLfloat x, GLfloat y, GLfloat w, GLfloat h):
    _topLeft(x, y),
    _topRight(x + w, y),

    _bottomLeft(x, y - h),
    _bottomRight(x + w, y - h),
    _w(w),
    _h(h)  {}

Rect::Rect(const Rect& lhs)
    : Rect(lhs.topLeft().x(),
           lhs.topLeft().y(),
           lhs.with(), lhs.height()) {}

void Rect::setX(GLfloat x)
{
    _topLeft.setX(_topLeft.x() + x);
    _topRight.setX(_topRight.x() + x);

    _bottomLeft.setX(_bottomLeft.x() + x);
    _bottomRight.setX(_bottomRight.x() + x);
}

void Rect::setY(GLfloat y)
{
    _topLeft.setY(_topLeft.y() + y);
    _topRight.setY(_topRight.y() + y);

    _bottomLeft.setY(_bottomLeft.y() + y);
    _bottomRight.setY(_bottomRight.y() + y);
}

void Rect::setGeometry(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
    _topLeft = Vertex(x, y);
    _topRight = Vertex(x + w, y);

    _bottomLeft = Vertex(x, y - h);
    _bottomRight = Vertex(x + w, y - h);

    _w = w;
    _h = h;
}

void drawTextureRect(const Rect& rect, GLuint texture)
{
    glBindTexture(GL_TEXTURE_2D,
                  texture);

    Rect textureRect(0, 0, 1, 1);
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
