#pragma once

#include <SFML/Graphics.hpp>

#include "Component.h"
#include <vector>

class CBoard;

class CMenu
{
public:
	CMenu(CBoard* board);
	~CMenu() {}

	void Render(sf::RenderWindow& window);

	void OnClick(sf::Vector2f pos);
	
	class Button
	{
	public:
		Button(sf::Vector2f position, const std::string& function, const std::string& fileLocation = "../images/default.png");
		~Button() {}

		bool HitTest(const sf::Vector2f& pos) { return mButton->HitTest(pos); }
		std::string GetFunction() const { return mFunc; }
		void Render(sf::RenderWindow& window);
		void SetPosition(sf::Vector2f pos) { mButton->SetPosition(pos); }
	private:
		std::string mFunc = "";
		std::shared_ptr<CComponent> mButton;
	};


private:
	std::vector<Button> mButtons;
	sf::Vector2f mDefault = sf::Vector2f(100, 100);
	CBoard* mBoard = nullptr;
};

