#version 450

const int MAX_POINT_LIGHTS = 10;

in vec2 TexCoord0;
in vec3 Normal0;
in vec3 WorldPos0;

out vec4 FragColor;

struct BaseLight
{
    vec3 Color;
    float AmbientIntensity;
    float DiffuseIntensity;
};

struct DirectionalLight
{
    BaseLight Base;
    vec3 Direction;
};

struct Attenuation
{
    float Constant;
    float Linear;
    float Exp;
};

struct PointLight
{
    BaseLight Base;
    vec3 Position;
    Attenuation Atten;
};


uniform vec3 Cam;
uniform int NumPointLights;
uniform DirectionalLight directionalLight;
uniform PointLight PointLights[MAX_POINT_LIGHTS];
uniform sampler2D Sampler;


vec4 CalcLightInternal(BaseLight Light, vec3 LightDirection, vec3 Normal)
{
    vec4 AmbientColor = vec4(Light.Color, 1.0f) * Light.AmbientIntensity;
    float DiffuseFactor = dot(Normal, -LightDirection);

    vec4 DiffuseColor  = vec4(0, 0, 0, 0);

    if (DiffuseFactor > 0) {
        DiffuseColor = vec4(Light.Color, 1.0f) * Light.DiffuseIntensity * DiffuseFactor;

        vec3 VertexToEye = normalize(Cam - WorldPos0);
        vec3 LightReflect = normalize(reflect(LightDirection, Normal));
    }

    return (AmbientColor + DiffuseColor);
}

vec4 CalcDirectionalLight(vec3 Normal)
{
    return CalcLightInternal(directionalLight.Base, directionalLight.Direction, Normal);
}

vec4 CalcPointLight(int Index, vec3 Normal)
{
    vec3 LightDirection = WorldPos0 - PointLights[Index].Position;
    float Distance = length(LightDirection);
    LightDirection = normalize(LightDirection);

    vec4 Color = CalcLightInternal(PointLights[Index].Base, LightDirection, Normal);
    float Attenuation =  PointLights[Index].Atten.Constant +
                         PointLights[Index].Atten.Linear * Distance +
                         PointLights[Index].Atten.Exp * Distance * Distance;

    return Color / Attenuation;
}

void main()
{
    vec3 Normal = normalize(Normal0);
    vec4 TotalLight = CalcDirectionalLight(Normal);

    for (int i = 0 ; i < NumPointLights ; i++) {
        TotalLight += CalcPointLight(i, Normal);
    }

    FragColor = texture2D(Sampler, TexCoord0.xy) * TotalLight;
}