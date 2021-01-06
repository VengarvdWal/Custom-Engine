#pragma once

#include "Model.h";
#include "reactphysics3d/reactphysics3d.h"

using namespace reactphysics3d;
//TODO: Add the needed includes to deal with transforms
class GameObject
{
protected:

	Model model;

public:
	//Keeping the transform public since it will be changed all the time from many different places.
	Transform transform; 
	
	GameObject(std::string modelPath);

	~GameObject();

	//This is an empty function. Called on creation, to be overriden by the child classes. No need to put it on the CPP file
	void start() {};

	//This is an empty function. Called each frame, to be overriden by the child classes. No need to put it on the CPP file
	void update() {};

	//TODO: Call the rendermodel on model
	void render();
};
