#include "LogicGate.h"

CLogicGate::CLogicGate(sf::Vector2f pos, const std::string& fileLocation)
	: CPinnedComponent(pos, fileLocation)
{
}

void CLogicGate::ReceivePower(bool pow)
{
	if (pow && mLogicGood)
	{
		this->PropogatePower(pow);
	}
}
