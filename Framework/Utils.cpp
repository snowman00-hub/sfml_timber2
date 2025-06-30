#include "stdafx.h"
#include "Utils.h"

void Utils::Init()
{
	srand((int)time(0));
}

float Utils::RandomValue()
{
	return (float)rand() / RAND_MAX;
}

int Utils::RandomRange(int min, int maxExclude)
{
	return min + rand() % (maxExclude - min);
}

float Utils::RandomRange(float min, float max)
{
	return min + (max - min) * (float)rand() / RAND_MAX;
}

sf::Vector2f Utils::setOrigin(sf::Sprite& obj, Origins preset)
{
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigin(rect.width, rect.height);

	newOrigin.x *= ((int)preset % 3) * 0.5f;
	newOrigin.y *= ((int)preset / 3) * 0.5f;

	obj.setOrigin(newOrigin);
	return newOrigin;
}

sf::Vector2f Utils::setOrigin(sf::Text& obj, Origins preset)
{
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigin(rect.width, rect.height);

	newOrigin.x *= ((int)preset % 3) * 0.5f;
	newOrigin.y *= ((int)preset / 3) * 0.5f;

	obj.setOrigin(newOrigin);
	return newOrigin;
}
