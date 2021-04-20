#include "PinnedComponent.h"

#include "Wire.h"

CPinnedComponent::CPinnedComponent(sf::Vector2f pos)
	: CComponent(pos)
{
	
}

void CPinnedComponent::Render(sf::RenderWindow& context)
{
	CComponent::Render(context);

	for (auto i : mInputPins)
	{
		i->SetPos(sf::Vector2f(GetPosition().x - 40, GetPosition().y + (GetHeight() / 2) - 5));
		i->Render(context);
	}

	for (auto i : mOutputPins)
	{
		i->SetPos(sf::Vector2f(GetPosition().x + GetWidth(), GetPosition().y + (GetHeight() / 2) - 5));
		i->Render(context);
	}
	
}

void CPinnedComponent::ReceivePower(bool pow)
{
	if (pow)
	{
		this->SetColor(sf::Color::Red);
	}
	else
	{
		this->SetColor(sf::Color::Black);
	}
}

void CPinnedComponent::CreateInputPin()
{
	auto pin = std::make_shared<InputPin>(this);
	mInputPins.push_back(pin);
}

void CPinnedComponent::CreateOutputPin()
{
	auto pin = std::make_shared<OutputPin>(this);
	mOutputPins.push_back(pin);
}

void CPinnedComponent::AttachWireInput(CWire* wire)
{
	wire->SetInputPin(mInputPins[0].get());
}

void CPinnedComponent::AttachWireOutput(CWire* wire)
{
	wire->SetOutputPin(mOutputPins[0].get());
}

void CPinnedComponent::SendPower()
{
	mOutputPins[0]->PropogatePower(true);
}

void CPinnedComponent::OutputPin::PropogatePower(bool pow)
{
	if (mWire != nullptr)
	{
		mWire->PropogatePower(pow);
	}
}
