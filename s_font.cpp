#include "s_font.h"
#include <iostream>

std::map<char,Character>
getTexturesOfCharacters(const std::string &strOfCharacters,
                        const std::string& pathToFont,
                        unsigned int textureW,
                        unsigned int textureH)
{
    FT_Library  library;   /* handle to library     */
    FT_Face     face;      /* handle to face object */
    std::map<char,Character>characters;
    FT_Error error = FT_Init_FreeType( &library );
    error = FT_Init_FreeType( &library );
    if ( error ) {
        std::cout<<"error init lib"<<std::endl;
        return {};
    }
    error = FT_New_Face( library,pathToFont.data(),
                         0,
                         &face );
    if ( error == FT_Err_Unknown_File_Format )
    {
        std::cout<<"unknown_file_format"<<std::endl;
        return {};
    }
    else if ( error )
    {
        std::cout<<"another error"<<error<<std::endl;
        return {};
    }
    else
    {
        FT_Set_Pixel_Sizes(face, textureW, textureH);
        for(auto &ch:strOfCharacters)
        {
            error=FT_Load_Char(face, ch, FT_LOAD_RENDER);
            if (error)
            {
                std::cout << "ERROR::FREETYTPE: Failed to load Glyph:"
                          <<error<< std::endl;
            }
            else
            {
                GLuint textureGlyph;
                //TODO без этого параметра не отображается одно число
                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glGenTextures(1, &textureGlyph);
                glBindTexture(GL_TEXTURE_2D, textureGlyph);

                //            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                //            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

                //            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
                //            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                glTexImage2D(
                            GL_TEXTURE_2D,0,
                            GL_RED,
                            //                        GL_RGB,
                            face->glyph->bitmap.width,
                            face->glyph->bitmap.rows,
                            0,//1
                            GL_RED,
                            //                        GL_RGB,
                            GL_UNSIGNED_BYTE,
                            face->glyph->bitmap.buffer
                            );

                Character character = {
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
        FT_Done_Face(face);   // Завершение работы с шрифтом face
        FT_Done_FreeType(library);
        return characters;
    }
}
