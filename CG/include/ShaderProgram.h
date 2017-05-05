#ifndef CG_SHADERPROGRAM_H
#define CG_SHADERPROGRAM_H



#include "Shader.h"
#include <GL/glew.h>

class ShaderProgram
{
public:
    ShaderProgram();

    GLuint program();

    void attachShader(Shader shader);
    void link();
    void use();
    bool isValid();
private:
    GLuint _program;
};


#endif
