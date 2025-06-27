#include "stdafx.h"
#include "InputMgrVector.h"

std::vector<sf::Keyboard::Key> InputMgrVector::downKeys;
std::vector<sf::Keyboard::Key> InputMgrVector::heldKeys;
std::vector<sf::Keyboard::Key> InputMgrVector::upKeys;

void InputMgrVector::Init()
{
	for (int i = 0; i < sf::Keyboard::Key::KeyCount; i++)
	{
		downKeys.push_back(sf::Keyboard::Key(i));
		heldKeys.push_back(sf::Keyboard::Key(i));
		upKeys.push_back(sf::Keyboard::Key(i));
	}
}

void InputMgrVector::Clear()
{
	downKeys.clear();
	heldKeys.clear();
	upKeys.clear();
	Init();
}

void InputMgrVector::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
		case sf::Event::KeyPressed:
			if (!Contains(heldKeys, ev.key.code))
			{
				downKeys[ev.key.code] = sf::Keyboard::Key::Unknown;
				heldKeys[ev.key.code] = sf::Keyboard::Key::Unknown;
			}
			break;
		case sf::Event::KeyReleased:
			Remove(heldKeys, ev.key.code);
			upKeys[ev.key.code] = sf::Keyboard::Key::Unknown;
			break;
	}
}

void InputMgrVector::Update(float dt)
{

}

bool InputMgrVector::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputMgrVector::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputMgrVector::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputMgrVector::Contains(const std::vector<sf::Keyboard::Key>& vec, sf::Keyboard::Key key)
{
	return vec[key] == sf::Keyboard::Key::Unknown;
}

void InputMgrVector::Remove(std::vector<sf::Keyboard::Key>& vec, sf::Keyboard::Key key)
{
	vec[key] = key;
}
