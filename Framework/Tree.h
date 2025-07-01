#pragma once
#include "GameObject.h"

class Tree : public GameObject
{
protected:
	sf::Sprite tree;
	std::vector<sf::Sprite> branches;
	std::vector<Sides> branchesSide;

	std::string texIdTree;
	std::string texIdBranches;

public:
	Tree() = default;
	~Tree() override = default;

	void setPosition(const sf::Vector2f& pos) override;
	Sides UpdateBranches();

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};