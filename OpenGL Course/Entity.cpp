#include "Entity.h"

Entity::Entity()
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
}

Entity::Entity(int mHealth, int mDamage, int mSpeed)
{
	this->mHealth = mHealth;
	this->mDamage = mDamage;
	this->mSpeed = mSpeed;
}

Entity::Render() 
{
	matrix = glm::mat4(1.0f);
	matrix = glm::translate(matrix, glm::vec3(0.0f, 0.0f, 0.0f));
	shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(matrix));
	model.RenderModel();
}

Entity::~Entity()
{
}