#ifndef RENDEREABLE_OBJECT_H
#define RENDEREABLE_OBJECT_H

class Renderer;

class Renderable
{
public:
    Renderable(){}
    virtual ~Renderable(){}
    virtual void render(Renderer& renderer)  = 0;
};

template <typename T>
class RenderableObject
        : public Renderable
{
public:
    RenderableObject(T* object):_object(object){}

    virtual void render(Renderer& renderer)  override{
        render(renderer, _object);
    }
    virtual void render(Renderer& renderer, T* object) = 0;
    void setObject(T*object){
        _object=object;
    }
public:
    T*_object;
    //public:
    //    RenderableObject(T& object)
    //        :mObject(object) {}
    //    virtual ~RenderableObject(){}


    //protected:
    //    virtual void render(Renderer& renderer, T& object) = 0;
    //    T mObject;
};
#endif // RENDEREABLE_OBJECT_H
