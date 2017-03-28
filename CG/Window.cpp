
#include "Window.h"

Window::Window() {}

Window::Window(GLuint width, GLuint height, GLuint x, GLuint y, std::string title): _width(width), _heigth(height), _position(x, y)
{
    glutInitWindowPosition(_position.x, _position.y);
    glutInitWindowSize(_width, _heigth);
    glutCreateWindow(title.c_str());
}

Window::Window(GLuint width, GLuint height, GLuint y, GLuint x, char *title): Window(width, height, y, x, std::string(title)) {}


GLuint Window::width()
{
    return _width;
}

GLuint Window::heigth()
{
    return _heigth;
}

Position Window::position()
{
    return _position;
}



Position::Position(GLint _x, GLint _y)
{
    x = _x;
    y = _y;
}

Position::Position() {}
