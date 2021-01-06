#pragma once

#include <GL\glew.h>

class RenderMaterial
{
public:
	RenderMaterial();
	RenderMaterial(GLfloat sIntensity, GLfloat shine);

	void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

	~RenderMaterial();

private:
	GLfloat specularIntensity;
	GLfloat shininess;
};
