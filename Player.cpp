#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& name)
	: GameObject(name)
{
}

void Player::setSide(Sides s)
{
	side = s;
	sprite.setPosition(position + positions[(int)side]);
	sprite.setScale(scales[(int)side]);
}

void Player::setPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position + positions[(int)side]);
}

void Player::Init()
{
	textureId = "graphics/player.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.f,0.f };
	positions[(int)Sides::Right] = { 300.f,0.f };

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
	Utils::setOrigin(sprite, Origins::BC);
	setSide(Sides::Right);
}

void Player::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		setSide(Sides::Left);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		setSide(Sides::Right);
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
