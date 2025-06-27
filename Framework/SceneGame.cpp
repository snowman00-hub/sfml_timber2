#include "stdafx.h"
#include "SceneGame.h"
#include "TextGo.h"

SceneGame::SceneGame()
	: Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    SpriteGo* spriteGo = new SpriteGo("graphics/player.png");
    spriteGo->setOrigin(Origins::ML);

    TextGo* textGo = new TextGo("fonts/KOMIKAP_.ttf");
    textGo->setColor(sf::Color::Red);
    textGo->setString("Hello");
    textGo->setCharSize(100);
    textGo->setPosition(sf::Vector2f(600.f, 360.f));
    textGo->setOrigin(Origins::ML);

    AddGameObject(spriteGo);
    AddGameObject(textGo);

    Scene::Init();
}
