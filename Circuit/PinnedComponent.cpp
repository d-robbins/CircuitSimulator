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
	std::cout << "Component Recieved Power!\n";
}

CPinnedComponent::InputPin* CPinnedComponent::PinInHitTest(const sf::Vector2f& pos)
{
	for (auto& i : mInputPins)
	{
		if (i->GetGlobalBound().contains(pos))
		{
			return i.get();
			break;
		}
	}

	return nullptr;
}

CPinnedComponent::OutputPin* CPinnedComponent::PinOutHitTest(const sf::Vector2f& pos)
{
	for (auto& i : mOutputPins)
	{
		if (i->GetGlobalBound().contains(pos))
		{
			return i.get();
			break;
		}
	}

	return nullptr;
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

void CPinnedComponent::SendPower(bool pow)
{
	mOutputPins[0]->PropogatePower(pow);
}

void CPinnedComponent::OutputPin::PropogatePower(bool pow)
{
	if (mWire != nullptr)
	{
		mWire->PropogatePower(pow);
	}
}
