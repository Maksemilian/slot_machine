#ifndef RO_TOKEN_H
#define RO_TOKEN_H

#include "ro_renderable_object.h"

class Token;

class TokenRenderable:public RenderableObject<Token>
{
public:
    TokenRenderable(Token *token):
        RenderableObject<Token>(token)   {  }

    void render(Renderer& renderer, Token* token)override;
};

#endif // RO_TOKEN_H
