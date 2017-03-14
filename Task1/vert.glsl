#version 450

layout (location = 1) in vec3 Position;

void main(void)
{
    gl_Position = vec4(Position.x, Position.y, Position.z, 1.0);
}
