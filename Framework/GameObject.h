#pragma once

class GameObject
{
protected:
	std::string name;
	bool active;

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
	sf::Vector2f origin;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject();

	std::string getName() const { return name; }
	void setName(const std::string& n) { name = n; }

	bool getActive() const { return active; }
	void setActive(bool a) { active = a; }

	sf::Vector2f getPosition() const { return position; }
	virtual void setPosition(const sf::Vector2f& pos) { position = pos; }

	float getRotation() const { return rotation; }
	virtual void setRotation(float r) { rotation = r; }

	sf::Vector2f getScale() const { return scale; }
	virtual void setScale(const sf::Vector2f& s) { scale = s; }

	sf::Vector2f getOrigin() const { return origin; }
	virtual void setOrigin(const sf::Vector2f& o) { origin = o; }

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Reset() = 0;

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};