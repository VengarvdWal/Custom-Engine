#include "GameObject.h"

GameObject::GameObject(std::string modelPath)
{	
	model.LoadModel(modelPath);		
}

GameObject::~GameObject()
{
}

void GameObject::render() 
{	
	std::cout << "Rendering Model" << std::endl;
	model.RenderModel();
}