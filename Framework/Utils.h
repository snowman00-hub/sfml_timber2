#pragma once

class Utils
{
public:
	static sf::Vector2f setOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f setOrigin(sf::Text& obj, Origins preset);
};