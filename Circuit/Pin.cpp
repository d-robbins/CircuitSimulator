#include "Pin.h"

CPin::CPin(sf::Vector2f position, const std::string& fileLocation) : CComponent (position, fileLocation)
{
	this->SetPinPos(position);
}
