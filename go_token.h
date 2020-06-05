#ifndef TOKEN_H
#define TOKEN_H

#include "go_game_object.h"


class Token : public GameObject
{
  public:
    enum class Type
    {
        T_Simple,
        T_Wild,
        T_Scutter,
        T_Bonus
    } ;

    Token(int tokenId, Type type = Type::T_Simple);
    Token(const Token& lhs);
    Token& operator=(const Token& lhs);

    inline void setId(int tokenId)
    {
        _tokenId = tokenId;
    }
    inline int getId()const
    {
        return  _tokenId;
    }
    inline void setSelected(bool select)
    {
        _selected = select;
    }
    inline bool isSelected()const
    {
        return _selected;
    }
  private:
    int _tokenId;
    Type _type;
    bool _selected;
};

#endif // TOKEN_H
