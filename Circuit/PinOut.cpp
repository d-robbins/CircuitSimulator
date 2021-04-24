#include "PinOut.h"

#include "PinnedComponent.h"

#include "Wire.h"

CPinOut::CPinOut(sf::Vector2f position, const std::string& fileLocation) 
	: CPin(position, fileLocation)
{
	this->SetColor(sf::Color::Red);
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
	mWires.back()->SetOutPut(this);
}
