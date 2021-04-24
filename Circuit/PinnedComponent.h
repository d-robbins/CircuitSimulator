#pragma once

#include "Component.h"
#include "PinIn.h"
#include "PinOut.h"

#include <vector>

class CWire;

class CPinnedComponent : public CComponent
{
public:
	CPinnedComponent(sf::Vector2f pos);
	~CPinnedComponent() {}

	virtual void Render(sf::RenderWindow& context) override;

	void ReceivePower(bool pow);

	void AddInputPin();
	void AddOutputPin();

	bool InPinHitTest(sf::Vector2f pos);
	bool OutPinHitTest(sf::Vector2f pos);

	virtual void Accept(CPinVisitor* visitor) override { visitor->VisitPinnedComponent(this); };

	CPinOut* GetLOut() { return mLOut; }
	CPinIn* GetLIn() { return mLIn; }
private:
	void UpdatePin();

	CPinIn* mLIn = nullptr;
	CPinOut* mLOut = nullptr;

	sf::Vector2f mInLoc, mOutLoc;
	std::vector<std::shared_ptr<CPinIn>> mInputPins;
	std::vector<std::shared_ptr<CPinOut>> mOutputPins;
};

