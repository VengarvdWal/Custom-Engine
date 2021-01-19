#pragma once
#include "Character.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
class Player :
	public Character
{
public:


	Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize);

	Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position);

	Player(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position , int mHealth, int mDamage, int mSpeed, int mStamina, int mCargoLimit, int mXP);

	//Player(const Player&) = delete;

	~Player();

	void start();

	void update();

	void Movement(bool* keys, GLfloat deltaTime);

	void LookDirection(glm::vec3 lookDirection);	
		
	void addToInventory(GameObject go);

	void removeFromInventory(GameObject go);


private:
	std::vector<GameObject> inventory;
	float horizontal = 0, vertical = 0;


protected:
	int mXP;
	int mStamina;
	int mCargoLimit;
};
