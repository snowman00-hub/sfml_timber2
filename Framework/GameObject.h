#pragma once

class GameObject
{
protected:
	std::string name;
	bool active;

	sf::Vector2f position;
	float rotation = 0.f;
	sf::Vector2f scale;
	sf::Vector2f origin;

	Origins originPreset = Origins::TL;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject();

	std::string GetName() const { return name; }
	void SetName(const std::string& n) { name = n; }

	bool GetActive() const { return active; }
	void SetActive(bool a) { active = a; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }

	float GetRotation() const { return rotation; }
	virtual void SetRotation(float r) { rotation = r; }

	sf::Vector2f GetScale() const { return scale; }
	virtual void SetScale(const sf::Vector2f& s) { scale = s; }

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(const sf::Vector2f& o) { origin = o; }
	virtual void SetOrigin(Origins preset) { originPreset = preset; }

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Reset() = 0;

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};