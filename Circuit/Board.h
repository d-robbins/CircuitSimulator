#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"
#include "PinnedComponent.h"
#include "Wire.h"
#include <vector>
#include <memory>

class CBoard
{
public:	
	CBoard();
	~CBoard() {}

	void Render(sf::RenderWindow& window, sf::Event& evnt);

	void AddComponent(std::shared_ptr<CPinnedComponent> c);

	void OnClick(const sf::Vector2f& mousePos);

	void SendPower(std::shared_ptr<CPinnedComponent> comp);

	void WireMode(bool on);
private:
	std::vector<std::shared_ptr<CPinnedComponent>> mComponents;
	std::shared_ptr<CPinnedComponent>* mGrabbed = nullptr;
	std::vector<std::shared_ptr<CWire>> mWires;
			

	bool mWireMode = false;
};

