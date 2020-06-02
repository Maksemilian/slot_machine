#ifndef RO_WHEL_H
#define RO_WHEL_H

#include "ro_renderable_object.h"

class Wheel;

class WheelRenderable : public RenderableObject<Wheel>
{
    static const int COUNT_VIEW_TOKENS = 3;
  public:
    WheelRenderable(Wheel* wheel);
  protected:
    virtual void render(Renderer& renderer, Wheel* wheel)override;
};


#endif // RO_WHEL_H
