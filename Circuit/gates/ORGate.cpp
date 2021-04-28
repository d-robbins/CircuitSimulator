#include "ORGate.h"

CORGate::CORGate(sf::Vector2f pos, const sf::Texture& texture)
	: CLogicGate(pos, texture)
{
	auto spacing = GetHeight() / 2;
	CPinIn ipin1(sf::Vector2f(0.0f, (float)(GetHeight() / 2) - 20), this);
	CPinIn ipin2(sf::Vector2f(0.0f, (float)(GetHeight() / 2) + 10), this);
	CPinOut opin3(sf::Vector2f((float)GetWidth(), -5.0f + (float)GetHeight() / 2.0f), this);

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
