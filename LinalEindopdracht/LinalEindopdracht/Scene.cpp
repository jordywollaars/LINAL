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
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->update();
	}
}

void Scene::render(sf::RenderWindow& window)
{
	for (int i = 0; i < renderObjects.size(); i++)
	{
		renderObjects[i]->render(window);
	}
}

std::vector<RenderObject*>& Scene::getRenderObjects()
{
	return this->renderObjects;
}
