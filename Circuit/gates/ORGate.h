#pragma once

#include "LogicGate.h"

class CORGate : public CLogicGate
{
public:
	CORGate(sf::Vector2f pos, const sf::Texture& texture);
	CORGate() = delete;
	~CORGate() {}

	virtual void ReceivePower(bool pow) override;
private:

};

