#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string& Id, const std::string& name)
	: GameObject(name), fontId(Id)
{
	text.setString("");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	Utils::setOrigin(text, originPreset);
}

void TextGo::setCharSize(int size)
{
	text.setCharacterSize(size);
	Utils::setOrigin(text, originPreset);
}

void TextGo::setString(const std::string& str)
{
	text.setString(str);
	Utils::setOrigin(text, originPreset);
}

void TextGo::setPosition(const sf::Vector2f& pos)
{
	position = pos;
	text.setPosition(pos);
}

void TextGo::setRotation(float rot)
{
	rotation = rot;
	text.setRotation(rot);
}

void TextGo::setScale(const sf::Vector2f& s)
{
	scale = s;
	text.setScale(s);
}

void TextGo::setOrigin(const sf::Vector2f& o)
{
	originPreset = Origins::Custom;
	origin = o;
	text.setOrigin(o);
}

void TextGo::setOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::setOrigin(text, originPreset);
	}
}

void TextGo::Init()
{
}

void TextGo::Release()
{
}

void TextGo::Reset()
{
	text.setFont(FONT_MGR.Get(fontId));
	Utils::setOrigin(text, originPreset);
}

void TextGo::Update(float dt)
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

void TextGo::Draw(sf::RenderWindow& window)
{
	if (active)
	{
		window.draw(text);
	}
}