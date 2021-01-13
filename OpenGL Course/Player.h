#pragma once
#include "Character.h"
class Player :
	public Character
{
public:


	Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType);

	Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 position);

	Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 position , int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP);

	//Player(const Player&) = delete;

	~Player();

	void start();

	void update();

	void addToInventory(GameObject go);

	void removeFromInventory(GameObject go);


private:
	std::vector<GameObject> inventory;


protected:
	int mXP;
	int mStamina;
	int mCargoLimit;
};
