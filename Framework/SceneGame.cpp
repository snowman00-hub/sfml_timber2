#include "stdafx.h"
#include "SceneGame.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Bee.h"
#include "Player.h"

SceneGame::SceneGame()
	: Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/player.png");

    AddGameObject(new SpriteGo("graphics/background.png"));
    for (int i = 0; i < 3; i++)
    {
        AddGameObject(new BackgroundElement("graphics/cloud.png"));
    }
    tree = (Tree*)AddGameObject(new Tree());
    AddGameObject(new Bee("graphics/bee.png"));
    player = (Player*)AddGameObject(new Player());

    Scene::Init();
}

void SceneGame::Enter()
{
    Scene::Enter();

    sf::Vector2f pos = tree->getPosition();
    pos.y = 950.f;

    player->setPosition(pos);
}

void SceneGame::Exit()
{
    Scene::Exit();
}