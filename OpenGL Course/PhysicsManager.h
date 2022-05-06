#pragma once
#include <reactphysics3d/reactphysics3d.h>
class PhysicsManager
{

private:

	rp3d::PhysicsWorld* world;
	rp3d::PhysicsCommon common;
	

public:

	PhysicsManager();
	~PhysicsManager();	

	void update(const float timeStep);
	void DestroyGameObject(rp3d::RigidBody* body);
	rp3d::RigidBody *createRigidBody(rp3d::Transform transform);
	rp3d::BoxShape *createBoxShape(rp3d::Vector3 size);
	
};

