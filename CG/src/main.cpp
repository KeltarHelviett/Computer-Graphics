#include <GL/glew.h>
#include <Magick++.h>
#include "../include/Shader.h"
#include "../include/Window.h"
#include "../include/GameManager.h"

#define ToRadian(x) (float)((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

GameManager *GM;
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768


void RenderScene()
{
    GM->Render();
}

void KeyPressed(unsigned char key, int x, int y)
{
    GM->KeyPress(key, x, y);
}

void KeyUp(unsigned char key, int x, int y)
{
    GM->KeyUp(key, x, y);
}

void MouseClick(int button , int state, int x, int y)
{
    GM->MouseClick(button, state, x, y);
}

void MouseMove(int x, int y)
{
    GM->MouseMove(x, y);
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    Window w(1024, 768, 300, 300, "Window");
    glClearColor(.5f, .5f, 1.0f, 1.0f);
    glutIdleFunc(RenderScene);
    glutKeyboardUpFunc(KeyUp);
    glutKeyboardFunc(KeyPressed);
    glutMouseFunc(MouseClick);
    glutMotionFunc(MouseMove);
    GLenum res = glewInit();
    if (res != GLEW_OK)
        return 1;
//    glutGameModeString("1920x1200@64");
//    glutEnterGameMode();
    GM = new GameManager();
    GM->Init();
    glutWarpPointer(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    GM->MouseMove(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    GM->MouseMove(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    glutMainLoop();
}