#include "Character.h"


Character::Character(std::string modelPath, PhysicsManager* physicsManager) : GameObject(modelPath,  physicsManager)
{
}

Character::Character(std::string modelPath, PhysicsManager* physicsManager, Vector3 position) : GameObject(modelPath, physicsManager, position)
{

}

Character::Character(std::string modelPath, PhysicsManager* physicsManager, Vector3 position, int mHealth, int mDamage, int mSpeed) : GameObject(modelPath, physicsManager, position)
{
	this->mHealth = mHealth;
	this->mDamage = mDamage;
	this->mSpeed = mSpeed;
}

