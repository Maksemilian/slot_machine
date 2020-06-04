#ifndef RENDERER_H
#define RENDERER_H

#include "s_texture_loader.h"
#include "go_slot_machine.h"

class Renderer
{
    static const int COUNT_WHEEL = 5;
  public:
    std::pair<Texture, Texture> _blinkButtonTexture;
    std::vector<Texture> _tokenTextures;
    Texture _txBack;

    const std::string PATH_TO_TEXTURE[4] =
    {
        "/resources/images/display/btn1.png",
        "/resources/images/display/btn2.png",
        "/resources/images/display/back.png",
        "/resources/images/tokens/"
    };

    std::unique_ptr<SlotMachine> slotMachine;
    Renderer(std::string& applicationDirPath);

    void reshape(int w, int h);

    void renderObjects();

    void mouseClicked(int x, int y) const;
    void keyClicked(unsigned char key);
};

#endif // RENDERER_H
