#include "s_font.h"
#include <iostream>

std::map<char, Character>
getTexturesOfCharacters(const std::string& strOfCharacters,
                        const std::string& pathToFont,
                        unsigned int textureW,
                        unsigned int textureH)
{
    FT_Library  library;
    FT_Face     face;
    std::map<char, Character>characters;
    FT_Error error = FT_Init_FreeType( &library );
    error = FT_Init_FreeType( &library );
    if ( error )
    {
        throw std::runtime_error("FREETYTPE_ERR:error init lib");
    }
    error = FT_New_Face( library, pathToFont.data(),
                         0,
                         &face );
    if ( error == FT_Err_Unknown_File_Format )
    {
        throw std::runtime_error("FREETYTPE_ERR:unknown_file_format");
    }
    else if ( error )
    {
        throw std::runtime_error("FREETYTPE_ERR:another error" + std::to_string(error));
    }
    else
    {
        FT_Set_Pixel_Sizes(face, textureW, textureH);
        for(auto& ch : strOfCharacters)
        {
            error = FT_Load_Char(face, ch, FT_LOAD_RENDER);
            if (error)
            {
                throw std::runtime_error("FREETYTPE_ERR: Failed to load Glyph"
                                         + std::to_string(ch) +
                                         std::to_string(error));
            }
            else
            {
                GLuint textureGlyph;

                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glGenTextures(1, &textureGlyph);
                glBindTexture(GL_TEXTURE_2D, textureGlyph);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                glTexImage2D(
                    GL_TEXTURE_2D, 0,
                    GL_RED,
                    face->glyph->bitmap.width,
                    face->glyph->bitmap.rows,
                    0,
                    GL_RED,
                    GL_UNSIGNED_BYTE,
                    face->glyph->bitmap.buffer
                );

                Character character =
                {
                    textureGlyph,
                    face->glyph->bitmap.width,
                    face->glyph->bitmap.rows,
                    face->glyph->bitmap_left,
                    face->glyph->bitmap_top,
                    face->glyph->advance.x
                };
                characters.insert(std::pair<char, Character>(ch, character));
            }
        }
        FT_Done_Face(face);
        FT_Done_FreeType(library);
        return characters;
    }
}
