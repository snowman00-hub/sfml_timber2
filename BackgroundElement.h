#pragma once
#include "SpriteGo.h"
class BackgroundElement : public SpriteGo
{
protected:	

public:
	BackgroundElement(const std::string& texId = "", const std::string& name = "");

	float speed = 0.f;
	sf::Vector2f direction;

	void SetSide(Sides side);

	void Reset() override;
	void Update(float dt) override;
};

