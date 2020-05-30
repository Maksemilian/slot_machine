#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class Renderable;

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
protected:
    Renderable *_renderable;
};

#endif // GAME_OBJECT_H
