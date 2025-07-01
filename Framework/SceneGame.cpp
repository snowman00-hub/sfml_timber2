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
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");

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
// 누르고 있을 때 도끼 보이기
// 충돌 시 비석
// 죽었을 때 입력 안받고, 리턴시 재시작

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

void SceneGame::Update(float dt)
{
    Scene::Update(dt);

    if (InputMgr::GetKeyDown(sf::Keyboard::Left))
    {
        tree->UpdateBranches();
        player->setSide(Sides::Left);
    }

    if (InputMgr::GetKeyDown(sf::Keyboard::Right))
    {
        tree->UpdateBranches();
        player->setSide(Sides::Right);
    }

    if (tree->GetSide() == player->getSide())
    {
        std::cout << "충돌" << std::endl;
    }
}