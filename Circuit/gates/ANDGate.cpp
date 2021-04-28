#include "ANDGate.h"

#include "../PinIn.h"
#include "../PinOut.h"

CANDGate::CANDGate(sf::Vector2f pos, const std::string& fileLocation) 
	: CLogicGate(pos, fileLocation)
{
	CPinIn ipin1(sf::Vector2f(-20, (GetHeight() / 2) - 20), this);
	CPinIn ipin2(sf::Vector2f(-20, (GetHeight() / 2) + 10), this);
	CPinOut opin3(sf::Vector2f(GetWidth(), -5 + GetHeight() / 2), this);

	this->AddInputPin(ipin1);
	this->AddInputPin(ipin2);
	this->AddOutputPin(opin3);
}

void CANDGate::ReceivePower(bool pow)
{
	if (!pow)
	{
		PropogatePower(pow);
		SetState(pow);
	}
	else
	{
		auto pins = GetInputPins();

		if (pins[0].PowerOn() && pins[1].PowerOn())
		{
			std::cout << "AND Gate Received Power\n";
			SetState(pow);
			this->PropogatePower(pow);
		}
	}
}
