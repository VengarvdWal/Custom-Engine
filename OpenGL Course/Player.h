#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player();
	Player(int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP);

	~Player();

protected:
	int mXP;
	int mStamina;
	int mCargoLimit;
};
