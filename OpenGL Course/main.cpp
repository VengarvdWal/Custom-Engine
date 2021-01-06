#define STB_IMAGE_IMPLEMENTATION

#include "Game.h"

const float toRadians = 3.14159265f / 180.0f;

GLWindow mainWindow;

Model ant;

Game game(&mainWindow);


int main()
{ 
	mainWindow = GLWindow(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	game.Init();

	game.Run();	

	//const float timeStep = 1.0f / 60.0f;*/

	return 0;
}

