#include "ORGate.h"

CORGate::CORGate(sf::Vector2f pos, const std::string& fileLocation)
	: CLogicGate(pos, fileLocation)
{
	auto spacing = GetHeight() / 2;
	CPinIn ipin1(sf::Vector2f(0, (GetHeight() / 2) - 20), this);
	CPinIn ipin2(sf::Vector2f(0, (GetHeight() / 2) + 10), this);
	CPinOut opin3(sf::Vector2f(GetWidth(), -5 + GetHeight() / 2), this);

	this->AddInputPin(ipin1);
	this->AddInputPin(ipin2);
	this->AddOutputPin(opin3);
}

void CORGate::ReceivePower(bool pow)
{
	if (!pow)
	{
		PropogatePower(pow);
		SetState(pow);
	}
	else
	{
		auto pins = this->GetInputPins();

		if (pins[0].PowerOn() || pins[1].PowerOn())
		{
			std::cout << "OR Gate Receieved Power!\n";
			this->PropogatePower(pow);
			SetState(pow);
		}
	}
}
