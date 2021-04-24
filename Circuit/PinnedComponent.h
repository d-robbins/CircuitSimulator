#pragma once

#include "Component.h"
#include "PinIn.h"
#include "PinOut.h"

#include <vector>

class CWire;

class CPinnedComponent : public CComponent
{
public:
	CPinnedComponent(sf::Vector2f pos, const std::string& fileLocation = "../images/default.png");
	~CPinnedComponent() {}

	virtual void Render(sf::RenderWindow& context) override;

	void AddInputPin(sf::Vector2f pos = sf::Vector2f(0, 0));
	void AddOutputPin(sf::Vector2f pos = sf::Vector2f(0, 0));

	bool InPinHitTest(sf::Vector2f pos);
	bool OutPinHitTest(sf::Vector2f pos);

	virtual void Accept(CPinVisitor* visitor) override { visitor->VisitPinnedComponent(this); };

	virtual void PropogatePower(bool power) override;
	virtual void ReceivePower(bool pow);

	CPinOut* GetLOut() { return mLOut; }
	CPinIn* GetLIn() { return mLIn; }

protected:
	std::vector<std::shared_ptr<CPinIn>> GetInputPins() { return mInputPins; }
private:
	void UpdatePin();

	CPinIn* mLIn = nullptr;
	CPinOut* mLOut = nullptr;

	sf::Vector2f mInLoc, mOutLoc;
	
	std::vector<std::shared_ptr<CPinIn>> mInputPins;
	std::vector<std::shared_ptr<CPinOut>> mOutputPins;
};

