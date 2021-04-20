#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"
#include "PinnedComponent.h"
#include <vector>
#include <memory>

class CBoard
{
public:	
	CBoard();
	~CBoard() {}

	void Render(sf::RenderWindow& window, sf::Event& evnt);

	void AddComponent(std::shared_ptr<CComponent> c);

	void OnClick(const sf::Vector2f& mousePos);

	void SendPower(std::shared_ptr<CPinnedComponent> comp);
private:
	std::vector<std::shared_ptr<CComponent>> mComponents;
	std::shared_ptr<CComponent>* mGrabbed = nullptr;
};

