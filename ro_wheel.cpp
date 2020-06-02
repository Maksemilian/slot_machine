#include "ro_wheel.h"

#include "go_wheel.h"
#include "go_token.h"
#include "renderer_game.h"

WheelRenderable::WheelRenderable(Wheel* wheel)
    : RenderableObject<Wheel>(wheel) {  }

void WheelRenderable::render(Renderer& renderer, Wheel* wheel)
{
    Rect& wheelRect = wheel->rect();
    GLfloat tokenW = wheel->rect().with();
    GLfloat tokenH = wheel->rect().height() / COUNT_VIEW_TOKENS;

    GLfloat  spaceBetweenToken = tokenH / COUNT_VIEW_TOKENS;
    Rect tokenRect(wheelRect.topLeft().x(),
                   wheelRect.topLeft().y(),
                   tokenW, tokenH );

    auto& tokens = wheel->tokens();
    for(size_t i = 0; i < COUNT_VIEW_TOKENS; ++i)
    {
        tokens[i].setRect(tokenRect);
        tokens[i].getRenderable()->render(renderer);
        tokenRect.setY(-(tokenRect.height() + spaceBetweenToken));
    }
}
