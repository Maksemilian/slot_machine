#ifndef RENDERER_H
#define RENDERER_H

#include "texture.h"

#include <GL/gl.h>

#include <iostream>
#include <cmath>

#include "go_blink_button.h"
#include "go_slot_machine.h"
#include "rendereable_object.h"

class Renderer
{
public:
    GLfloat _m_x1 = 0.0f;   /// GLfloat - аналог float
    GLfloat _m_y1 = 100;

    int _countWheel=5;
    int _countViewTokens=3;
    int _countTokensInWhell=0;

    GLfloat _tokenSize;
    GLfloat _spaceBetweenWheelW;
    GLfloat _spaceBetweenWheelH;

    std::pair<Texture,Texture> _blinkButtonTexture;
    std::vector<Texture> _tokenTextures;
    Texture _txBack;

    GLfloat _marginLeft;
    GLfloat _marginRight;

    GLfloat _marginTop;
    GLfloat _marginBottom;
    int _w;
    int _h;

    GLfloat startButtonW;
    GLfloat startButtonH;

    GLfloat xPosButton;
    GLfloat yPosButton;

    const std::string PATH_TO_TEXTURE[4]={
        "/resources/images/display/btn1.png",
        "/resources/images/display/btn2.png",
        "/resources/images/display/back.png",
        "/resources/images/tokens/"
    };
    SlotMachine *slotMachine;
    BlinkButton *startButton;

    Renderer(std::string &applicationDirPath,int w,int h)
    {
        _w=w;
        _h=h;

        _blinkButtonTexture.first=
                TextureLoader::loadTexture(applicationDirPath+PATH_TO_TEXTURE[0]);

        _blinkButtonTexture.second=
                TextureLoader::loadTexture(applicationDirPath+PATH_TO_TEXTURE[1]);

        _txBack=
                TextureLoader::loadTexture(applicationDirPath+PATH_TO_TEXTURE[2]);

        _tokenTextures =
                TextureLoader::loadTextures(applicationDirPath+PATH_TO_TEXTURE[3]);


        _marginTop=h*12/100;
        _marginBottom=h*40/100;

        _marginLeft=w*18/100;
        _marginRight=_marginLeft;

        GLfloat tokenFieldW=w-_marginLeft-_marginRight;
        GLfloat tokenFieldH=h-_marginTop-_marginBottom;

        GLfloat tokenFieldSquare=tokenFieldW*tokenFieldH;
        GLfloat spaceBetwenTokens=(tokenFieldW/_countWheel)*tokenFieldH;

        GLfloat tokenSquare=(tokenFieldSquare-spaceBetwenTokens)/
                (_countWheel*_countViewTokens);

        _tokenSize=static_cast<int>(sqrt(static_cast<GLdouble>(tokenSquare)));

        _m_x1=_marginLeft;
        _m_y1=h-_marginTop;

        _spaceBetweenWheelW=_tokenSize/_countWheel-1;
        _spaceBetweenWheelH=_tokenSize/_countViewTokens-1;
        _countTokensInWhell=static_cast<int>(_tokenTextures.size());

        startButtonW=_w*12/100;
        startButtonH=startButtonW;

        xPosButton=_w-startButtonW;
        yPosButton=startButtonH;

        startButton=new BlinkButton;
        startButton->setTime(400);

        slotMachine = new SlotMachine(_countWheel,
                                      _countTokensInWhell);
    }

    void renderObjects() {
        slotMachine->getRenderable()->render(*this);
        startButton->getRenderable()->render(*this);
    }

    void mouseClicked(int x,int y) const
    {
        y=_h-y;
        if( (x>xPosButton && y<yPosButton) &&
                (x<xPosButton+startButtonW && y>yPosButton-startButtonH))
        {
            slotMachine->start();
        }
    }

    void keyClicked(unsigned char key){

        if(key=='g'){
            std::cout<<"Game Start"<<std::endl;
            slotMachine->start();
        }
    }

};







#endif // RENDERER_H
