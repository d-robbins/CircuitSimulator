#include "PinnedComponent.h"

#include "Wire.h"


CPinnedComponent::CPinnedComponent(sf::Vector2f pos, const std::string& fileLocation)
	: CComponent(pos, fileLocation)
{
	
}

CPinnedComponent::CPinnedComponent(sf::Vector2f pos, const sf::Texture& texture)
	: CComponent(pos, texture)
{
}

void CPinnedComponent::Render(sf::RenderWindow& context)
{
	CComponent::Render(context);
	
	for (auto i : mInputPins)
	{
		i.Render(context);
	}

	for (auto i : mOutputPins)
	{
		i.Render(context);
	}
}

void CPinnedComponent::ReceivePower(bool pow)
{
	std::cout << "Pinned Component Recieved Power!\n";

	for (auto i : mOutputPins)
	{
		i.ProcessPower(pow);
	}
}

void CPinnedComponent::AddInputPin(CPinIn pin)
{
	mInputPins.push_back(pin);
}

void CPinnedComponent::AddOutputPin(CPinOut pin)
{
	mOutputPins.push_back(pin);
}

bool CPinnedComponent::InPinHitTest(sf::Vector2f pos)
{
	for (auto& i : mInputPins)
	{
		if (i.HitTest(pos))
		{
			mLIn = &i;
			return true;
		}
	}

	return false;
}

bool CPinnedComponent::OutPinHitTest(sf::Vector2f pos)
{
	for (auto &i : mOutputPins)
	{
		if (i.HitTest(pos))
		{
			mLOut = &i;
			return true;
		}
	}

	return false;
}

void CPinnedComponent::PropogatePower(bool power)
{
	for (auto i : mOutputPins)
	{
		i.ProcessPower(power);
	}
}

