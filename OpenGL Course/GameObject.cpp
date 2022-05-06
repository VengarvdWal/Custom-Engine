#include "GameObject.h"

GameObject::GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize)
{
	model.LoadModel(modelPath);
	start();
	body = physicsManager->createRigidBody(Transform::identity());
	body->setType(bodyType);
	body->addCollider(physicsManager->createBoxShape(collisionSize), Transform::identity());
	body->setLinearDamping(0);
	body->setAngularDamping(0);
}

GameObject::GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 collisionSize, Vector3 position) : GameObject(modelPath, physicsManager, bodyType, collisionSize)
{
	Transform transform(Vector3(position), Quaternion::identity());
	body->setTransform(transform);
}

GameObject::~GameObject()
{
}

void GameObject::render()
{
	update();
	model.RenderModel();
}

Transform GameObject::getTransform()
{
	return body->getTransform();
}

RigidBody* GameObject::getRigidBody()
{
	return body;
}

void GameObject::setTransform(Transform transform)
{
	body->setTransform(transform);
}

void GameObject::SetPosition(Vector3 position)
{
	Transform playerTransform(Vector3(position), Quaternion::identity());
	setTransform(playerTransform);
}

void GameObject::moveControl(bool clicked, Vector3 cameraForward)
{
	if (clicked)
	{
		body->applyForceToCenterOfMass(cameraForward * 3000);
	}
}
