#include "PinIn.h"

#include "PinnedComponent.h"

CPinIn::CPinIn(sf::Vector2f position, CPinnedComponent* comp)
	:  CPin(position, comp)
{
	
}

void CPinIn::ReceivePower(bool power)
{
	mPower = power;

	GetPinComp()->ReceivePower(power);
}

void CPinIn::SetWire(CWire* wire)
{
	mWire = wire;
}



