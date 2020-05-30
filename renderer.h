#ifndef RENDERER_H
#define RENDERER_H

#include "texture.h"

#include <GL/gl.h>

#include <iostream>
#include <cmath>

class Renderer;

class Renderable
{
public:
    Renderable(){}
    virtual ~Renderable(){}
    virtual void render(Renderer& renderer)  = 0;
};

template <typename T>
class RenderableObject
        : public Renderable
{
public:
    RenderableObject(T* object):_object(object){}

    virtual void render(Renderer& renderer)  override{
        //        std::cout<<"RENDER:"<<_object<<std::endl;
        render(renderer, _object);
    }
    virtual void render(Renderer& renderer, T* object) = 0;
    void setObject(T*object){
        _object=object;
    }
public:
    T*_object;
    //public:
    //    RenderableObject(T& object)
    //        :mObject(object) {}
    //    virtual ~RenderableObject(){}


    //protected:
    //    virtual void render(Renderer& renderer, T& object) = 0;
    //    T mObject;
};

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

    std::vector<Texture> _tokenTextures;
    Texture _txBack;

    GLfloat _marginLeft;
    GLfloat _marginRight;

    GLfloat _marginTop;
    GLfloat _marginBottom;
    int _w;
    int _h;
    Renderer(std::string &applicationDirPath,int w,int h)
    {
        _w=w;
        _h=h;

        std::string backPath=applicationDirPath+
                "/resources/images/display/back.png";

        std::string tokensDirPath=  applicationDirPath+
                "/resources/images/tokens/";

        _tokenTextures = TextureLoader::loadTextures(tokensDirPath);
        _txBack=TextureLoader::loadTexture(backPath);

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

        _tokenSize=sqrt(tokenSquare);

        _m_x1=_marginLeft;
        _m_y1=h-_marginTop;

        _spaceBetweenWheelW=_tokenSize/_countWheel-1;
        _spaceBetweenWheelH=_tokenSize/_countViewTokens-1;
        _countTokensInWhell=_tokenTextures.size();

            }

    //    void renderObjects(std::vector<Wheel>& gameObjects) {
    //        // If you want to do something fancy with the renderable GameObjects,
    //        // create a visitor class to return the list of GameObjects that
    //        // are visible instead of rendering them straight-away
    //        //        std::list<GameObject>::iterator itr = gameObjects.begin(), end = gameObjects.end();
    //        //        while (itr != end) {
    //        //            GameObject* gameObject = *itr++;
    //        //            if (gameObject == null || !gameObject->isVisible()) {
    //        //                continue;
    //        //            }
    //        //            gameObject->getRenderable()->render(*this);
    //        //        }
    //    }
};







#endif // RENDERER_H
