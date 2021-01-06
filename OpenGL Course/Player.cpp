#include "Player.h"

Player::Player()
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	mStamina = 0;
	mXP = 0;
	mCargoLimit = 0;
}

Player::Player(int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP)
{
	this->mHealth = mHealth;
	this->mDamage = mDamage;
	this->mSpeed = mSpeed;
	this->mStamina = mStamina;
	this->mCargoLimit = mCargoLimit;
	this->mXP = mXP;
}
Player::~Player()
{
}