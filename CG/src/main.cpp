#include <GL/glew.h>
#include <Magick++.h>
#include "../include/Shader.h"
#include "../include/ShaderProgram.h"
#include "../include/Window.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include "../include/gl_math.h"
#include "../include/Camera.h"
#include "../include/KeyboardEventHandler.h"
#include "../include/CameraEventHandler.h"
#include "../include/MouseEventHandler.h"
#include "../include/Texture.h"
#include "../include/Light.h"
#include <GL/glut.h>

#define ToRadian(x) (float)((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

struct Vertex
{
    Vec3f pos;
    Vec2f tex;
    Vec3f normal;

    Vertex() {}

    Vertex(const Vec3f &pos, const Vec2f &tex)
    {
        this->pos = pos;
        this->tex = tex;
        normal    = {0.0f, 0.0f, 0.0f};
    }
};

GLuint VAO;
GLuint VBO;
GLuint IBO;
GLuint Sampler;
GLuint DLColor;
GLuint DLIntens;
GLuint DLDiffuse;
GLuint DLDirection;
Texture *Tex = NULL;
float Scale = 0.0f;
GLuint WVP;
GLuint WorldTrans;
Matrix4 Projection, Translation, Rotattion, MScale;
Camera Cam;
float zMove = 0.0f;
KeyboardEventHandler KEH;
CameraEventHandler CEH;
MouseEventHandler MEH;
DirectionalLight dl({1.0f, 1.0f, 1.0f}, 1.0f, {1.0f, 0.0f, 0.0f}, 0.5f);

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

void CalcNormals(const unsigned int* Indices, unsigned int IndexCount, Vertex* Vertices, unsigned int VertexCount)
{
    for (unsigned int i = 0 ; i < IndexCount ; i += 3) {
        unsigned int Index0 = Indices[i];
        unsigned int Index1 = Indices[i + 1];
        unsigned int Index2 = Indices[i + 2];
        Vec3f v1 = Vertices[Index1].pos - Vertices[Index0].pos;
        Vec3f v2 = Vertices[Index2].pos - Vertices[Index0].pos;
        Vec3f Normal = v1.Cross(v2);
        Normal.Normalize();

        Vertices[Index0].normal += Normal;
        Vertices[Index1].normal += Normal;
        Vertices[Index2].normal += Normal;
    }

    for (unsigned int i = 0 ; i < VertexCount ; i++) {
        Vertices[i].normal.Normalize();
        //std::cout << Vertices[i].normal[0] << "\t" << Vertices[i].normal[1] << "\t" << Vertices[i].normal[2] << std::endl;
        auto v = -dl.Direction() * Vertices[i].normal;
        std::cout << v << std::endl;
    }
}

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
    CalcNormals(Indices, sizeof(Indices) / sizeof(Indices[0]), vs, sizeof(vs) / sizeof(vs[0]));
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);

    glBindVertexArray(VAO);
}

void CreateShaders()
{
    ShaderProgram sp;
    std::ifstream fragFin("../shaders/fragment/frag.glsl");
    std::ifstream vertFin("../shaders/vertex/vert.glsl");
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
    Sampler = (GLuint) glGetUniformLocation(sp.program(), "Sampler");
    assert(Sampler != 0xFFFFFFFF);
    WVP = (GLuint)glGetUniformLocation(sp.program(), "WVP");
    assert(WVP != 0xFFFFFFFF);
    DLColor = (GLuint) glGetUniformLocation(sp.program(), "directionalLight.Color");
    assert(DLColor!= 0xFFFFFFFF);
    DLIntens = (GLuint) glGetUniformLocation(sp.program(), "directionalLight.AmbientIntensity");
    assert(DLIntens != 0xFFFFFFFF);
    DLDiffuse = (GLuint) glGetUniformLocation(sp.program(), "directionalLight.DiffuseIntensity");
    assert(DLDiffuse != 0xFFFFFFFF);
    DLDirection = (GLuint) glGetUniformLocation(sp.program(), "directionalLight.Direction");
    assert(DLDirection != 0xFFFFFFFF);
    WorldTrans = (GLuint) glGetUniformLocation(sp.program(), "World");
    assert(WorldTrans != 0xFFFFFFFF);

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
    Matrix4 world = EyeMatrix4();

    glUniformMatrix4fv(WVP, 1, GL_TRUE, (GLfloat *)&res);
    glUniformMatrix4fv(WorldTrans, 1, GL_TRUE, (GLfloat *)&world);
    glUniform3f(DLColor, dl.Color()[0], dl.Color()[1], dl.Color()[2]);
    Vec3f Direction = dl.Direction();
    Direction.Normalize();
    glUniform3f(DLDirection, Direction[0], Direction[1], Direction[2]);
    glUniform1f(DLDiffuse, dl.DiffuseIntensity());
    glUniform1f(DLIntens, dl.AmbientIntensity());
    glUniform1i(Sampler, 0);
    Tex->Bind(GL_TEXTURE0);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

    glutSwapBuffers();
}

void KeyPressed(unsigned char key, int x, int y)
{
    if (key == 'o')
        dl.AmbientIntensity() += 0.05;
    if (key == 'p')
        dl.AmbientIntensity() -= 0.05;

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
    Tex = new Texture(GL_TEXTURE_2D, "../rsc/stone2.jpg");
    if (!Tex->Load())
        return 1;
    glutMainLoop();
}