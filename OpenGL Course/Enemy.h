#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:

	Enemy(std::string modelPath);
	Enemy(std::string modelPath, int FOV, int mHealth, int mDamage, int mSpeed); 

	~Enemy();

protected:
	int FOV;
};
