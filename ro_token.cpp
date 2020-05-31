#include "ro_token.h"
#include "renderer.h"
#include "go_token.h"

#include <s_geometry.h>

void TokenRenderable:: render(Renderer& renderer, Token* token)
{
    Rect rect(renderer._m_x1,
               renderer._m_y1,
               renderer._tokenSize,
               renderer._tokenSize);

    drawTextureRect(rect,
                renderer._tokenTextures[static_cast<size_t>(token->getId())]);

}
