#pragma once
#include "SpriteGo.h"

class Bee : public SpriteGo
{
protected:

public:
	Bee(const std::string& texId = "", const std::string& name = "");

	float speed = 0.f;
	sf::Vector2f direction;
	float time = 0.f;

	void SetSide(Sides side);

	void Reset() override;
	void Update(float dt) override;
};

