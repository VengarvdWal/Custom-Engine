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
	Character(std::string modelPath);
	Character(std::string modelPath, int mHealth, int mDamage, int mSpeed);
};

