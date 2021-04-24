#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "Pin.h"

class CPinnedComponent;
class CPinIn : public CPin
{
public:
	CPinIn(sf::Vector2f position, const std::string& fileLocation = "../images/default.png");
	CPinIn(sf::Vector2f position, CPinnedComponent* mComp, const std::string& file = "../images/default.png");
	~CPinIn() {}

	sf::Vector2f GetCompPos();
private:
	CPinnedComponent* mComp = nullptr;
};

