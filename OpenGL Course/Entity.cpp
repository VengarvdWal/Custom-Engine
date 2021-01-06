#include "Entity.h"

Entity::Entity(String modelPath)
{
	model.loadModel(modelPath);
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
}

//This constructor calls the default constructor first to initialize the model and then sets the values.
Entity::Entity(String modelPath, int mHealth, int mDamage, int mSpeed) : Entity(modelPath)
{
	this->mHealth = mHealth;
	this->mDamage = mDamage;
	this->mSpeed = mSpeed;
}

Entity::~Entity()
{
}