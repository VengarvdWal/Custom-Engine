#include "Enemy.h"

Enemy::Enemy(std::string modelPath) : Character(modelPath)
{
	FOV = 60;
}

Enemy::Enemy(std::string modelPath, int FOV, int mHealth, int mDamage, int mSpeed) : Character(modelPath, mHealth, mDamage, mSpeed)
{
	this->FOV = FOV;
}

Enemy::~Enemy()
{
}