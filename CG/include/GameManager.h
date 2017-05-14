//
// Created by keltar on 5/14/17.
//

#ifndef CG_GAMEMANAGER_H
#define CG_GAMEMANAGER_H

#include <GL/glew.h>
#include "Model.h"
#include "Light.h"
#include "Camera.h"
#include "MouseEventHandler.h"
#include "KeyboardEventHandler.h"
#include "CameraEventHandler.h"
#include "ShaderProgram.h"
#include <cassert>

struct DirectionalLightUniform
{
    GLuint color, intense, diffuse, direction;
    DirectionalLightUniform() {}
};

struct PointLightUniform
{
    GLuint color, ambientIntensity, position, diffuseIntensity, constant, linear, exp;
    PointLightUniform() {}
};


class GameManager
{
public:
    GameManager();
    void Render();
    void Init();
    void AddPointLight();
    void AddCube();
    void MouseClick(int button , int state, int x, int y);
    void KeyPress(unsigned char key, int x, int y);
    void KeyUp(unsigned char key, int x, int y);
    void MouseMove(int x, int y);
private:
    void InitShaderProgram();
    void InitUniformLocations();
    void InitPlatform();
    void InitDirectionalLight();

    std::vector<Model *> models;
    std::vector<PointLight *> pointLights;
    std::vector<Camera *> cams;
    DirectionalLight directionalLight;
    MouseEventHandler meh;
    KeyboardEventHandler keh;
    CameraEventHandler ceh;
    Camera *activeCam;
    ShaderProgram program;
    // uniforms
    std::vector<PointLightUniform> plus;
    GLuint sampler;
    DirectionalLightUniform dlu;
    GLuint pointLightsNumber;
    GLuint activeCamUniform;
    GLuint WVP;
    GLuint worldTrans;
};


#endif //CG_GAMEMANAGER_H
