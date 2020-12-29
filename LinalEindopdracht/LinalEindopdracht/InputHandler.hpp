#pragma once

#include <vector>
#include <sfml/Graphics.hpp>


enum InputState {
	PRESSED,
	HOLD,
	RELEASED,
};

class InputHandler {
private:
	std::map<sf::Keyboard::Key, InputState> keys;
	std::vector<sf::Keyboard::Key> releasedKeys;
	std::vector<sf::Keyboard::Key> pressedKeys;
public:
	InputHandler() {}
	//~InputHandler();

	void input(sf::Event& event);
	void clear();

	bool keyDown(sf::Keyboard::Key keyCode) const;
	bool keyHold(sf::Keyboard::Key keyCode) const;
	bool keyUp(sf::Keyboard::Key keyCode) const;

};