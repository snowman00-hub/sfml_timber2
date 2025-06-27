#pragma once
#include <list>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

const int KEYCOUNT = sf::Keyboard::Key::KeyCount;

class InputMgrVector
{
private:
	static std::vector<sf::Keyboard::Key> downKeys;
	static std::vector<sf::Keyboard::Key> heldKeys;
	static std::vector<sf::Keyboard::Key> upKeys;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::vector<sf::Keyboard::Key>& vec, sf::Keyboard::Key key);
	static void Remove(std::vector<sf::Keyboard::Key>& vec, sf::Keyboard::Key key);
};

