#include "game.h"

#include "renderer.h"
#include "widget.h"

#include "fps.h"

#include "font.h"

#include <GL/glut.h>
#include <algorithm>

std::map<char,Character>_characters;

Renderer *renderer;

//****** STATIC VARIBLE GAME

FPS Game::_fps;

const std::string Game::NAME_GAME="SlotGame";
const std::string Game::CHARACTERS_FOR_TEXTURE="FPS:.1234567890";
const std::string Game::PATH_TO_FONT="/resources/arial.ttf";

Game::Game(int argc,char** argv)
{
    std::string appDirPath(argv[0]);

#ifdef WIN32
    std::replace(appDirPath.begin(),appDirPath.end(),'\\','/');
#endif
    appDirPath.erase(appDirPath.find_last_of('/'));
    std::cout<<"APP_PATH:"<<appDirPath<<" MS"<<TIME_MS<<std::endl;
    int w,h;
    if(argc==1){
        w=WIDTH;
        h=HEIGHT;
    }else{
        //TODO сделать обработку аргументов w h
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w,h);
    //TODO 100 100
    glutInitWindowPosition(0,0);
    glutCreateWindow(NAME_GAME.data());

    initGL();
    _characters=getTexturesOfCharacters(CHARACTERS_FOR_TEXTURE,
                                       appDirPath+PATH_TO_FONT);

    renderer=new Renderer(appDirPath,w,h);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(RENDER_TIMEOUT,renderSceneByTimer,0);

    glutMouseFunc(mouseClicked);
    glutKeyboardFunc(keyClicked);
}

void Game::exec()
{
    _fps.reset();
    glutMainLoop();
}

void Game::renderSceneByTimer(int v)
{
    glutPostRedisplay();
    glutTimerFunc(RENDER_TIMEOUT,renderSceneByTimer,v);
}

void Game::initGL()
{
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0,0.0,0.0,0.0);
}

void Game::renderText(const std::string &text,
                      GLfloat x, GLfloat y,
                      GLfloat w, GLfloat h)
{
    for(auto &ch:text)
    {
        Widget token(_characters[ch]._texture,w,h);
        token.setGeometry(x,y+h,w,h);
        token.draw();
        x+=w;
    }
}

void Game::display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderer->renderObjects();
    _fps.CalculateFrameRate();

    std::string text="FPS:"+std::to_string(_fps.fps());
    renderText(text,0,0,32,32);
    glutSwapBuffers();
}

void Game::reshape(int w, int h)
{
    GLfloat aspectRatio;
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspectRatio = (GLfloat)w / (GLfloat)h;

    gluOrtho2D(0,w,0,h);

    //    aspectRatio = (GLfloat)w / (GLfloat)h;
    //    if (w <= h){
    //        _windowWidth = w;
    //        _windowHeight = h / aspectRatio;
    //        glOrtho(-w,w,-_windowHeight,_windowHeight,1.0,-1.0);
    //    } else {
    //        _windowWidth = w * aspectRatio;
    //        _windowHeight = h;
    //        glOrtho(-_windowWidth,_windowWidth,-h,h,1.0,-1.0);
    //    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//******************* MOUSE AND KEYBOARD

void Game::mouseClicked(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        renderer->mouseClicked(x,y);
    }
}

void Game::keyClicked(unsigned char key, int x, int y)
{
        renderer->keyClicked(key);
        std::cout<<x<<" "<<y<<std::endl;
}
