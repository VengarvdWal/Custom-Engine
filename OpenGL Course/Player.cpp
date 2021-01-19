#include "Player.h"


Player::Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize) : Character(modelPath, physicsManager, bodyType, collisionSize)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	mStamina = 0;
	mXP = 0;
	mCargoLimit = 0;
}


Player::Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position) : Character(modelPath, physicsManager, bodyType, collisionSize, position)
{
	mHealth = 0;
	mDamage = 0;
	mSpeed = 0;
	mStamina = 0;
	mXP = 0;
	mCargoLimit = 0;
}

Player::Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position, int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP) : Character(modelPath, physicsManager, bodyType, collisionSize, position, mHealth, mDamage, mSpeed)
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
	
}

void Player::Movement(bool* keys, GLfloat deltaTime)
{	

	if (keys[GLFW_KEY_W])
	{
		horizontal = 1;		
	}

	if (keys[GLFW_KEY_S])
	{
		horizontal = -1;		
	}

	if (keys[GLFW_KEY_A])
	{
		vertical = -1;		
	}

	if (keys[GLFW_KEY_D])
	{
		vertical = 1;		
	}

	if (!keys[GLFW_KEY_W] && !keys[GLFW_KEY_S] && !keys[GLFW_KEY_A] && !keys[GLFW_KEY_D])
	{
		vertical = 0;
		horizontal = 0;
	}
	
	Transform transform = Player::getTransform();
	transform.getPosition();
	body->applyForceToCenterOfMass(Vector3(horizontal * mSpeed * deltaTime, 0 ,vertical * mSpeed * deltaTime));
}

void Player::LookDirection(glm::vec3 lookDirection)
{	
	Vector3 direction = Vector3(lookDirection.x, 0, lookDirection.z);
	Quaternion quaternion = Quaternion::fromEulerAngles(lookDirection.x, 0, lookDirection.z);
	Player::getTransform().setOrientation(quaternion);
	
	
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
