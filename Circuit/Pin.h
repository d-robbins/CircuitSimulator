#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "Component.h"

class CWire;
class CPinnedComponent;
class CPin
{
public:
	CPin(sf::Vector2f position, CPinnedComponent* comp);
	virtual void ProcessPower(bool power) {}
	~CPin() {}

	void SetPinPos(sf::Vector2f pos) { mPos = pos; }
	sf::Vector2f GetPinPos() { return mPos; }

	bool HitTest(sf::Vector2f pos);

	void SetPinColor(sf::Color col) { mShape.setFillColor(col); }

	virtual void Render(sf::RenderWindow& window);

	float GetPinWidth() { return this->mShape.getGlobalBounds().width; }

	sf::Vector2f GetPinComponentPos();

protected:
	CPinnedComponent* GetPinComp() { return mComp; }
private:
	sf::Vector2f mPos;
	sf::RectangleShape mShape;
	CPinnedComponent* mComp = nullptr;
};

