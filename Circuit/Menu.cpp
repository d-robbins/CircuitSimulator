#include "Menu.h"

#include "Board.h"

#include "gates/ANDGate.h"
#include "gates/ORGate.h"

#include "PinIn.h"
#include "PinOut.h"


CMenu::CMenu(CBoard* board) : mBoard(board)
{
	// Setup menu for board
	mButtons.push_back(Button(mDefault, "AND", "../images/and-button.png"));
	mButtons.push_back(Button(mDefault, "OR", "../images/or-button.png"));
	mButtons.back().SetPosition(sf::Vector2f(0, 110));

	mAND = std::make_shared<sf::Texture>();
	mOR = std::make_shared<sf::Texture>();

	mAND->loadFromFile("../images/and.png");
	mOR->loadFromFile("../images/or.png");
}

void CMenu::Render(sf::RenderWindow& window)
{
	for (auto i : mButtons)
	{
		i.Render(window);
	}
}

void CMenu::OnClick(sf::Vector2f pos)
{
	std::string op;

	for (auto i : mButtons)
	{
		if (i.HitTest(pos))
		{
			op = i.GetFunction();
			break;
		}
	}

	if (op != "")
	{
		if (op == "AND")
		{
			auto comp = std::make_shared<CANDGate>(sf::Vector2f(200, 200), *(mAND.get()));

			mBoard->AddComponent(comp);
		}
		else if (op == "OR")
		{
			auto comp = std::make_shared<CORGate>(sf::Vector2f(200, 200), *(mOR.get()));
			mBoard->AddComponent(comp);
		}
	}
}

CMenu::Button::Button(sf::Vector2f position, const std::string& function, const std::string& fileLocation)
	: mFunc(function)
{
	mButton = std::make_shared<CComponent>(position, fileLocation);
}

void CMenu::Button::Render(sf::RenderWindow& window)
{
	mButton->Render(window);
}
