#include "PinnedComponent.h"

#include "Wire.h"


CPinnedComponent::CPinnedComponent(sf::Vector2f pos, const std::string& fileLocation)
	: CComponent(pos, fileLocation)
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
	std::cout << "Pinned Component Recieved Power!\n";

	for (auto i : mOutputPins)
	{
		i->ProcessPower(pow);
	}
}

void CPinnedComponent::AddInputPin(sf::Vector2f pos)
{
	mInputPins.push_back(std::make_shared<CPinIn>(GetPosition() + pos
		, this, "../images/ipin.png"));
	
	if (pos == sf::Vector2f(0, 0))
	{
		pos = mInLoc;
		mInputPins.back()->SetPinPos(mInLoc);
	}
}

void CPinnedComponent::AddOutputPin(sf::Vector2f pos)
{
	mOutputPins.push_back(std::make_shared<CPinOut>(GetPosition() + pos, "../images/opin.png"));

	if (pos == sf::Vector2f(0, 0))
	{
		pos = mInLoc;
		mOutputPins.back()->SetPinPos(mOutLoc);
	}
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

void CPinnedComponent::PropogatePower(bool power)
{
	for (auto i : mOutputPins)
	{
		i->ProcessPower(power);
	}
}

void CPinnedComponent::UpdatePin()
{
	for (auto i : mInputPins)
	{
		i->SetPosition(GetPosition() + i->GetPinPos());
	}
	
	for (auto i : mOutputPins)
	{
		i->SetPosition(GetPosition() + i->GetPinPos());
	}

}

