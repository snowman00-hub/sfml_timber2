#include <algorithm>
#include "InputMgr.h"

std::vector<sf::Keyboard::Key> InputMgr::downKeys;
std::vector<sf::Keyboard::Key> InputMgr::heldKeys;
std::vector<sf::Keyboard::Key> InputMgr::upKeys;

void InputMgr::Init()
{
	for (int i = 0; i < sf::Keyboard::Key::KeyCount; i++)
	{
		downKeys.push_back(sf::Keyboard::Key(i));
		heldKeys.push_back(sf::Keyboard::Key(i));
		upKeys.push_back(sf::Keyboard::Key(i));
	}
}

void InputMgr::Clear()
{
	downKeys.clear();
	upKeys.clear();
	upKeys.clear();
	Init();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
		case sf::Event::KeyPressed:
			if (!Contains(heldKeys, ev.key.code))
			{
				downKeys[ev.key.code] = sf::Keyboard::Key::Unknown;
				heldKeys[ev.key.code] = sf::Keyboard::Key::Unknown;
				//downKeys.push_back(ev.key.code);
				//heldKeys.push_back(ev.key.code);
			}
			break;
		case sf::Event::KeyReleased:
			Remove(heldKeys, ev.key.code);
			upKeys[ev.key.code] = sf::Keyboard::Key::Unknown;
			//upKeys.push_back(ev.key.code);
			break;
	}
}

void InputMgr::Update(float dt)
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::vector<sf::Keyboard::Key>& vec, sf::Keyboard::Key key)
{
	//return std::find(list.begin(), list.end(), key) != list.end();
	return vec[key] == sf::Keyboard::Key::Unknown;
}

void InputMgr::Remove(std::vector<sf::Keyboard::Key>& vec, sf::Keyboard::Key key)
{
	//list.remove(key);
	vec[key] = key;
}
