#pragma once
class Entity
{
public:

	Entity();
	Entity(int mHealth, int mDamage, int mSpeed);

	~Entity();

protected:

	int mHealth;
	int mDamage;
	int mSpeed;
};
