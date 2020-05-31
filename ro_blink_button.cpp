#include "ro_blink_button.h"
#include "s_geometry.h"

#include "renderer.h"
#include "go_blink_button.h"

RenderableBlinkButton::RenderableBlinkButton(BlinkButton *blinkButton)
    :RenderableObject<BlinkButton> (blinkButton)
{

}

void RenderableBlinkButton::render(Renderer &renderer, BlinkButton *blinkButton)
{
    Rect rect(renderer.xPosButton,
               renderer.yPosButton,
               renderer.startButtonW,
               renderer.startButtonH);

    if(!blinkButton->blinkStatus()){
        drawTextureRect(rect,renderer._blinkButtonTexture.first);
    }else {
        drawTextureRect(rect,renderer._blinkButtonTexture.second);
    }
}
