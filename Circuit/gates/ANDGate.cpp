#include "ANDGate.h"

CANDGate::CANDGate(sf::Vector2f pos, const std::string& fileLocation) 
	: CLogicGate(pos, fileLocation)
{
	AddInputPin(sf::Vector2f(-GetWidth() / 2, -GetHeight() / 2 - 20));
	AddInputPin(sf::Vector2f(-GetWidth() / 2, -GetHeight() / 2 + 10));
	AddOutputPin();
}

void CANDGate::ReceivePower(bool pow)
{
	if (!pow)
	{
		PropogatePower(pow);
	}
	else
	{
		auto pins = GetInputPins();

		if (pins[0]->PowerOn() && pins[1]->PowerOn())
		{
			std::cout << "AND Gate Received Power\n";
			this->PropogatePower(pow);
		}
	}
}
