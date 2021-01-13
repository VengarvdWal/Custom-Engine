#define STB_IMAGE_IMPLEMENTATION

#include "Game.h"

const float toRadians = 3.14159265f / 180.0f;

GLWindow mainWindow;

Game game(&mainWindow);

int main()
{
	mainWindow = GLWindow(1920, 1080); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	game.Init();

	game.Run();
		

	return 0;
}