#pragma once

class Utils
{
public:
	static void Init(); // ������ �ʱ�ȭ�� �ʱ�ȭ, C++�� �����Լ���

	// Random
	static float RandomValue(); // 0.0f ~ 1.0f
	static int RandomRange(int min, int maxExclude);
	static float RandomRange(float min, float max);

	// Origin
	static sf::Vector2f setOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f setOrigin(sf::Text& obj, Origins preset);
};