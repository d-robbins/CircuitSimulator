#pragma once

#include "PinVisitor.h"

#include "PinOut.h"

class COutPinVisitor : public CPinVisitor
{
public:
	virtual void VisitPinnedComponent(CPinnedComponent* pinned) override;
	CPinOut* GetPin() { if (mPin != nullptr) return mPin; else return nullptr; }
	void SetLoc(sf::Vector2f pos) { mCoord = pos; }
private:
	sf::Vector2f mCoord = sf::Vector2f(0,0);
	CPinOut* mPin = nullptr;
};

