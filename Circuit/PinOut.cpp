#include "PinOut.h"

#include "PinnedComponent.h"

CPinOut::CPinOut(sf::Vector2f position, const std::string& fileLocation) 
	: CPin(position, fileLocation)
{
	this->SetColor(sf::Color::Red);
}
