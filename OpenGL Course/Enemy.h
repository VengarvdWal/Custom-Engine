#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:

	Enemy();
	Enemy(int FOV, int mHealth, int mDamage, int mSpeed);

	~Enemy();

protected:
	int FOV;
};
