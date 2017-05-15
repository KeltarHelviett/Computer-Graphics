#version 450

const int MAX_POINT_LIGHTS = 9;
const int MAX_SPOT_LIGHTS = 9;

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

struct SpotLight
{
    PointLight Base;
    vec3 Direction;
    float Cutoff;
};

uniform int NumPointLights;
uniform int NumSpotLights;
uniform DirectionalLight directionalLight;
uniform PointLight PointLights[MAX_POINT_LIGHTS];
uniform SpotLight SpotLights[MAX_SPOT_LIGHTS];
uniform sampler2D Sampler;
uniform vec3 Cam;

vec4 CalcLightInternal(BaseLight Light, vec3 LightDirection, vec3 Normal)
{
    vec4 AmbientColor = vec4(Light.Color, 1.0f) * Light.AmbientIntensity;
    float DiffuseFactor = dot(Normal, -LightDirection);

    vec4 DiffuseColor  = vec4(0, 0, 0, 0);

    if (DiffuseFactor > 0) {
        DiffuseColor = vec4(Light.Color, 1.0f) * Light.DiffuseIntensity * DiffuseFactor;
    }

    return (AmbientColor + DiffuseColor);
}

vec4 CalcDirectionalLight(vec3 Normal)
{
    return CalcLightInternal(directionalLight.Base, directionalLight.Direction, Normal);
}

vec4 CalcPointLight( PointLight l, vec3 Normal)
{
    vec3 LightDirection = WorldPos0 - l.Position;
    float Distance = length(LightDirection);
    LightDirection = normalize(LightDirection);

    vec4 Color = CalcLightInternal(l.Base, LightDirection, Normal);
    float Attenuation =  l.Atten.Constant +
                         l.Atten.Linear * Distance +
                         l.Atten.Exp * Distance * Distance;

    return Color / Attenuation;
}

vec4 CalcSpotLight( SpotLight l, vec3 Normal)
{
    vec3 LightToPixel = normalize(WorldPos0 - l.Base.Position);
    float SpotFactor = dot(LightToPixel, normalize(l.Direction));

    if (SpotFactor > l.Cutoff) {
        vec4 Color = CalcPointLight(l.Base, Normal);
        return Color * (1.0 - (1.0 - SpotFactor) * 1.0/(1.0 - l.Cutoff));
    }
    else {
        return vec4(0,0,0,0);
    }
}

void main()
{
    vec3 Normal = normalize(Normal0);
    vec4 TotalLight = CalcDirectionalLight(Normal);

    for (int i = 0 ; i < NumPointLights ; i++) {
        TotalLight += CalcPointLight(PointLights[i], Normal);
    }

    for (int i = 0 ; i < NumSpotLights ; i++) {
        TotalLight += CalcSpotLight(SpotLights[i], Normal);
    }

    FragColor = texture2D(Sampler, TexCoord0.xy) * TotalLight;
}