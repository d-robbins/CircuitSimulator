#include "Board.h"

#include <SFML/Window.hpp>
#include "InPinVisitor.h"
#include "OutPinVisitor.h"


CBoard::CBoard()
{

}

void CBoard::Render(sf::RenderWindow& window, sf::Event& evnt)
{
	if (mGrabbed != nullptr)
	{
		(*mGrabbed)->SetPosition(sf::Vector2f(evnt.mouseMove.x, evnt.mouseMove.y));
	}

	for (auto i : mWires)
	{
		i->Render(window);
	}
	

	for (auto i : mComponents)
	{
		i->Render(window);
	}
}

void CBoard::AddComponent(std::shared_ptr<CPinnedComponent> c)
{
	this->mComponents.push_back(c);
}

void CBoard::OnClick(const sf::Vector2f& mousePos)
{
	if (mGrabbed == nullptr)
	{
		for (auto &comp : mComponents)
		{
			if (!mWireMode)
			{
				if (comp->HitTest(mousePos))
				{
					mGrabbed = &comp;
					break;
				}
			}
			else
			{
				CInPinVisitor ivisitor;
				ivisitor.SetLoc(mousePos);
				for (auto i : mComponents)
				{
					i->Accept(&ivisitor);
				}

				COutPinVisitor ovisitor;
				ovisitor.SetLoc(mousePos);
				for (auto i : mComponents)
				{
					i->Accept(&ovisitor);
				}

				CPinIn* ipin = nullptr;
				CPinOut* opin = nullptr;

				ipin = ivisitor.GetPin();
				opin = ovisitor.GetPin();

				if (ipin != nullptr)
				{
					mWires.back()->SetInputPin(ipin);
				}

				if (opin != nullptr)
				{
					mWires.back()->SetOutPut(opin);
				}

				mWireMode = !mWires.back()->Good();
			}
		}
	}
	else
	{
		mGrabbed = nullptr;
	}
}

void CBoard::SendPower(bool power)
{
	mPowerOn = power;
}

void CBoard::Tick(double elapsed)
{
	
}

void CBoard::WireMode(bool on)
{
	mWireMode = on;

	if (on)
		this->mWires.push_back(std::make_shared<CWire>());
}
