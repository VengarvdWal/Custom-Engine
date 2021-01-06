#pragma once
#include <glm\glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <reactphysics3d\reactphysics3d.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include "GLWindow.h"
#include "GameObject.h"
#include "CommonValues.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "RenderMaterial.h"
#include "Model.h"
#include "Skybox.h"

#include "Player.h"
#include "Enemy.h"
#include "Shaders.h"


using namespace reactphysics3d;

class Game {
private:
    //TODO: Add all necessary variables here
    //This vector will hold all the games entities just like the hierarchy in Unity.
    std::vector<GameObject*> gameObjects;   

    GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
        uniformSpecularIntensity = 0, uniformShininess = 0, uniformOmniLightPos = 0, uniformFarPlane = 0;

    Camera camera;

    std::vector<Shader*> shaderList;
    Shader directionalShadowShader;
    Shader omniShadowShader;
    Shader objectShader;

    GLfloat deltaTime = 0.0f;
    GLfloat lastTime = 0.0f;
    GLfloat accumulator = 0.0f;

    GLWindow* mainWindow;

    Texture brickTexture;
    Texture dirtTexture;
    Texture plainTexture;

    RenderMaterial shinyMaterial;
    RenderMaterial dullMaterial;

    DirectionalLight mainLight;
    PointLight pointLights[MAX_POINT_LIGHTS];
    SpotLight spotLights[MAX_SPOT_LIGHTS];

    Skybox skybox;

    unsigned int pointLightCount = 0;
    unsigned int spotLightCount = 0;

    void CreateShaders();
    void RenderScene();
    void DirectionalShadowMapPass(DirectionalLight* light);
    void OmniShadowMapPass(PointLight* light);
    void RenderPass(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
    void AddGameObject(GameObject* entity);

public:
    //Game receives the window to be able to check for window closing and events on the loop.
    Game(GLWindow* mainWindow);

    //This will be called before run and will initialize everything
    //like creating all objects, lights, etc. needed for the scene, setting up shaders etc...
    void Init();   

    //will be called in main and has the full game loop;
    //Inside the loop it will deal with the timing and call render();
    void Run();
};