#pragma once
#include "Scene.h"

class Player;
class Tree;

class SceneGame : public Scene
{
protected:
	Player* player;
	Tree* tree;

public:
	SceneGame();
	~SceneGame() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
};

