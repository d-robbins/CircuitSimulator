#include "LogicGate.h"

CLogicGate::CLogicGate(sf::Vector2f pos, const std::string& fileLocation)
	: CPinnedComponent(pos, fileLocation)
{
}

CLogicGate::CLogicGate(sf::Vector2f pos, const sf::Texture& texture)
	: CPinnedComponent(pos, texture)
{
}

void CLogicGate::ReceivePower(bool pow)
{
	if (pow && mLogicGood)
	{
		this->PropogatePower(pow);
	}
}
