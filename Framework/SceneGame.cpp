#include "stdafx.h"
#include "SceneGame.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Bee.h"
#include "Player.h"
#include "UiHud.h"

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

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	AddGameObject(new SpriteGo("graphics/background.png"));
	for (int i = 0; i < 3; i++)
	{
		AddGameObject(new BackgroundElement("graphics/cloud.png"));
	}
	tree = (Tree*)AddGameObject(new Tree());
	AddGameObject(new Bee("graphics/bee.png"));
	player = (Player*)AddGameObject(new Player());

	uiHud = (UiHud*)AddGameObject(new UiHud());

	Scene::Init();
}

void SceneGame::Enter()
{
	Scene::Enter();

	sf::Vector2f pos = tree->GetPosition();
	pos.y = 900.f;
	player->SetPosition(pos);

	score = 0;
	uiHud->SetScore(score);

	timer = timerMax;
	uiHud->SetTimeBar(timer / timerMax);

	uiHud->SetShowMessage(true);
	uiHud->SetMesage("Enter to Start!");
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	if (isPlaying)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			tree->UpdateBranches();
			player->SetSide(Sides::Left);			
			score += 10;
			uiHud->SetScore(score);
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			tree->UpdateBranches();
			player->SetSide(Sides::Right);
			score += 10;
			uiHud->SetScore(score);
		}

		if (tree->GetSide() == player->GetSide())
		{
			player->SetAlive(false);
			player->SetDrawAxe(false);
			isPlaying = false;
			FRAMEWORK.SetTimeScale(0.f);

			uiHud->SetShowMessage(true);
			uiHud->SetMesage("Enter to Restart!");
		}

		if (InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right))
		{
			player->SetDrawAxe(true);
		}		

		timer -= dt;
		if (timer <= 0.f)
		{
			timer = 0.f; 
			player->SetAlive(false);
			player->SetDrawAxe(false);
			isPlaying = false;
			FRAMEWORK.SetTimeScale(0.f);

			uiHud->SetShowMessage(true);
			uiHud->SetMesage("Enter to Restart!");
		}
		uiHud->SetTimeBar(timer / timerMax);
	}
	else
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Return))
		{
			isPlaying = true;
			FRAMEWORK.SetTimeScale(1.f);
			player->Reset();
			tree->Reset();

			score = 0;
			uiHud->SetScore(score);
			timer = timerMax;
			uiHud->SetTimeBar(timer / timerMax);

			uiHud->SetShowMessage(false);
		}
	}
}