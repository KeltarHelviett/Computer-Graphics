#version 450

in vec2 TexCoord0;
in vec3 Normal0;

out vec4 FragColor;

struct DirectionalLight
{
    vec3 Color;
    float AmbientIntensity;
    vec3 Direction;
    float DiffuseIntensity;
};
uniform DirectionalLight directionalLight;
uniform sampler2D Sampler;
void main()
{
    vec4 AmbientColor = vec4(directionalLight.Color, 1.0f) *
                        directionalLight.AmbientIntensity;
    float DiffuseFactor = dot(normalize(Normal0), -directionalLight.Direction);
    vec4 DiffuseColor;
    if (DiffuseFactor > 0)
    {
        DiffuseColor = vec4(directionalLight.Color, 1.0f) *
                       directionalLight.DiffuseIntensity *
                       DiffuseFactor;
    }
    else
    {
        DiffuseColor = vec4(0,0,0,0);
    }
    FragColor = texture2D(Sampler, TexCoord0.xy) *
                (AmbientColor + DiffuseColor);
}