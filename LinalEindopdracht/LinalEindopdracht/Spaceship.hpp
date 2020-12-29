#pragma once

#include "RenderObject.hpp"
#include "InputHandler.hpp"
#include "Scene.hpp"

class Spaceship : public RenderObject
{
private:
	InputHandler& inputHandler;
	Scene& scene;
public:
	Spaceship(InputHandler& inputHandler, Scene& scene);

	void update();
};