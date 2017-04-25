#version 450
in vec2 TexCoord0;
out vec4 FragColor;
uniform sampler2D gSampler;
void main()
{
//    FragColor = vec4(TexCoord0.x, TexCoord0.y, 0.0, 1.0);
    FragColor = texture2D(gSampler, TexCoord0.xy);
}
