#define STB_IMAGE_IMPLEMENTATION

#include "Game.h"

const float toRadians = 3.14159265f / 180.0f;

GLWindow mainWindow;

Model ant;

Game game(&mainWindow);

//void RenderScene()
//{
//	glm::mat4 model(1.0f);	
//	model = glm::mat4(1.0f);
//	model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
//	//model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
//	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//	plainTexture.UseTexture();
//	dullMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
//	meshList[2]->RenderMesh();
//
//	model = glm::mat4(1.0f);
//	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//	//model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
//	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//	shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
//
//	ant.RenderModel();
//}

int main()
{ 
	mainWindow = GLWindow(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	game.Init();

	game.Run();

	/*ant = Model();
	ant.LoadModel("Models/ant.obj");		

	const float timeStep = 1.0f / 60.0f;*/

	return 0;
}

