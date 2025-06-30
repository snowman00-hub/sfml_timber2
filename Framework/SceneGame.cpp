#include "stdafx.h"
#include "SceneGame.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "BackgroundElement.h"

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

    AddGameObject(new SpriteGo("graphics/background.png"));

    auto element = (BackgroundElement*)AddGameObject(new BackgroundElement("graphics/cloud.png"));
    element->speed = 100.f;
    element->direction = { 1.f,0.f };

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