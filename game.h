#ifndef GAME_H
#define GAME_H

#include "go_wheel.h"
#include "fps.h"
#include <GL/gl.h>

class Game
{
    static int _w;
    static int _h;
    static FPS _fps;

    //*****CONSTANT

    static const int MIN_WHEEL_SPEED=50;
    static const int MAX_WHEEL_SPEED=200;


    static const int TOKEN_COUNT=3;

    static const unsigned short REQUIRED_FPS = 30;
    static const unsigned short TIME_MS_IN_SEC = 1000;
    static constexpr float RENDER_TIMEOUT=TIME_MS_IN_SEC/REQUIRED_FPS;

public:
    Game(const std::string &applicationDirPath,int w,int h);
    void exec();
private:
    void init();
    static void spin();
    static void idle(int v);

    static void renderText(const std::string &text,
                           GLfloat x,GLfloat y,GLfloat w,GLfloat h);
    static void loadAllTexture();

    static void buttonTimer(int value);

    //**********
    static void display();
    static void reshape(int w,int h);

    static void mouseClicked(int button, int state, int x, int y);
    static void keyClicked(unsigned char key,int x,int y);
private:
};

#endif // GAME_H
