#include "Enemy.h"

Enemy::Enemy() : Entity()
{
	FOV = 60;
}

Enemy::Enemy(int FOV, int mHealth, int mDamage, int mSpeed) : Entity(mHealth, mDamage, mSpeed)
{
	this->FOV = FOV;
}

Enemy::~Enemy()
{
}