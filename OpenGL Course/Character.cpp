#include "Character.h"


Character::Character(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType) : GameObject(modelPath,  physicsManager, bodyType)
{
}

Character::Character(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 position) : GameObject(modelPath, physicsManager, bodyType, position)
{

}

Character::Character(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType ,Vector3 position, int mHealth, int mDamage, int mSpeed) : GameObject(modelPath, physicsManager, bodyType ,position)
{
	this->mHealth = mHealth;
	this->mDamage = mDamage;
	this->mSpeed = mSpeed;
}

