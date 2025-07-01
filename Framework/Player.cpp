#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& name)
	: GameObject(name)
{
}

void Player::SetSide(Sides s)
{
	side = s;
	sprite.setPosition(position + positions[(int)side]);
	sprite.setScale(scales[(int)side]);

	axeSprite.setPosition(position + axePositions[(int)side]);
	axeSprite.setScale(scales[(int)side]);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position + positions[(int)side]);
	axeSprite.setPosition(position + axePositions[(int)side]);
}

void Player::SetAlive(bool live)
{
	if (live)
	{
		sprite.setTexture(TEXTURE_MGR.Get(textureId));
	}
	else
	{
		sprite.setTexture(TEXTURE_MGR.Get(ripTexId));
		sprite.setScale({ 1.f,1.f });
		drawAxe = false;
	}
	Utils::SetOrigin(sprite, Origins::BC);
}

void Player::Init()
{
	textureId = "graphics/player.png";
	axeTexId = "graphics/axe.png";
	ripTexId = "graphics/rip.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.f,0.f };
	positions[(int)Sides::Right] = { 300.f,0.f };
	axePositions.resize(2);
	axePositions[(int)Sides::Left] = { -100.f,-80.f };
	axePositions[(int)Sides::Right] = { 100.f,-80.f };

	scales.resize(2);
	scales[(int)Sides::Left] = { -1.f,1.f };
	scales[(int)Sides::Right] = { 1.f,1.f };
}

void Player::Release()
{
}

void Player::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
	axeSprite.setTexture(TEXTURE_MGR.Get(axeTexId));
	Utils::SetOrigin(sprite, Origins::BC);
	SetSide(Sides::Right);
}

void Player::Update(float dt)
{
	drawAxe = false;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	if (drawAxe)
	{
		window.draw(axeSprite);
	}
}
