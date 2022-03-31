#include "Enemy.h"

Enemy::Enemy(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize) : Character(modelPath, physicsManager, bodyType, collisionSize)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	FOV = 0;
}


Enemy::Enemy(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position) : Character(modelPath, physicsManager, bodyType, collisionSize ,position)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	FOV = 60;
}

Enemy::Enemy(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position, int mHealth, int mDamage, int mSpeed, int FOV) : Character(modelPath, physicsManager, bodyType, collisionSize, position, mHealth, mDamage, mSpeed)
{ 
	this->FOV = FOV;
}

Enemy::~Enemy()
{
}