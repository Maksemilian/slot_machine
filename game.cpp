#include "game.h"

#include "go_slot_machine.h"
#include "renderer.h"

#include "fps.h"

#include "font.h"
#include "button.h"

#include "texture.h"

#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <algorithm>

GLfloat _windowWidth=100;
GLfloat _windowHeight=100;


std::map<char,Character>_characters;

Texture textureActiveButton;
Texture textureButton;

Renderer *renderer;
SlotMachine *slotMachine;
Button *button;

//****** STATIC VARIBLE GAME

int Game::_w;
int Game::_h;

FPS Game::_fps;
std::string Game::appDirPath="./";

//***CONSTANT
const std::string Game::PATH_TO_TEXTURE[]={
    "/resources/arial.ttf",
    "/resources/images/display/btn1.png",
    "/resources/images/display/btn2.png",
    "/resources/images/display/back_3.png"
};

const std::string Game::NAME_GAME="SlotGame";
const std::string Game::CHARACTERS_FOR_TEXTURE="FPS:.1234567890";

Game::Game(int argc,char** argv)
{
    std::string applicationDirPath(argv[0]);

#ifdef WIN32
    std::replace(applicationDirPath.begin(),applicationDirPath.end(),'\\','/');
#endif
    applicationDirPath.erase(applicationDirPath.find_last_of('/'));
    std::cout<<"APP_PATH:"<<applicationDirPath<<std::endl;

    if(argc==1){
        _w=WIDTH;
        _h=HEIGHT;
    }else{
        //TODO сделать обработку аргументов w h
    }
    _windowWidth=_w;
    _windowHeight=_h;

    appDirPath=applicationDirPath;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(_w,_h);
    //TODO 100 100
    glutInitWindowPosition(0,0);
    glutCreateWindow(NAME_GAME.data());

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(RENDER_TIMEOUT,renderSceneByTimer,0);
    //TODO 100
    glutTimerFunc(100,buttonTimer,true);

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

void Game::init()
{
    //load textures
    std::string buttonActivePath=appDirPath+PATH_TO_TEXTURE[1];

    std::string buttonPath=appDirPath+PATH_TO_TEXTURE[2];

    std::string backPath=appDirPath+PATH_TO_TEXTURE[3];


    textureActiveButton=TextureLoader::loadTexture(buttonActivePath);
    textureButton=TextureLoader::loadTexture(buttonPath);

    std::string pathToFont=appDirPath+PATH_TO_TEXTURE[0];
    _characters=getTexturesOfCharacters(CHARACTERS_FOR_TEXTURE,
                                        pathToFont);


    //********GUI

    GLfloat startButtonW=_w*12/100;
    GLfloat startButtonH=startButtonW;

    GLfloat x=_w-startButtonW;
    GLfloat y=startButtonH;

    button=new Button(textureActiveButton,
                      x,y,startButtonW,startButtonH);
    button->setGeometry(x,y,startButtonW,startButtonH);

    //*********GAME
    renderer=new Renderer(appDirPath,_w,_h);

    slotMachine = new SlotMachine(renderer->_countWheel,
                                  renderer->_countTokensInWhell);

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

// ***************** GLUT TIMERS ******************

//*****GUI

void Game::buttonTimer(int value)
{
    if(value)
    {
        button->setTexture(textureActiveButton);
    }
    else
    {
        button->setTexture(textureButton);
    }
    //TODO 400
    glutTimerFunc(400,buttonTimer,!value);
}

//************************* DRAW *********************

void Game::display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    slotMachine->getRenderable()->render(*renderer);

    button->draw();
    _fps.CalculateFrameRate();

    std::string text="FPS:"+std::to_string(_fps.fps());
    renderText(text,0,0,32,32);
    glutSwapBuffers();
}

void Game::reshape(int w, int h)
{
    //        std::cout<<"res"<<std::endl;
    GLfloat aspectRatio;
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspectRatio = (GLfloat)w / (GLfloat)h;
//    std::cout<<"IF"<<"w:"<<w<<"h:"<<h<<std::endl;
    _windowWidth = w;
    _windowHeight = h;
    //

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
    int ViewportWidth=_w;
    int ViewportHeight=_h;

    GLfloat aspectX = (GLfloat)ViewportWidth / _windowWidth;
    GLfloat aspectY = (GLfloat)ViewportHeight / _windowHeight;

    GLfloat MouseViewportX = (GLfloat) x / aspectX;
    GLfloat MouseViewportY =  (GLfloat) (ViewportHeight-y) / aspectY;
    if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(::button->containsPoint(MouseViewportX,MouseViewportY)){
//            std::cout<<"M("<<x<<","<<y<<")"
//                    <<"B("<<MouseViewportX<<","<<MouseViewportY<<")"
//                   <<"Is Cliecked:"
//                  <<::button->containsPoint(MouseViewportX,MouseViewportY)<<std::endl;
            slotMachine->start();
        }else{
//            std::cout<<x<<" "<<y<<std::endl;
        }
    }
}

void Game::keyClicked(unsigned char key, int x, int y)
{
    //    if(key==GLUT_KEY_INSERT)
    if(key=='g')
    {
        std::cout<<"Game Start"<<std::endl;
        slotMachine->start();
    }
    else
    {
        std::cout<<key<<std::endl;
    }
}

