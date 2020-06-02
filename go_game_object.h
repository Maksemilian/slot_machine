#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "s_geometry.h"
#define UNUSED(P) {(P) = (P);}


class Renderable;

class GameObject
{
  public:
    GameObject(Renderable* renderable);

    virtual ~GameObject();

    inline void setRenderable(Renderable* renderable)
    {
        _renderable = renderable;
    }

    inline Renderable* getRenderable()
    {
        return _renderable;
    }

    inline void setRect(const Rect& rect)
    {
        _rect = rect;
    }

    inline Rect& rect()
    {
        return _rect;
    }

    virtual void onPressEvent(int x, int y);
  protected:
    Renderable* _renderable;
    Rect _rect;
};

#endif // GAME_OBJECT_H
