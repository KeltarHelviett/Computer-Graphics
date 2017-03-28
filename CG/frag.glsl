#version 450

out vec4 fragColor;
in vec4 Color;

void main(void)
{
    fragColor = Color;
}
