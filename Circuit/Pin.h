#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "Component.h"

class CWire;
class CPin : public CComponent
{
public:
	CPin(sf::Vector2f position, const std::string& fileLocation = "../images/default.png");
	virtual void ProcessPower(bool power) {}
	~CPin() {}

	void SetPinPos(sf::Vector2f pos) { mPos = pos; }
	sf::Vector2f GetPinPos() { return mPos; }

	int GetPinWidth() { return this->GetWidth(); }
private:
	sf::Vector2f mPos;
};

