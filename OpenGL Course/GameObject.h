#pragma once

#include "Model.h";
#include "reactphysics3d/reactphysics3d.h"

using namespace reactphysics3d;
//TODO: Add the needed includes to deal with transforms
class GameObject
{
protected:

	Model model;
	
private:

	BoxShape* mBoxShape;
	Collider* mCollider;
	PhysicsCommon common;
	RigidBody* body;

public:
	//Keeping the transform public since it will be changed all the time from many different places.
	Transform transform;
	
		

	GameObject(std::string modelPath);
	GameObject(std::string modelPath, Vector3 position);
	GameObject(std::string modelPath, Vector3 position, PhysicsCommon& physicsCommon, PhysicsWorld* world);

	~GameObject();

	//This is an empty function. Called on creation, to be overriden by the child classes. No need to put it on the CPP file
	virtual void start() {};

	//This is an empty function. Called each frame, to be overriden by the child classes. No need to put it on the CPP file
	virtual void update() {};	

	//TODO: Call the rendermodel on model
	void render();
};
