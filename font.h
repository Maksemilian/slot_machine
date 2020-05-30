#ifndef FONT_H
#define FONT_H

#include <GL/gl.h>
#include <map>

#include <ft2build.h>
#include <freetype/freetype.h>

struct Character
{
    GLuint     TextureID; // ID текстуры глифа
//    FT_UInt w;//lin
//    FT_UInt r;//lin
        FT_Int w;//win
        FT_Int r;//win

    FT_Int left;
    FT_Int top;
    FT_Pos Advance;

    // Размеры глифа
//    GLuint w; //unix
//    GLuint r; //unix
//    int w; //unix
//    int r; //unix
};

std::map<char,Character>
getTexturesOfCharacters(const std::string&characters,
                        const std::string& pathToFont);



#endif // FONT_H
