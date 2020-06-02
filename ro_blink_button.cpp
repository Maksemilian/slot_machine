#include "ro_blink_button.h"
#include "s_geometry.h"

#include "renderer_game.h"
#include "go_blink_button.h"

RenderableBlinkButton::RenderableBlinkButton(BlinkButton* blinkButton)
    : RenderableObject<BlinkButton> (blinkButton) {}

void RenderableBlinkButton::render(Renderer& renderer, BlinkButton* blinkButton)
{
    if(!blinkButton->blinkStatus())
    {
        drawTextureRect(blinkButton->rect(), renderer._blinkButtonTexture.first);
    }
    else
    {
        drawTextureRect(blinkButton->rect(), renderer._blinkButtonTexture.second);
    }
}
