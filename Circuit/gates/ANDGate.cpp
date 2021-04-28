#include "ANDGate.h"

#include "../PinIn.h"
#include "../PinOut.h"

CANDGate::CANDGate(sf::Vector2f pos, const sf::Texture& texture)
	: CLogicGate(pos, texture)
{
	CPinIn ipin1(sf::Vector2f(-20.0f, ((float)GetHeight() / 2) - 20.0f), this);
	CPinIn ipin2(sf::Vector2f(-20.0f, ((float)GetHeight() / 2) + 10.0f), this);
	CPinOut opin3(sf::Vector2f((float)GetWidth(), -5.0f + (float)GetHeight() / 2.0f), this);

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
