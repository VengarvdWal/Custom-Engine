#include "Character.h"

Character::Character(std::string modelPath) : GameObject(modelPath)
{
}

Character::Character(std::string modelPath, Vector3 position) : GameObject(modelPath, position)
{
}

Character::Character(std::string modelPath, Vector3 position, PhysicsCommon& physicsCommon, PhysicsWorld* world) : GameObject(modelPath, position, physicsCommon, world)
{
}

Character::Character(std::string modelPath, int mHealth, int mDamage, int mSpeed) : GameObject(modelPath)
{
	this->mHealth = mHealth;
	this->mDamage = mDamage;
	this->mSpeed = mSpeed;
}