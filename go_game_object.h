#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class Renderable;
#include "s_geometry.h"

class GameObject
{
public:
    GameObject(Renderable*renderable)
        :_renderable(renderable){}

    virtual ~GameObject(){}

    void setRenderable(Renderable *renderable){
        _renderable=renderable;
    }

    Renderable* getRenderable() {
        // By default, all GameObjects are missing their Renderable
        return _renderable;
    }
    void setRect(const Rect &rect){_rect=rect;}
    Rect& rect(){return _rect;}
    virtual void onPressEvent(int x,int y){

    }
protected:
    Renderable *_renderable;
    Rect _rect;
};

#endif // GAME_OBJECT_H
