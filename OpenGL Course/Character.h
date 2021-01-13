#pragma once
#include "GameObject.h"
class Character :
	public GameObject
{
protected:
	int mHealth;
	int mSpeed;
	int mDamage;

public:
	
	Character(std::string modelPath, PhysicsManager* physicsManager);

	Character(std::string modelPath, PhysicsManager* physicsManager, Vector3 position);

	Character(std::string modelPath, PhysicsManager* physicsManager, Vector3 position ,int mHealth, int mDamage, int mSpeed);

};
