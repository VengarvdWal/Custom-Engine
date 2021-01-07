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

GameObject::~GameObject()
{
}

void GameObject::render() 
{
	//Use a flag for start init
	
	update();
	model.RenderModel();
}