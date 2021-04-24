#pragma once

#include "../PinnedComponent.h"


class CLogicGate : public CPinnedComponent
{
public:
	CLogicGate(sf::Vector2f pos, const std::string& fileLocation = "../images/default.png");
	virtual ~CLogicGate() {}

	virtual void ReceivePower(bool pow) override;

private:
	bool mLogicGood = false;
};

