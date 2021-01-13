#include "PhysicsManager.h"



PhysicsManager::PhysicsManager()
{
	world = common.createPhysicsWorld();
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::update(const float timeStep)
{
	world->update(timeStep);
}

rp3d::RigidBody *PhysicsManager::createRigidBody(rp3d::Transform transform)
{
	
	return world->createRigidBody(transform);
}

rp3d::BoxShape *PhysicsManager::createBoxShape(rp3d::Vector3 size)
{
	return common.createBoxShape(size);
}
