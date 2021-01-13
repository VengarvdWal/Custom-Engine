#include "Enemy.h"

Enemy::Enemy(std::string modelPath, PhysicsManager* physicsManager) : Character(modelPath, physicsManager)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	FOV = 0;
}

Enemy::Enemy(std::string modelPath, PhysicsManager* physicsManager, Vector3 position) : Character(modelPath, physicsManager ,position)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	FOV = 60;
}

Enemy::Enemy(std::string modelPath, PhysicsManager* physicsManager, Vector3 position, int mHealth, int mDamage, int mSpeed, int FOV) : Character(modelPath, physicsManager, position, mHealth, mDamage, mSpeed)
{ 
	this->FOV = FOV;
}

Enemy::~Enemy()
{
}