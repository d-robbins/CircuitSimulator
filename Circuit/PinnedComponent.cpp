#include "PinnedComponent.h"

#include "Wire.h"


CPinnedComponent::CPinnedComponent(sf::Vector2f pos)
	: CComponent(pos)
{
	mInLoc = sf::Vector2f(-GetWidth() / 2, GetHeight() / 2);
	mOutLoc = sf::Vector2f(GetWidth() / 2, GetHeight() / 2);
}

void CPinnedComponent::Render(sf::RenderWindow& context)
{
	UpdatePin();
	
	for (auto i : mInputPins)
	{
		i->Render(context);
	}

	for (auto i : mOutputPins)
	{
		i->Render(context);
	}
	
	CComponent::Render(context);
}

void CPinnedComponent::ReceivePower(bool pow)
{
	std::cout << "Component Recieved Power!\n";
}

void CPinnedComponent::AddInputPin()
{
	mInputPins.push_back(std::make_shared<CPinIn>(GetPosition() + mInLoc
		, this, "../images/ipin.png"));
}

void CPinnedComponent::AddOutputPin()
{
	mOutputPins.push_back(std::make_shared<CPinOut>(GetPosition() + mOutLoc, "../images/opin.png"));
}

bool CPinnedComponent::InPinHitTest(sf::Vector2f pos)
{
	for (auto& i : mInputPins)
	{
		if (i->HitTest(pos))
		{
			mLIn = i.get();
			return true;
		}
	}

	return false;
}

bool CPinnedComponent::OutPinHitTest(sf::Vector2f pos)
{
	for (auto &i : mOutputPins)
	{
		if (i->HitTest(pos))
		{
			mLOut = i.get();
			return true;
		}
	}

	return false;
}

void CPinnedComponent::UpdatePin()
{
	for (auto i : mInputPins)
	{
		i->SetPosition(GetPosition() + mInLoc);
	}
	
	for (auto i : mOutputPins)
	{
		i->SetPosition(GetPosition() + mOutLoc);
	}

}

