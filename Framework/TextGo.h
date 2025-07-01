#pragma once
#include "GameObject.h"

class TextGo : public GameObject
{
protected:
	sf::Text text;
	std::string fontId;

public:
	TextGo(const std::string& Id = "", const std::string& name = "");
	~TextGo() override = default;

	const std::string& GetFontId() const { return fontId; }
	void SetFontId(const std::string& Id) { fontId = Id; }
	const sf::Color& GetColor() const { return text.getFillColor(); }
	void SetColor(const sf::Color& color) { text.setFillColor(color); }
	int GetCharSize() const { return text.getCharacterSize(); }
	void SetCharSize(int size);
	const std::string& GetString() const { return text.getString(); }
	void SetString(const std::string& str);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float rot) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;
	void SetOrigin(Origins preset) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};
