#include "GameObject.h"

GameObject::GameObject(std::string modelPath)
{	
	model.LoadModel(modelPath);		
}

//TODO This doesn't work
GameObject::GameObject(std::string modelPath, Vector3 position) : GameObject(modelPath)
{
	//std::cout << "First postition " << transform.getPosition().x << " " << transform.getPosition().y << " " << transform.getPosition().z << std::endl;
	transform = Transform(position, Quaternion::identity());
	//std::cout << "Second position " << transform.getPosition().x << " " << transform.getPosition().y << " " << transform.getPosition().z << std::endl;
}

GameObject::~GameObject()
{
}

void GameObject::render() 
{
	model.RenderModel();
}