#pragma once

#include "Model.h";
#include "reactphysics3d/reactphysics3d.h"
#include "PhysicsManager.h"

using namespace reactphysics3d;
//TODO: Add the needed includes to deal with transforms
class GameObject
{
protected:

	Model model;
	RigidBody* body;
	
private:

		

public:
	//Keeping the transform public since it will be changed all the time from many different places.
	
	GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize);

	GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position);

	~GameObject();

	GameObject(const GameObject&) = delete;

	//This is an empty function. Called on creation, to be overriden by the child classes. No need to put it on the CPP file
	virtual void start() {};

	//This is an empty function. Called each frame, to be overriden by the child classes. No need to put it on the CPP file
	virtual void update() {};	

	//TODO: Call the rendermodel on model
	void render();

	Transform getTransform();

	RigidBody* getRigidBody();
		
	void setTransform(Transform transform);

};
