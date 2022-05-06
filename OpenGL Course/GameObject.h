#pragma once

#include "Model.h";
#include "reactphysics3d/reactphysics3d.h"
#include "PhysicsManager.h"

using namespace reactphysics3d;

class GameObject
{
protected:

	Model model;
	RigidBody* body;
	
private:

		

public:	
	
	GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize);

	GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position);

	~GameObject();

	GameObject(const GameObject&) = delete;
		
	virtual void start() {};

	virtual void update() {};	

	void render();

	Transform getTransform();

	RigidBody* getRigidBody();
		
	void setTransform(Transform transform);

	void SetPosition(Vector3 position);

	void moveControl(bool clicked, Vector3 cameraForward);
		
};
