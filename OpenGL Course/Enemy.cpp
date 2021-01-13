#include "Enemy.h"

Enemy::Enemy(std::string modelPath) : Character(modelPath)
{
	FOV = 60;
}

Enemy::Enemy(std::string modelPath, int FOV, int mHealth, int mDamage, int mSpeed) : Character(modelPath, mHealth, mDamage, mSpeed)
{
	this->FOV = FOV;
}

Enemy::Enemy(std::string modelPath, Vector3 position, PhysicsCommon& physicsCommon, PhysicsWorld* world) : Character(modelPath, position, physicsCommon, world)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	FOV = 60;
}

Enemy::~Enemy()
{
}