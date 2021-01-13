#include "GameObject.h"

GameObject::GameObject(std::string modelPath)
{
	model.LoadModel(modelPath);
	//TODO this should go on first render.
	start();
}

GameObject::GameObject(std::string modelPath, Vector3 position) : GameObject(modelPath)
{
	transform.setPosition(position);
}

GameObject::GameObject(std::string modelPath, Vector3 position, PhysicsCommon &physicsCommon, PhysicsWorld* world) : GameObject(modelPath)
{
	mBoxShape = physicsCommon.createBoxShape(Vector3(5, 5, 5));

	transform.setPosition(position);
	body = world->createRigidBody(transform);	
	body->enableGravity(true);
	body->setType(BodyType::DYNAMIC);
	mCollider = body->addCollider(mBoxShape, Transform::identity());
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