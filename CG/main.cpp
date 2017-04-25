#include <GL/glew.h>
#include <GL/glut.h>
#include <Magick++.h>
#include "Shader.h"
#include "ShaderProgram.h"
#include "Window.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include "gl_math.h"
#include "Camera.h"
#include "KeyboardEventHandler.h"
#include "CameraEventHandler.h"
#include "MouseEventHandler.h"
#include "Texture.h"

#define ToRadian(x) (float)((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

struct Vertex
{
    Vec3f pos;
    Vec2f tex;

    Vertex() {}

    Vertex(const Vec3f &pos, const Vec2f &tex)
    {
        this->pos = pos;
        this->tex = tex;
    }
};

GLuint VAO;
GLuint VBO;
GLuint IBO;
GLuint gSampler;
Texture *Tex = NULL;
float Scale = 0.0f;
GLuint gWorldLocation;
Matrix4 Projection, Translation, Rotattion, MScale;
Camera Cam;
float zMove = 0.0f;
KeyboardEventHandler KEH;
CameraEventHandler CEH;
MouseEventHandler MEH;

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

void CreateVertexBuffer()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    Vertex vs[4];
    vs[0] = Vertex({-1.0f, -1.0f, 0.5773f}, {0.0f, 0.0f});
    vs[1] = Vertex({0.0f, -1.0f, -1.15475f},  {0.5f, 0.0f});
    vs[2] = Vertex({1.0f, -1.0f, 0.5773f},  {1.0f, 0.0f});
    vs[3] = Vertex({0.0f, 1.0f, 0.0f},   {0.5f, 1.0f});

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STATIC_DRAW);

    unsigned int Indices[] = { 0, 3, 1,
                               1, 3, 2,
                               2, 3, 0,
                               1, 2, 0 };
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glBindVertexArray(VAO);
}

void CreateShaders()
{
    ShaderProgram sp;
    std::ifstream fragFin("../frag.glsl");
    std::ifstream vertFin("../vert.glsl");
    Shader vert(vertFin, GL_VERTEX_SHADER);
    Shader frag(fragFin, GL_FRAGMENT_SHADER);
    vert.compile();
    frag.compile();
    sp.attachShader(vert);
    sp.attachShader(frag);
    sp.link();
    if (sp.isValid())
        sp.use();
    else
        throw std::runtime_error("Shader program is not valid");
    gSampler = (GLuint) glGetUniformLocation(sp.program(), "gSampler");
    assert(gSampler != 0xFFFFFFFF);
    gWorldLocation = (GLuint)glGetUniformLocation(sp.program(), "gWVP");
    assert(gWorldLocation != 0xFFFFFFFF);
}

Matrix4 GetRotationMatrix(float x, float y, float z)
{
    Matrix4 rx, ry, rz;

    x = ToRadian(x);
    y = ToRadian(y);
    z = ToRadian(z);

    rx[0][0] = 1.0f; rx[0][1] = 0.0f   ; rx[0][2] = 0.0f    ; rx[0][3] = 0.0f;
    rx[1][0] = 0.0f; rx[1][1] = cosf(x); rx[1][2] = -sinf(x); rx[1][3] = 0.0f;
    rx[2][0] = 0.0f; rx[2][1] = sinf(x); rx[2][2] = cosf(x) ; rx[2][3] = 0.0f;
    rx[3][0] = 0.0f; rx[3][1] = 0.0f   ; rx[3][2] = 0.0f    ; rx[3][3] = 1.0f;

    ry[0][0] = cosf(y); ry[0][1] = 0.0f; ry[0][2] = -sinf(y); ry[0][3] = 0.0f;
    ry[1][0] = 0.0f   ; ry[1][1] = 1.0f; ry[1][2] = 0.0f    ; ry[1][3] = 0.0f;
    ry[2][0] = sinf(y); ry[2][1] = 0.0f; ry[2][2] = cosf(y) ; ry[2][3] = 0.0f;
    ry[3][0] = 0.0f   ; ry[3][1] = 0.0f; ry[3][2] = 0.0f    ; ry[3][3] = 1.0f;

    rz[0][0] = cosf(z); rz[0][1] = -sinf(z); rz[0][2] = 0.0f; rz[0][3] = 0.0f;
    rz[1][0] = sinf(z); rz[1][1] = cosf(z) ; rz[1][2] = 0.0f; rz[1][3] = 0.0f;
    rz[2][0] = 0.0f   ; rz[2][1] = 0.0f    ; rz[2][2] = 1.0f; rz[2][3] = 0.0f;
    rz[3][0] = 0.0f   ; rz[3][1] = 0.0f    ; rz[3][2] = 0.0f; rz[3][3] = 1.0f;

    return rz * ry * rx;
}

Matrix4 Trans(float x, float y, float z)
{
    Matrix4 m;
    m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = x;
    m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = y;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = z;
    m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    return m;
}

void PrintLog()
{
    auto pos = Cam.Position();
    std:: cout << pos[0] << "\t" << pos[1] << "\t" << pos[2] << "\t" << std::endl;
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glBindVertexArray(VAO);

    Vec3f p = CEH.GetCameraPosition(KEH.keys(), Cam.Target(), Cam.Up(), Cam.Position());
    Matrix4 res = Cam.GetProjectionPerspectiveMatrix()  * Cam.GetUVNMatrix() * Cam.SetPosition(p[0], p[1], p[2]);

    glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, (GLfloat *)&res);
    Tex->Bind(GL_TEXTURE0);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

    glutSwapBuffers();
}

void KeyPressed(unsigned char key, int x, int y)
{
    KEH.Press(key, x, y);
}

void KeyUp(unsigned char key, int x, int y)
{
    KEH.Release(key, x, y);
}

void MouseClick(int button , int state, int x, int y)
{
    MEH.GetMouseInfo(button, state, x, y);
}

void MouseMove(int x, int y)
{
    MEH.MouseMove(x, y);
    Point angles = CEH.GetRotationAngles(MEH.Info());
    Cam.Rotate(angles);
}
int main(int argc, char *argv[])
{
    Projection = EyeMatrix4();
    Rotattion = EyeMatrix4();
    Translation = EyeMatrix4();
    MScale = EyeMatrix4();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    Window w(1024, 768, 300, 300, "Window");
    glClearColor(.0f, .0f, .0f, 0.0f);
    glutIdleFunc(RenderScene);
    glutKeyboardUpFunc(KeyUp);
    glutKeyboardFunc(KeyPressed);
    glutMouseFunc(MouseClick);
//    glutPassiveMotionFunc(MouseMove);
    glutMotionFunc(MouseMove);
    // glutDisplayFunc(RenderScene);
    GLenum res = glewInit();
    if (res != GLEW_OK)
        return 1;
    CreateVertexBuffer();
    CreateShaders();
    glutGameModeString("1920x1200@64");
    glutEnterGameMode();
    glutWarpPointer(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    MEH.MouseMove(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    MEH.MouseMove(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    glUniform1i(gSampler, 0);
    Tex = new Texture(GL_TEXTURE_2D, "../rsc/stone2.jpg");
    if (!Tex->Load())
        return 1;
    glutMainLoop();
}