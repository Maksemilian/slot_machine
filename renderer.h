#ifndef RENDERER_H
#define RENDERER_H

#include "s_texture_loader.h"
#include "s_geometry.h"

#include "go_slot_machine.h"
#include "ro_renderable_object.h"

class Renderer
{
public:
    int _countWheel=5;
    int _countViewTokens=3;

    std::pair<Texture,Texture> _blinkButtonTexture;
    std::vector<Texture> _tokenTextures;
    Texture _txBack;

    const std::string PATH_TO_TEXTURE[4]={
        "/resources/images/display/btn1.png",
        "/resources/images/display/btn2.png",
        "/resources/images/display/back.png",
        "/resources/images/tokens/"
    };

    std::unique_ptr<SlotMachine> slotMachine;
    Renderer(std::string &applicationDirPath)
    {
        _blinkButtonTexture.first=
                TextureLoader::loadTexture(applicationDirPath+PATH_TO_TEXTURE[0]);

        _blinkButtonTexture.second=
                TextureLoader::loadTexture(applicationDirPath+PATH_TO_TEXTURE[1]);

        _txBack=
                TextureLoader::loadTexture(applicationDirPath+PATH_TO_TEXTURE[2]);

        _tokenTextures =
                TextureLoader::loadTextures(applicationDirPath+PATH_TO_TEXTURE[3]);

        int _countTokensInWhell =
                static_cast<int>(_tokenTextures.size());

        slotMachine.reset(new SlotMachine(_countWheel,
                                             _countTokensInWhell));
    }

    void reshape(int w,int h)
    {
        Rect _backGroundRect(0,h,w,h);
        slotMachine->setRect(_backGroundRect);
    }

    void renderObjects()
    {
        slotMachine->getRenderable()->render(*this);
    }

    void mouseClicked(int x,int y) const
    {
        slotMachine->onPressEvent(x,y);
    }

    void keyClicked(unsigned char key)
    {

        if(key=='g')
        {
            std::cout<<"Game Start"<<std::endl;
            slotMachine->start();
        }
    }
};







#endif // RENDERER_H
