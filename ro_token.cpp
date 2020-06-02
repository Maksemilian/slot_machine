#include "ro_token.h"
#include "renderer_game.h"
#include "go_token.h"

#include "s_geometry.h"

TokenRenderable::TokenRenderable(Token* token):
    RenderableObject<Token>(token)   {  }

void TokenRenderable:: render(Renderer& renderer, Token* token)
{
    drawTextureRect(token->rect(),
                    renderer._tokenTextures[static_cast<size_t>(token->getId())]);
}
