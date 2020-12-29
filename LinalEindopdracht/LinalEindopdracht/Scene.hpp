#pragma once

#include "RenderObject.hpp"

class Scene {
public:
	void add(GameObject* gameObject);
	void update();
	void render(sf::RenderWindow& window);

	std::vector<RenderObject*>& getRenderObjects();
private:
	std::vector<GameObject*> gameObjects;
	std::vector<RenderObject*> renderObjects;
};