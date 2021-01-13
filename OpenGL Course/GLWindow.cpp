#include "GLWindow.h"

GLWindow::GLWindow()
{
	width = 800;
	height = 600;

	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}

	xChange = 0;
	yChange = 0;
}

GLWindow::GLWindow(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;

	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}

	xChange = 0;
	yChange = 0;
}

int GLWindow::Initialise()
{
	//Initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW Initialisation failed!");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_SAMPLES, 8);
	glEnable(GL_MULTISAMPLE);

	// Core profile = NO backwards Compatibilit
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//
	mainWindow = glfwCreateWindow(width, height, "Ant Stranding", glfwGetPrimaryMonitor(), NULL);
	if (!mainWindow)
	{
		printf("GLFW windos creation failed!");
		glfwTerminate();
		return 1;
	}

	// Get buffer size information
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Handle Key + Mouse Input
	createCallBack();
	glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	glfwSetWindowUserPointer(mainWindow, this);
}

void GLWindow::createCallBack()
{
	glfwSetKeyCallback(mainWindow, handleKeys);
	glfwSetCursorPosCallback(mainWindow, handleMouse);
}

GLfloat GLWindow::getXChange()
{
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat GLWindow::getYChange()
{
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}

void GLWindow::handleKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
	GLWindow* currentWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			currentWindow->keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			currentWindow->keys[key] = false;
		}
	}
}

void GLWindow::handleMouse(GLFWwindow* window, double xPos, double yPos)
{
	GLWindow* currentWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	if (currentWindow->mouseFirstMoved)
	{
		currentWindow->lastX = xPos;
		currentWindow->lastY = yPos;
		currentWindow->mouseFirstMoved = false;
	}

	currentWindow->xChange = xPos - currentWindow->lastX;
	currentWindow->yChange = currentWindow->lastY - yPos;

	currentWindow->lastX = xPos;
	currentWindow->lastY = yPos;
}

GLWindow::~GLWindow()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}