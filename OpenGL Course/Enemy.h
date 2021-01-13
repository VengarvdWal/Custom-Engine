#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:

	Enemy(std::string modelPath);
	Enemy(std::string modelPath, int FOV, int mHealth, int mDamage, int mSpeed);
	Enemy(std::string modelPath, Vector3 position, PhysicsCommon& physicsCommon, PhysicsWorld* world);

	~Enemy();

protected:
	int FOV;
};
