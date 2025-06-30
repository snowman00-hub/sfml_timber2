#include "stdafx.h"
#include "Tree.h"

void Tree::setPosition(const sf::Vector2f& pos)
{
	tree.setPosition(pos);
	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setPosition(pos.x, i * 150.f);
	}
}

void Tree::UpdateBranches()
{
}

void Tree::Init()
{
	texIdTree = "graphics/tree.png";
	texIdBranches = "graphics/branch.png";

	branches.resize(6);
	branchesSide.resize(6);
}

void Tree::Release()
{
}

void Tree::Reset()
{
	tree.setTexture(TEXTURE_MGR.Get(texIdTree), true);
	Utils::setOrigin(tree, Origins::TC);
	sf::FloatRect bounds = tree.getLocalBounds();

	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setTexture(TEXTURE_MGR.Get(texIdBranches));
		branches[i].setOrigin(bounds.width * -0.5f, 0.f);

		branchesSide[i] = (Sides)Utils::RandomRange(0, 3);

		switch (branchesSide[i])
		{
			case Sides::Left:
				branches[i].setScale(-1.f, 1.f);
				break;
			case Sides::Right:
				branches[i].setScale(1.f, 1.f);
				break;
		}
	}
	branchesSide[branches.size() - 1] = Sides::None;

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();
	setPosition({ windowBounds.width * 0.5f,0.f });
}

void Tree::Update(float dt)
{
}

void Tree::Draw(sf::RenderWindow& window)
{
	window.draw(tree);

	for (int i = 0; i < branches.size(); i++)
	{
		if (branchesSide[i] != Sides::None)
		{
			window.draw(branches[i]);
		}
	}
}
