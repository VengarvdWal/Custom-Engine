#include "GameObject.h"

GameObject::GameObject(std::string modelPath)
{	
	matrix.LoadModel(modelPath);		
}

GameObject::~GameObject()
{
}

void GameObject::render() 
{
	matrix.RenderModel();
}