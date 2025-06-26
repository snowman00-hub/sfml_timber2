#pragma once
#include <list>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

class InputMgr
{
private:
	static std::vector<int> downKeys;
	static std::vector<int> heldKeys;
	static std::vector<int> upKeys;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
};

