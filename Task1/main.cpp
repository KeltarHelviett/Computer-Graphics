#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>


GLuint Triangle;
GLuint ShaderProg;

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
    glGenBuffers(3, &Triangle);
    glBindBuffer(GL_ARRAY_BUFFER, Triangle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STATIC_DRAW);
}

void AttachShader(const char *shaderCode, GLenum type)
{
    GLuint shader = glCreateShader(type);
    std::cout << shaderCode;
    const GLchar *c[1];
    c[0] = shaderCode;
    GLint lengths[1];
    lengths[0] = (GLint)strlen(shaderCode);
    glShaderSource(shader, 1, c, lengths);
    glAttachShader(ShaderProg, shader);
}
void CreateShaders()
{
    ShaderProg = glCreateProgram();
    std::ifstream fragFin("../frag.glsl");
    std::ifstream vertFin("../vert.glsl");
    std::string fragShaderCode {std::istreambuf_iterator<char>(fragFin), std::istreambuf_iterator<char>()},
            vertShaderCode{std::istreambuf_iterator<char>(vertFin), std::istreambuf_iterator<char>()};
    AttachShader((char *) fragShaderCode.c_str(), GL_FRAGMENT_SHADER);
    AttachShader((char *) vertShaderCode.c_str(), GL_VERTEX_SHADER);
    glLinkProgram(ShaderProg);
    glValidateProgram(ShaderProg);
    glUseProgram(ShaderProg);
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, Triangle);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(1);

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Task 1");
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