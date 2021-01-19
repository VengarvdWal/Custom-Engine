#include "Character.h"


Character::Character(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize) : GameObject(modelPath,  physicsManager, bodyType, collisionSize)
{
}

Character::Character(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position) : GameObject(modelPath, physicsManager, bodyType, collisionSize, position)
{

}

Character::Character(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize,Vector3 position, int mHealth, int mDamage, int mSpeed) : GameObject(modelPath, physicsManager, bodyType, collisionSize ,position)
{
	this->mHealth = mHealth;
	this->mDamage = mDamage;
	this->mSpeed = mSpeed;
}

