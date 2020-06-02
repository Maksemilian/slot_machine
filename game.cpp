#include "game.h"
#include "s_fps.h"

#include <GL/glut.h>
#include <algorithm>

std::map<char,Character> Game::_characters;
std::unique_ptr<Renderer>Game:: renderer;
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
        w=0;
        h=0;

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

    renderer.reset(new Renderer(appDirPath));

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
    Rect rect(x,y+h,w,h);
    for(auto &ch:text)
    {
        rect.setGeometry(x,y+h,w,h);
        drawTextureRect(rect,_characters[ch]._texture);
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

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,w,0,h);
    renderer->reshape(w,h);

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
}
