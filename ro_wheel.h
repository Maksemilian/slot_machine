#ifndef RO_WHEL_H
#define RO_WHEL_H

#include "rendereable_object.h"
class Wheel;

class WheelRenderable : public RenderableObject<Wheel> {
public:
    WheelRenderable(Wheel*wheel)
        : RenderableObject<Wheel>(wheel){  }
protected:
    virtual void render(Renderer& renderer, Wheel* wheel)override;
};


#endif // RO_WHEL_H
