//
// Created by keltar on 3/10/17.
//

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
    _program = glCreateProgram();
}

GLuint ShaderProgram::program()
{
    return _program;
}

void ShaderProgram::attachShader(Shader shader)
{
    glAttachShader(_program, shader.shader());
}

void ShaderProgram::link()
{
    glLinkProgram(_program);
#ifndef NDEBUG
    GLint res;
    glGetProgramiv(_program, GL_LINK_STATUS, &res);
    if (res == 0)
    {
        GLchar infoLog[1024];
        glGetProgramInfoLog(_program, sizeof(infoLog), NULL, infoLog);
        fprintf(stderr, "Error linking shader program: '%s'\n", infoLog);
    }
#endif
}

void ShaderProgram::use()
{
    glUseProgram(_program);
}

bool ShaderProgram::isValid()
{
    glValidateProgram(_program);
#ifndef NDEBUG
    GLint res;
    glGetProgramiv(_program, GL_VALIDATE_STATUS, &res);
    if (res == 0)
    {
        GLchar infoLog[1024];
        glGetProgramInfoLog(_program, sizeof(infoLog), NULL, infoLog);
        fprintf(stderr, "Error linking shader program: '%s'\n", infoLog);
        return false;
    }
    return true;
#endif
}
