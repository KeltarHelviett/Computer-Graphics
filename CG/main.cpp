#include <GL/glew.h>
#include <GL/glut.h>
#include "Shader.h"
#include "ShaderProgram.h"
#include "Window.h"
#include <iostream>

GLuint VAO;
GLuint VBO;

struct Vector3D
{
    Vector3D() {}
    Vector3D(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    float x, y, z;
};

void CreateVertexBuffer()
{
    Vector3D vs[3];
    vs[0] = Vector3D(-1.0f, 0.0f, 0.0f);
    vs[1] = Vector3D(1.0f, 0.0f, 0.0f);
    vs[2] = Vector3D(0.0f, 1.0f, 0.0f);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
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
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    Window w(800, 600, 300, 300, "Window");
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glutDisplayFunc(RenderScene);
    GLenum res = glewInit();
    if (res != GLEW_OK)
        return 1;
    CreateVertexBuffer();
    CreateShaders();
    glutMainLoop();
    return 0;
}