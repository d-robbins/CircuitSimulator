#pragma once

#include "SFML/Graphics.hpp"

#include "PinnedComponent.h"

#include <vector>

class CWire
{
public:
	CWire();
	~CWire() {}

	void SetInputPin(CPinnedComponent::InputPin* pin);
	void SetOutputPin(CPinnedComponent::OutputPin* pin);

	void Render(sf::RenderWindow& context);

	void PropogatePower(bool power);

	bool Good();

private:
	CPinnedComponent::InputPin* mInputPin = nullptr;
	CPinnedComponent::OutputPin* mOutputPin= nullptr;

	bool mReadyToDraw = false;

	bool mState = false;
};

