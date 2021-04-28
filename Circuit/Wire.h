#pragma once

#include "SFML/Graphics.hpp"

#include "PinIn.h"
#include "PinOut.h"

#include <vector>

class CWire
{
public:
	CWire();
	~CWire() {}

	void Render(sf::RenderWindow& context);

	void PropogatePower(bool power);
	
	void PowerOut(CPinIn* pin) { mIn = pin; pin->SetWire(this); }
	void PowerIn(CPinOut* pin) { mOut = pin; }

	bool Good() { return ((mIn != nullptr) && (mOut != nullptr)); }

private:
	CPinIn* mIn = nullptr; /// Power goes out wire into this pin
	CPinOut* mOut = nullptr; /// Power goes through this pin into wire

	bool mReadyToDraw = false;

	bool mState = false;
};

