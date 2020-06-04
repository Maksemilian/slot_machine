#ifndef RENDERER_TEXT_H
#define RENDERER_TEXT_H

#include "s_font.h"

class RendererText
{
  public:

    RendererText(const std::string& appDirPath,
                 const std::string characters,
                 unsigned int w, unsigned int h);

    void render(const std::string& text,
                GLfloat x, GLfloat y);

    void reshape(int w, int h);
  private:
    std::map<char, Character>_characters;
    std::string _appDirPath;
    std::string _scharacters;
    unsigned int _w;
    unsigned int _h;
};

#endif // RENDERER_TEXT_H
