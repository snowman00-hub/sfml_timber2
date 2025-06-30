#include "stdafx.h"
#include "SceneGame.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Bee.h"

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

    AddGameObject(new SpriteGo("graphics/background.png"));
    for (int i = 0; i < 3; i++)
    {
        AddGameObject(new BackgroundElement("graphics/cloud.png"));
    }
    AddGameObject(new Tree());
    AddGameObject(new Bee("graphics/bee.png"));

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