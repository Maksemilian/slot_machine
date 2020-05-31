#ifndef FONT_H
#define FONT_H

#include <GL/gl.h>
#include <map>

#include <ft2build.h>
#include <freetype/freetype.h>

struct Character
{
    GLuint     _texture; // ID текстуры глифа
#ifdef WIN32
    FT_Int _w;//win
    FT_Int _r;//win
#else
    FT_UInt _w;//lin
    FT_UInt _r;//lin
#endif

    FT_Int left;
    FT_Int top;
    FT_Pos Advance;
};

std::map<char,Character>
getTexturesOfCharacters(const std::string&characters,
                        const std::string& pathToFont);



#endif // FONT_H
