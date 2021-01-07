#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(std::string modelPath);
	Player(std::string modelPath, Vector3 position);
	Player(std::string modelPath, int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP);

	~Player();

	void start();

	void update();

protected:
	int mXP;
	int mStamina;
	int mCargoLimit;
};
