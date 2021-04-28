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
		(*mGrabbed)->SetPosition(sf::Vector2f((float)evnt.mouseMove.x, (float)evnt.mouseMove.y));
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
		if (!mWireMode && !mPowerMode)
		{
			for (auto &comp : mComponents)
			{
				if (comp->HitTest(mousePos) && comp->IsMovable())
				{
					mGrabbed = &comp;
					break;
				}
			}
		}
		else if (mWireMode && !mPowerMode)
		{
			AddWire(mousePos);
		}
		else if (mPowerMode && !mWireMode)
		{
			for (auto& comp : mComponents)
			{
				if (comp->HitTest(mousePos))
				{
					comp->PropogatePower(true);
					mPowerMode = false;
					break;
				}
			}
		}
	}
	else
	{
		mGrabbed = nullptr;
	}
}

void CBoard::PowerToggle(bool power)
{
	mPowerMode = power;
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

void CBoard::AddWire(sf::Vector2f mousePos)
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
		mWires.back()->PowerOut(ipin);
	}

	if (opin != nullptr)
	{
		opin->AddWire(mWires.back());
	}


	mWireMode = !mWires.back()->Good();
}
