#include "GameObject.h"

GameObject::GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType)
{
	model.LoadModel(modelPath);
	//TODO this should go on first render.
	start();	
	body = physicsManager->createRigidBody(Transform::identity());
	//body->setTransform(Transform(position, Quaternion::identity()));
	//body->enableGravity(true);
	body->setType(bodyType);
	body->addCollider(physicsManager->createBoxShape(Vector3(5, 5, 5)), Transform::identity());
}

GameObject::GameObject(std::string modelPath, PhysicsManager* physicsManager, BodyType bodyType, Vector3 position) : GameObject(modelPath, physicsManager, bodyType)
{
	Transform transform(Vector3(position), Quaternion::identity());
	body->setTransform(transform);
}

GameObject::~GameObject()
{
}

void GameObject::render()
{
	//Use a flag for start init
	
	update();
	model.RenderModel();
}

Transform GameObject::getTransform()
{
	return body->getTransform();
}

void GameObject::setTransform(Transform transform)
{
	body->setTransform(transform);
}
