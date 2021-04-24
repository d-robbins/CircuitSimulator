#pragma once

#include "SFML/Graphics.hpp"
#include "Pin.h"

class CPinOut : public CPin
{
public:
	CPinOut(sf::Vector2f position, const std::string& fileLocation = "../images/default.png");
	~CPinOut() {}
private:

};

