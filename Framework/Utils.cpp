#include "stdafx.h"
#include "Utils.h"

sf::Vector2f Utils::setOrigin(sf::Sprite& obj, Origins preset)
{
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigin(rect.width, rect.height);

	newOrigin.x *= ((int)preset % 3) * 0.5f;
	newOrigin.y *= ((int)preset / 3) * 0.5f;

	obj.setOrigin(newOrigin);
	return newOrigin;
}
