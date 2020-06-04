#include "renderer_text.h"
#include "s_geometry.h"

RendererText::RendererText(const std::string& appDirPath,
                           const std::string characters,
                           unsigned int w, unsigned int h)
{
    const std::string PATH_TO_FONT = "/resources/arial.ttf";
    _w = w;
    _h = h;
    _appDirPath = appDirPath + PATH_TO_FONT;
    _scharacters = characters;
    _characters = getTexturesOfCharacters(_scharacters,
                                          _appDirPath,
                                          w, h);
}

void RendererText::render(const std::string& text,
                          GLfloat x, GLfloat y)
{
    Rect rect(x, y + _h, _w, _h);

    for(auto& ch : text)
    {
        rect.setGeometry(x, y + _h,
                         _w,
                         _h);
        drawTextureRect(rect, _characters[ch]._texture);
        x += _w;
    }
}

void RendererText::reshape(int w, int h)
{
    _characters.clear();
    _w = static_cast<unsigned int >(w);
    _h = static_cast<unsigned int >(h);
    _characters = getTexturesOfCharacters(_scharacters,
                                          _appDirPath,
                                          _w,
                                          _h);
}
