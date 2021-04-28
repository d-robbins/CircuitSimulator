#pragma once

#include <memory>
#include "SFML/Graphics.hpp"
#include "Pin.h"

class CPinnedComponent;
class CPinIn : public CPin
{
public:
	CPinIn(sf::Vector2f position, CPinnedComponent* comp);
	~CPinIn() {}

	void ReceivePower(bool power);

	void SetWire(CWire* wire);

	bool PowerOn() { return mPower; }
private:
	CWire* mWire = nullptr;
	bool mPower = false;
};

