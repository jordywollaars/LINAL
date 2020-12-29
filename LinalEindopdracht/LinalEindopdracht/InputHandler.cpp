#include "InputHandler.hpp"

void InputHandler::input(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (this->keys[event.key.code] != InputState::HOLD)
		{
			this->keys[event.key.code] = InputState::PRESSED;
			this->pressedKeys.push_back(event.key.code);
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		this->keys[event.key.code] = InputState::RELEASED;
		this->releasedKeys.push_back(event.key.code);
	}
}

void InputHandler::clear()
{
	for (sf::Keyboard::Key code : this->pressedKeys) {
		this->keys[code] = InputState::HOLD;
	}

	for (sf::Keyboard::Key code : this->releasedKeys) {
		this->keys.erase(code);
	}

	this->releasedKeys.clear();
	this->pressedKeys.clear();
}

bool InputHandler::keyDown(sf::Keyboard::Key keyCode) const
{
	auto it = this->keys.find(keyCode);
	return it != this->keys.end() && it->second == InputState::PRESSED;
}

bool InputHandler::keyHold(sf::Keyboard::Key keyCode) const
{
	auto it = this->keys.find(keyCode);
	return it != this->keys.end() &&
		(it->second == InputState::HOLD || it->second == InputState::PRESSED);
}

bool InputHandler::keyUp(sf::Keyboard::Key keyCode) const
{
	auto it = this->keys.find(keyCode);
	return it != this->keys.end() && it->second == InputState::RELEASED;
}