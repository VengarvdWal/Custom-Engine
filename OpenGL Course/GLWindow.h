#pragma once

#include <stdio.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

class GLWindow
{
public:
	GLWindow();
	GLWindow(GLint windowWidth, GLint windowHeight);

	int Initialise();

	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }

	bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }

	bool* getsKeys() { return keys; }
	bool getClick() { return mouseClicked; }
	GLfloat getXChange();
	GLfloat getYChange();

	void swapBuffers() { glfwSwapBuffers(mainWindow); }

	~GLWindow();

private:
	GLFWwindow* mainWindow;

	GLint width, height;
	GLint bufferWidth, bufferHeight;

	bool keys[1024];
	bool mouseClicked = false;

	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	bool mouseFirstMoved;
	

	void createCallBack();
	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleClick(GLFWwindow* window, int button, int action, int mods);
	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
};
