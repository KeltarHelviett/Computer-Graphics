#version 450

layout (location = 0) in vec4 Position;
uniform mat4 gWorld;
out vec4 Color;

void main(void)
{
    gl_Position = Position;//vec4(Position.x, Position.y, Position.z, 1.0);//gWorld * Position;
    Color = Position;//vec4(clamp(vec3(Position.x, Position.y, Position.z), 0.0, 1.0), 1.0);
}