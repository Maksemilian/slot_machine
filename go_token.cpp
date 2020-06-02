#include "go_token.h"
#include "ro_token.h"

Token::Token(int tokenId, Type type):
    GameObject(new TokenRenderable(this)),
    _tokenId(tokenId),
    _type(type)
{}


Token::Token(const Token& lhs)
    : GameObject(new TokenRenderable(this))
{
    _tokenId = lhs._tokenId;
    _type = lhs._type;
}

Token& Token::operator=(const Token& lhs)
{
    if(this != &lhs)
    {
        _tokenId = lhs._tokenId;
        _type = lhs._type;
    }
    return *this;
}

