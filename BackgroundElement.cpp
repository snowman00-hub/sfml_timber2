#include "stdafx.h"
#include "BackgroundElement.h"

BackgroundElement::BackgroundElement(const std::string& texId, const std::string& name)
	: SpriteGo(texId,name)
{
}

void BackgroundElement::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	switch (side)
	{
		case Sides::Left:
			direction = { 1.f,0.f };
			setScale({ -1.f,1.f });
			setPosition({ -150, 0 });
			break;
		case Sides::Right:
			direction = { -1.f,0.f };
			setScale({ 1.f,1.f });
			setPosition({ 1920 + 150, 0 });
			break;
	}
	speed = 200.f;
}

void BackgroundElement::Reset()
{
	SpriteGo::Reset();

	setOrigin(Origins::MC);
	SetSide(Sides::Left);
	setPosition({ 500.f,0.f });
}
// 스케일, y값 랜덤, 왼쪽오른쪽

void BackgroundElement::Update(float dt)
{
	sf::Vector2f pos = getPosition();
	pos += direction * speed * dt;
	setPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		SetSide(Sides::Right);
	}
}
