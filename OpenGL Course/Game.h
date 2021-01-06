#pragma once
#include <glm\glm.hpp>

class Game {
    private:
        //TODO: Add all necessary variables here
        //This vector will hold all the games entities just like the hierarchy in Unity.
        vector<Entity *> entities;

        void CreateShaders();
        void RenderScene();
        void RenderPass(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
        void AddEntity(Entity * entity);

    public:
        //Game receives the window to be able to check for window closing and events on the loop.
        Game(GLWindow * mainWindow);

        //This will be called before run and will initialize everything
        //like creating all objects, lights, etc. needed for the scene, setting up shaders etc...
        void Init();

        //Will do ALL the rendering for the game
        //It should go throuh all entities and call their render methods.
        void Render();

        //will be called in main and has the full game loop;
        //Inside the loop it will deal with the timing and call render();
        void Run();
}