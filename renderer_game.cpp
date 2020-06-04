#include "renderer_game.h"
#include "ro_slot_machine.h"

Renderer::Renderer(std::string& applicationDirPath)
{
    _blinkButtonTexture.first =
        TextureLoader::loadTexture(applicationDirPath + PATH_TO_TEXTURE[0]);

    _blinkButtonTexture.second =
        TextureLoader::loadTexture(applicationDirPath + PATH_TO_TEXTURE[1]);

    _txBack =
        TextureLoader::loadTexture(applicationDirPath + PATH_TO_TEXTURE[2]);

    _tokenTextures =
        TextureLoader::loadTextures(applicationDirPath + PATH_TO_TEXTURE[3]);

    int _countTokensInWhell =
        static_cast<int>(_tokenTextures.size());

    slotMachine.reset(new SlotMachine(COUNT_WHEEL,
                                      _countTokensInWhell));
}

void Renderer::reshape(int w, int h)
{
    Rect _backGroundRect(0, h, w, h);
    slotMachine->setRect(_backGroundRect);
}

void Renderer::renderObjects()
{
    slotMachine->getRenderable()->render(*this);
}

void Renderer::mouseClicked(int x, int y) const
{
    slotMachine->onPressEvent(x, y);
}

void Renderer::keyClicked(unsigned char key)
{
    if(key == 'g')
    {
        std::cout << "Game Start" << std::endl;
        slotMachine->start();
    }
}
