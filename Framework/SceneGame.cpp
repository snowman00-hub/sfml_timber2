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

void SceneGame::Enter()
{
    Scene::Enter();

    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.f;

    player->SetPosition(pos);
}

void SceneGame::Exit()
{
    Scene::Exit();
}

void SceneGame::Update(float dt)
{
    if (isActive)
    {
        Scene::Update(dt);

        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Left);
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Right);
        }

        if (tree->GetSide() == player->GetSide())
        {
            player->SetSprite("graphics/rip.png");
            player->SetAxeFalse();
            player->SetRipScale();
            isActive = false;
        }
    }
    else
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Return))
        {
            isActive = true;
            tree->Reset();
            player->Reset();            
        }
    }
}