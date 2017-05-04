#ifndef CG_WINDOW_H
#define CG_WINDOW_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdint>
#include <string>

struct Position
{
    GLint x, y;
    Position();
    Position(GLint _x, GLint _y);
};

class Window
{
public:
    Window();
    Window(GLuint width, GLuint height, GLuint y, GLuint x, std::string title);
    Window(GLuint width, GLuint height, GLuint y, GLuint x, char *title);

    GLuint width();
    GLuint heigth();
    Position position();
private:
    GLuint _width, _heigth;
    Position _position;
};


#endif
