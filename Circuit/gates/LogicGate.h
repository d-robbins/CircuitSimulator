#pragma once

#include "../PinnedComponent.h"


class CLogicGate : public CPinnedComponent
{
public:
	CLogicGate(sf::Vector2f pos, const std::string& fileLocation = "../images/default.png");
	virtual ~CLogicGate() {}

	virtual void ReceivePower(bool pow) override;

	void SetState(bool val) {mState = val;}
	bool GetState() const {return mState;}

private:
	bool mLogicGood = false;
	bool mState = false;
};

