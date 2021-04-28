#pragma once

#include "LogicGate.h"

class CANDGate : public CLogicGate
{
public:
	CANDGate(sf::Vector2f pos, const sf::Texture& texture);
	virtual ~CANDGate() {}

	virtual void ReceivePower(bool pow) override;

private:

};

