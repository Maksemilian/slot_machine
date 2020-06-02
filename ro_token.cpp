#include "ro_token.h"
#include "renderer.h"
#include "go_token.h"

#include <s_geometry.h>

void TokenRenderable:: render(Renderer& renderer, Token* token)
{
    drawTextureRect(token->rect(),
                renderer._tokenTextures[static_cast<size_t>(token->getId())]);
}
