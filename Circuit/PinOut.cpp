#include "PinOut.h"

#include "PinnedComponent.h"

#include "Wire.h"

CPinOut::CPinOut(sf::Vector2f position, CPinnedComponent* comp)
	: CPin(position, comp)
{
	SetPinColor(sf::Color::Red);
}

void CPinOut::ProcessPower(bool power)
{
	for (auto i : mWires)
	{
		i->PropogatePower(power);
	}
}

void CPinOut::AddWire(std::shared_ptr<CWire> wire)
{
	mWires.push_back(wire);
	wire->PowerIn(this);
}
