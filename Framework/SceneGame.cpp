#include "stdafx.h"
#include "SceneGame.h"
#include "TextGo.h"
#include "SpriteGo.h"

SceneGame::SceneGame()
	: Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    texIds.push_back("graphics/player.png");
    fontIds.push_back("fonts/KOMIKAP_.ttf");

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

void SceneGame::Enter()
{
    Scene::Enter();
}

void SceneGame::Exit()
{
    Scene::Exit();
}