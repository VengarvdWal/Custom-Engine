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
	model.RenderModel();
}

Entity::~Entity()
{
}