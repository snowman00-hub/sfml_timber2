#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
	std::string name;
	bool active;

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
	sf::Vector2f origin;

public:
	virtual void Init();
	virtual void Release();
	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw();
};

