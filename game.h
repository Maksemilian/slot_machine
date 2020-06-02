#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "renderer_text.h"

#include "s_fps.h"

class Game
{
    static FPS _fps;

    static std::unique_ptr<Renderer> renderer;
    static std::unique_ptr<RendererText> rendererText;

    //*****CONSTANT
    static const std::string NAME_GAME;
    static const int WIDTH=800;
    static const int HEIGHT=600;

    static const unsigned short REQUIRED_FPS = 30;
    static const unsigned short TIME_MS_IN_SEC = 1000;

    static const int RENDER_TIMEOUT=TIME_MS_IN_SEC/REQUIRED_FPS;
    static const std::string CHARACTERS_FOR_TEXTURE;
public:
    Game(int argc,char** argv);

    void exec();
private:
    void initGL();

    static void renderSceneByTimer(int v);
    static void display();
    static void reshape(int w,int h);

    static void mouseClicked(int button, int state, int x, int y);
    static void keyClicked(unsigned char key,int x,int y);
};

#endif // GAME_H
