#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string& Id, const std::string& name)
	: GameObject(name), fontId(Id)
{
}

void TextGo::SetCharSize(int size)
{
	text.setCharacterSize(size);
	Utils::SetOrigin(text, originPreset);
}

void TextGo::SetString(const std::string& str)
{
	text.setString(str);
	Utils::SetOrigin(text, originPreset);
}

void TextGo::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	text.setPosition(pos);
}

void TextGo::SetRotation(float rot)
{
	rotation = rot;
	text.setRotation(rot);
}

void TextGo::SetScale(const sf::Vector2f& s)
{
	scale = s;
	text.setScale(s);
}

void TextGo::SetOrigin(const sf::Vector2f& o)
{
	originPreset = Origins::Custom;
	origin = o;
	text.setOrigin(o);
}

void TextGo::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(text, originPreset);
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
	Utils::SetOrigin(text, originPreset);
}

void TextGo::Update(float dt)
{
}

void TextGo::Draw(sf::RenderWindow& window)
{
	if (active)
	{
		window.draw(text);
	}
}