#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:

	Enemy(std::string modelPath, PhysicsManager* physicsManager);
	
	Enemy(std::string modelPath, PhysicsManager* physicsManager, Vector3 position);

	Enemy(std::string modelPath, PhysicsManager* physicsManager, Vector3 position , int mHealth, int mDamage, int mSpeed, int FOV);

	Enemy(const Enemy&) = delete;
	~Enemy();

protected:
	int FOV;
};
