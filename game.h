#ifndef GAME_H
#define GAME_H

#include "go_wheel.h"
#include "s_fps.h"
#include <GL/gl.h>

class Game
{
    static FPS _fps;
    //*****CONSTANT

    static const std::string NAME_GAME;
    static const int WIDTH=800;
    static const int HEIGHT=600;

    static const unsigned short REQUIRED_FPS = 30;
    static const unsigned short TIME_MS_IN_SEC = 1000;

    static constexpr float RENDER_TIMEOUT=TIME_MS_IN_SEC/REQUIRED_FPS;
    static const std::string PATH_TO_FONT;
    static const std::string CHARACTERS_FOR_TEXTURE;
public:
    Game(int argc,char** argv);

    void exec();
private:
    void initGL();

    static void renderText(const std::string &text,
                           GLfloat x,GLfloat y,GLfloat w,GLfloat h);

    //**********
    static void renderSceneByTimer(int v);
    static void display();
    static void reshape(int w,int h);

    static void mouseClicked(int button, int state, int x, int y);
    static void keyClicked(unsigned char key,int x,int y);
};

#endif // GAME_H
