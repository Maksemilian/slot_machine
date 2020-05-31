#ifndef RO_BLINK_BUTTON_H
#define RO_BLINK_BUTTON_H

#include "rendereable_object.h"

class BlinkButton;
class Renderer;
class RenderableBlinkButton:public RenderableObject<BlinkButton>
{
public:
    RenderableBlinkButton(BlinkButton *blinkButton);
     void render(Renderer& renderer, BlinkButton* blinkButton)override;

};

#endif // RO_BLINK_BUTTON_H
