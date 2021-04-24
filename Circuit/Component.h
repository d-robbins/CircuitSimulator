#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "PinVisitor.h"

class CComponent
{
public:
	CComponent(sf::Vector2f position, const std::string& fileLocation = "../images/default.png");
	~CComponent() {}

	virtual void Accept(CPinVisitor* visitor) {};

	virtual void SetPosition(const sf::Vector2f& pos)
	{
		mSprite.setPosition(pos);
	}

	void DisplayPosition() const
	{
		std::cout << mSprite.getPosition().x << " " << mSprite.getPosition().y << std::endl;
	}

	virtual void Render(sf::RenderWindow& context);

	void SetColor(sf::Color col) { }

	virtual bool HitTest(const sf::Vector2f& pos);
	
	sf::Vector2f GetPosition() const { return mSprite.getPosition(); }

	void SetSize(sf::Vector2f size);

	int GetHeight() const { return mSprite.getTextureRect().height; }
	int GetWidth() const { return mSprite.getTextureRect().width; }

private:
	/// Sprite for this component
	sf::Sprite mSprite;

	/// Texture for this sprite
	sf::Texture mTexture;
};

