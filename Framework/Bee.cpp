#include "stdafx.h"
#include "Bee.h"

Bee::Bee(const std::string& texId, const std::string& name)
	: SpriteGo(texId,name)
{
}

void Bee::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	switch (side)
	{
		case Sides::Left:
			direction = { 1.f,0.f };
			SetScale({ -1.f,1.f });
			SetPosition({ -150, Utils::RandomRange(700.f,750.f) });
			break;
		case Sides::Right:
			direction = { -1.f,0.f };
			SetScale({ 1.f,1.f });
			SetPosition({ 1920 + 150, Utils::RandomRange(700.f,750.f) });
			break;
	}
	speed = Utils::RandomRange(125.f, 150.f);
	time = 0.f;
}

void Bee::Reset()
{
	SpriteGo::Reset();

	SetOrigin(Origins::MC);
	if (Utils::RandomValue() < 0.5f)
	{
		SetSide(Sides::Left);
	}
	else
	{
		SetSide(Sides::Right);
	}
}

void Bee::Update(float dt)
{
	time += dt;
	sf::Vector2f pos = GetPosition();
	pos.x += direction.x * speed * dt;
	pos.y += direction.x * sinf(time) * speed * dt;
	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		if (Utils::RandomValue() < 0.5f)
		{
			SetSide(Sides::Left);
		}
		else
		{
			SetSide(Sides::Right);
		}
	}
}