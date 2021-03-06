#ifndef RENDEREABLE_OBJECT_H
#define RENDEREABLE_OBJECT_H

class Renderer;
class Rect;

class Renderable
{
  public:
    Renderable() ;
    virtual ~Renderable() ;
    virtual void render(Renderer& renderer)  = 0;
};

template <typename T>
class RenderableObject        : public Renderable
{
  public:
    RenderableObject(T* object): _object(object) {}

    virtual void render(Renderer& renderer)  override
    {
        render(renderer, _object);
    }

    virtual void render(Renderer& renderer, T* object) = 0;

  public:
    T* _object;
};

#endif // RENDEREABLE_OBJECT_H
