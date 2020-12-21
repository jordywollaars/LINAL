#include "Scene.hpp"

void Scene::add(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);

	RenderObject* renderObject = dynamic_cast<RenderObject*>(gameObject);
	if (renderObject)
	{
		this->renderObjects.push_back(renderObject);
	}
}

void Scene::update()
{
	for (GameObject* gameObject : this->gameObjects)
	{
		gameObject->update();
	}
}

void Scene::render(sf::RenderWindow& window)
{
	for (RenderObject* renderObject : this->renderObjects)
	{
		renderObject->render(window);
	}
}
