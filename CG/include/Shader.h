#ifndef CG_SHADER_H
#define CG_SHADER_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <fstream>
#include <string>

class Shader
{
public:
    Shader();
    Shader(std::ifstream &shaderCode, GLenum type);
    Shader(char *shaderCode, GLenum type);
    Shader(std::string shaderCode, GLenum type);

    std::string code();
    GLenum type();
    GLuint shader();

    void compile();
protected:
    std::string _code;
    GLenum  _type;
    GLuint  _shader;
};

#endif