//************** del

//Game::Game(const std::string &applicationDirPath,int w,int h)
//{
//    appDirPath=applicationDirPath;
//    _w=w;
//    _h=h;
//    char *argv[] = {"GameSlot"};
//    int argc = 1;

//    glutInit(&argc,argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(w,h);
//    glutInitWindowPosition(100,100);
//    glutCreateWindow("Slot Machine");

//    init();
//    std::string pathToFont=appDirPath+PATH_TO_TEXTURE[0];
//    _characters=getTexturesOfCharacters(CHARACTERS_FOR_TEXTURE,
//                                        pathToFont);
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);

//    glutTimerFunc(RENDER_TIMEOUT,idle,0);
//    glutTimerFunc(100,buttonTimer,true);

//    glutMouseFunc(mouseClicked);
//    glutKeyboardFunc(keyClicked);
//}

/*
std::vector<TokenWindget>Game::createTokensForWheel(
        const std::vector<GLuint> &textures,GLfloat w,GLfloat h)
{
    std::vector<TokenWindget> tokens;
    for(auto texture: textures)
    {
        tokens.push_back({texture,w,h});
    }
    return  tokens;
}
GLfloat marginTop=_h*12/100;
GLfloat marginBottom=_h*40/100;

GLfloat marginLeft=_w*18/100;
GLfloat marginRight=marginLeft;

GLfloat tokenFieldW=_w-marginLeft-marginRight;
GLfloat tokenFieldH=_h-marginTop-marginBottom;

GLfloat tokenH=tokenFieldH/3;
//    GLfloat tokenW=tokenFieldW/5;
GLfloat tokenW=tokenH;
GLfloat otherSpace=tokenFieldW-tokenW*5;
GLfloat tokenFieldSquare=tokenFieldW*tokenFieldH;
GLfloat spaceBetwenTokens=(tokenFieldW/_countWheel)*tokenFieldH;

GLfloat tokenSquare=(tokenFieldSquare-spaceBetwenTokens)/
        (_countWheel*_countViewTokens);

GLfloat tokenSize=sqrt(tokenSquare);

std::vector<TokenWindget> tokens=createTokensForWheel(_tokenTextures,
                                               tokenSize,
                                               tokenSize);

m_x1=marginLeft;
m_y1=_h-marginTop;

GLfloat spaceBetweenWheelW=tokenSize/_countWheel-1;
GLfloat spaceBetweenWheelH=tokenSize/_countViewTokens-1;


for(int i=0;i<_countWheel;++i)
{
    _wheels.push_back({m_x1,
                       m_y1,
                       _countViewTokens,tokens});

    _wheels[i].setSpeed(getRandomNumber(MIN_WHEEL_SPEED,MAX_WHEEL_SPEED));
    _wheels[i].setTest(spaceBetweenWheelH);

    m_x1+=tokenSize+spaceBetweenWheelW;
}
*/
//void Game::stopSpeenWheel(int wheelIndex)
//{
//    if(_timer.elapsed()<TIME_STOP_WHEEL)
//    {
//        glutTimerFunc(0,stopSpeenWheel,0);  //запускаем таймер заново.
//    }
//    else  if(wheelIndex<_wheels.size())
//    {
//        _wheels[wheelIndex].stop();
//        glutTimerFunc(1000,stopSpeenWheel,wheelIndex+1);  //запускаем таймер заново.
//    }
//}

//void Game::startSpinWheel(int wheelIndex)
//{
//    for(size_t i=0;i<_wheels.size();i++)
//    {
//        _wheels[i].start();
////        glutTimerFunc(_wheels[i].getSpeed(),
////                      spinWheel,i);  //запускаем таймер заново.
//    }
//    _timer.reset();
//    glutTimerFunc(0,stopSpeenWheel,wheelIndex+1);  //запускаем таймер заново.
//}



//void Game::spinWheel(int wheelIndex)
//{
////    cout<<"Tomer"<<timer.elapsed()<<endl;
//    _wheels[wheelIndex].spin();
//    if(!_wheels[wheelIndex].isStop())
//        glutTimerFunc(_wheels[wheelIndex].getSpeed(),spinWheel,wheelIndex);  //запускаем таймер заново.
//}

/*
void Game::startSpinWheel(int wheelIndex)
{
    _wheels[wheelIndex].resetTimeSpin();
    glutTimerFunc(_wheels[wheelIndex].getSpeed(),spinWheel,wheelIndex);  //запускаем таймер заново.
    if(wheelIndex<_countWheel-1)
    {
        GLuint _timeStartWheel=500;
        std::cout<<"started"<<wheelIndex<<std::endl;
        glutTimerFunc(_timeStartWheel,startSpinWheel,wheelIndex+1);  //запускаем таймер заново.
    }
}



void Game::spinWheel(int wheelIndex){

    _wheels[wheelIndex].spin();
    glutPostRedisplay();  // перерисовываем экран
    if(_wheels[wheelIndex].currentTimeSpin()<TIME_STOP_WHEEL){
        glutTimerFunc(_wheels[wheelIndex].getSpeed(),spinWheel,wheelIndex);  //запускаем таймер заново.
    }
}
*/
