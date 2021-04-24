#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "Component.h"

class CPin : public CComponent
{
public:
	CPin(sf::Vector2f position, const std::string& fileLocation = "../images/default.png");

	~CPin() {}
private:
	
};

