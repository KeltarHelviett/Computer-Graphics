
#include "Shader.h"

Shader::Shader() {}

Shader::Shader(std::ifstream &shaderCode, GLenum type): Shader(std::string(std::istreambuf_iterator<char>(shaderCode),
                                                                           std::istreambuf_iterator<char>()), type)
{}

Shader::Shader(char *shaderCode, GLenum type): Shader(std::string(shaderCode), type) {}

Shader::Shader(std::string shaderCode, GLenum type): _type(type), _code(shaderCode)
{
    _shader = glCreateShader(type);
    const GLchar *c[1] = {shaderCode.c_str()};
    GLint l[1] = {(GLint)shaderCode.size()};
    glShaderSource(_shader, 1, c, l);
}

std::string Shader::code()
{
    return _code;
}

GLenum Shader::type()
{
    return _type;
}

GLuint Shader::shader()
{
    return _shader;
}

void Shader::compile()
{
    glCompileShader(_shader);
    GLint res;
#ifndef NDEBUG
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &res);
    if (!res)
    {
        GLchar infoLog[1024];
        glGetShaderInfoLog(_shader, sizeof(infoLog), NULL, infoLog);
        fprintf(stderr, "Error compiling shader : '%s'\n", infoLog);
    }
#endif
}
