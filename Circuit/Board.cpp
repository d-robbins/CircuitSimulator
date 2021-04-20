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

	for (auto i : mComponents)
	{
		i->Render(window);
	}
}

void CBoard::AddComponent(std::shared_ptr<CComponent> c)
{
	this->mComponents.push_back(c);
}

void CBoard::OnClick(const sf::Vector2f& mousePos)
{
	std::cout << "Mouse Position On Click: " << mousePos.x << " " << mousePos.y << std::endl;
	if (mGrabbed == nullptr)
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
		mGrabbed = nullptr;
	}
}

void CBoard::SendPower(std::shared_ptr<CPinnedComponent> comp)
{
	comp->SendPower();
}
