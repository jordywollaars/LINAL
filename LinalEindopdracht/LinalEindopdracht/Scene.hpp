#pragma once

#include "RenderObject.hpp"
#include "BoundingBox.hpp"

class Scene {
public:
	void add(GameObject* gameObject);
	void updateCollisions();
	void update(double deltaTime);
	void render(sf::RenderWindow& window);

	std::vector<RenderObject*>& getRenderObjects();

	void queueForDestruction(GameObject* gameObject)
	{
		toBeDestroyed.push_back(gameObject);
	}
private:
	std::vector<GameObject*> gameObjects;
	std::vector<RenderObject*> renderObjects;
	std::vector<BoundingBox*> boundingBoxes;

	std::vector<GameObject*> toBeDestroyed;
};