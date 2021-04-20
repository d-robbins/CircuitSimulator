#include "Board.h"

#include <SFML/Window.hpp>


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
		if (!mWireMode)
		{
			for (auto &comp : mComponents)
			{
				if (comp->HitTest(mousePos))
				{
					mGrabbed = &comp;
					break;
				}
			}
		}
		else
		{
			if (mWires.back()->Good())
			{
				mWireMode = false;
			}
			else
			{
				for (auto i : mComponents)
				{
					if (i->PinInHitTest(mousePos) != nullptr)
					{
						mWires.back()->SetInputPin(i->PinInHitTest(mousePos));
					}

					if (i->PinOutHitTest(mousePos) != nullptr)
					{
						mWires.back()->SetOutputPin(i->PinOutHitTest(mousePos));
					}
				}
			}
		}
	}
	else
	{
		mGrabbed = nullptr;
	}
}

void CBoard::SendPower(std::shared_ptr<CPinnedComponent> comp)
{
	comp->SendPower(true);
}

void CBoard::WireMode(bool on)
{
	mWireMode = on;

	if (on)
		this->mWires.push_back(std::make_shared<CWire>());
}
