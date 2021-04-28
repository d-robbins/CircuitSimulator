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
	CPinnedComponent(sf::Vector2f pos, const sf::Texture& texture);
	~CPinnedComponent() {}

	virtual void Render(sf::RenderWindow& context) override;

	void AddInputPin(CPinIn pin);
	void AddOutputPin(CPinOut pin);

	bool InPinHitTest(sf::Vector2f pos);
	bool OutPinHitTest(sf::Vector2f pos);

	virtual void Accept(CPinVisitor* visitor) override { visitor->VisitPinnedComponent(this); };

	virtual void PropogatePower(bool power) override;
	virtual void ReceivePower(bool pow);

	CPinOut* GetLOut() { return mLOut; }
	CPinIn* GetLIn() { return mLIn; }

protected:
	std::vector<CPinIn> GetInputPins() { return mInputPins; }
private:
	CPinIn* mLIn = nullptr;
	CPinOut* mLOut = nullptr;

	sf::Vector2f mInLoc, mOutLoc;
	
	std::vector<CPinIn> mInputPins;
	std::vector<CPinOut> mOutputPins;
};

