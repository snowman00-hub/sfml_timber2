#pragma once
#include "GameObject.h"

class Player : public GameObject
{
protected:
	sf::Sprite sprite;
	sf::Sprite axeSprite;

	Sides side = Sides::Right;

	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> axePositions;
	std::vector<sf::Vector2f> scales;

	std::string textureId;
	std::string axeTexId;

	bool isAxe = false;

public:
	Player(const std::string& name = "");
	~Player() override = default;

	void SetSide(Sides s);
	Sides GetSide() const { return side; }

	void SetPosition(const sf::Vector2f& pos) override;

	void SetSprite(const std::string& id) { sprite.setTexture(TEXTURE_MGR.Get(id)); }
	void SetRipScale() { sprite.setScale({ 1.f,1.f }); }
	void SetAxeFalse() { isAxe = false; }
	
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

