#include "Player.h"

Player::Player(std::string modelPath) : Character(modelPath)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	mStamina = 0;
	mXP = 0;
	mCargoLimit = 0;
}

Player::Player(std::string modelPath, Vector3 position) : Character(modelPath, position)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	mStamina = 0;
	mXP = 0;
	mCargoLimit = 0;
}

Player::Player(std::string modelPath, int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP) : Character(modelPath)
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

void Player::start()
{
	
}
void Player::update() 
{
	std::cout << "Update on Player called" << std::endl;
	transform.setPosition(Vector3(transform.getPosition().x + 0.1f, transform.getPosition().y, transform.getPosition().z));

}