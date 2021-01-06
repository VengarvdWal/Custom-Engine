#include "RenderMaterial.h"

RenderMaterial::RenderMaterial()
{
	specularIntensity = 0.0f;
	shininess = 0.0f;
}

RenderMaterial::RenderMaterial(GLfloat sIntensity, GLfloat shine)
{
	specularIntensity = sIntensity;
	shininess = shine;
}

void RenderMaterial::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation)
{
	glUniform1f(specularIntensityLocation, specularIntensity);
	glUniform1f(shininessLocation, shininess);
}

RenderMaterial::~RenderMaterial()
{
}