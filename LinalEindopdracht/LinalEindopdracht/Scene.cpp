#include "Scene.hpp"

void Scene::add(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);

	RenderObject* renderObject = dynamic_cast<RenderObject*>(gameObject);
	if (renderObject)
	{
		this->renderObjects.push_back(renderObject);
	}

	BoundingBox* boundingBox = dynamic_cast<BoundingBox*>(gameObject);
	if (boundingBox)
	{
		this->boundingBoxes.push_back(boundingBox);
	}
}

void Scene::updateCollisions()
{
	for (int i = 0; i < boundingBoxes.size(); i++)
	{
		for (int j = 0; j < boundingBoxes.size(); j++)
		{
			if (i != j)
			{
				boundingBoxes[i]->collision(boundingBoxes[j]);
			}
		}
	}
}

template <typename Vec, typename Object>
void removeFromVector(Vec& vector, Object object) {
	auto it{ std::find(vector.begin(), vector.end(), object) };
	if (it != vector.end()) {
		vector.erase(it);
	}
}

void Scene::update(double deltaTime)
{
	while (!this->toBeDestroyed.empty())
	{
		removeFromVector(this->gameObjects, this->toBeDestroyed[0]);
		RenderObject* renderObject = dynamic_cast<RenderObject*>(this->toBeDestroyed[0]);
		if (renderObject)
		{
			removeFromVector(this->renderObjects, renderObject);
		}
		BoundingBox* boundingBox = dynamic_cast<BoundingBox*>(this->toBeDestroyed[0]);
		if (boundingBox)
		{
			removeFromVector(this->boundingBoxes, boundingBox);
		}
		removeFromVector(this->toBeDestroyed, this->toBeDestroyed[0]);
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->update(deltaTime);
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
