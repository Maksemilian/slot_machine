#include "game.h"

#include <GL/glut.h>
#include <algorithm>

#define UNUSED(P) {(P) = (P);}

std::unique_ptr<Renderer>Game:: renderer;
std::unique_ptr<RendererText>Game::rendererText;

FPS Game::_fps;

const std::string Game::NAME_GAME = "SlotGame";
const std::string Game::CHARACTERS_FOR_TEXTURE = "FPS:.1234567890";

Game::Game(int argc, char** argv)
{
    std::string appDirPath(argv[0]);

#ifdef WIN32
    std::replace(appDirPath.begin(), appDirPath.end(), '\\', '/');
#endif
    appDirPath.erase(appDirPath.find_last_of('/'));

    int w = WIDTH;
    int h = HEIGHT;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(NAME_GAME.data());

    initGL();

    renderer.reset(new Renderer(appDirPath));
    //символы FPS имеют размер 5 % от W и H
    int characterW = w * 5 / 100;
    int characterH = h * 5 / 100;

    rendererText.reset(new RendererText(appDirPath,
                                        CHARACTERS_FOR_TEXTURE,
                                        static_cast<unsigned int>(characterW),
                                        static_cast<unsigned int>(characterH)));

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(RENDER_TIMEOUT, renderSceneByTimer, 0);

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
    glutTimerFunc(RENDER_TIMEOUT, renderSceneByTimer, v);
}

void Game::initGL()
{
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Game::display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderer->renderObjects();
    _fps.CalculateFrameRate();

    std::string text = "FPS:" + std::to_string(_fps.fps());
    rendererText->render(text, 0, 0);
    glutSwapBuffers();
}

void Game::reshape(int w, int h)
{

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, w, 0, h, 1.0, -1.0);

    //символы FPS имеют размер 5 % от W и H
    int characterW = w * 5 / 100;
    int characterH = h * 5 / 100;

    renderer->reshape(w, h);
    rendererText->reshape(characterW, characterH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Game::mouseClicked(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        renderer->mouseClicked(x, y);
    }
}

void Game::keyClicked(unsigned char key, int x, int y)
{
    UNUSED(x);
    UNUSED(y);
    renderer->keyClicked(key);
}
