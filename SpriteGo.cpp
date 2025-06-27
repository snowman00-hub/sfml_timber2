#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string& texId, const std::string& name)
	: GameObject(name), textureId(texId)
{
}

void SpriteGo::setPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position);
}

void SpriteGo::setRotation(float r)
{
	rotation = r;
	sprite.setRotation(rotation);
}

void SpriteGo::setScale(const sf::Vector2f& s)
{
	scale = s;
	sprite.setScale(scale);
}

void SpriteGo::setOrigin(const sf::Vector2f& o)
{
	origin = o;
	sprite.setOrigin(o);
}

void SpriteGo::Init()
{
}

void SpriteGo::Release()
{
}

void SpriteGo::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
}

void SpriteGo::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		setPosition({ 0.f,0.f });
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		setPosition({ 500.f,500.f });
	}
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	if (active)
	{
		window.draw(sprite);
	}
}