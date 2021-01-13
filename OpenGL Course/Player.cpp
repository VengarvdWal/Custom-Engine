#include "Player.h"


Player::Player(std::string modelPath, PhysicsManager* physicsManager) : Character(modelPath, physicsManager)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	mStamina = 0;
	mXP = 0;
	mCargoLimit = 0;
}


Player::Player(std::string modelPath, PhysicsManager* physicsManager, Vector3 position) : Character(modelPath, physicsManager, position)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	mStamina = 0;
	mXP = 0;
	mCargoLimit = 0;
}

Player::Player(std::string modelPath, PhysicsManager* physicsManager, Vector3 position, int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP) : Character(modelPath, physicsManager, position, mHealth, mDamage, mSpeed)
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
	//transform.setPosition(Vector3(transform.getPosition().x + 0.001f, transform.getPosition().y, transform.getPosition().z));
	//body->setTransform((Vector3(body->getTransform().getPosition().x, body->getTransform().getPosition().y, body->getTransform().getPosition().z), Transform::identity()));
	
}
//
//void Player::addToInventory(GameObject go)
//{
//	inventory.push_back(go);
//}
//
//void Player::removeFromInventory(GameObject go)
//{
//	
//}
