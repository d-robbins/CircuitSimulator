#pragma once

#include "LogicGate.h"

class CANDGate : public CLogicGate
{
public:
	CANDGate(sf::Vector2f pos, const std::string& fileLocation = "../images/default.png");
	virtual ~CANDGate() {}

	virtual void ReceivePower(bool pow) override;

private:

};

