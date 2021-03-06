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

	void PowerToggle(bool power);

	void Tick(double elapsed);

	void WireMode(bool on);
private:
	
	void AddWire(sf::Vector2f mousePos);
	
	std::vector<std::shared_ptr<CPinnedComponent>> mComponents;
	
	std::vector<std::shared_ptr<CWire>> mWires;
			
	std::shared_ptr<CPinnedComponent>* mGrabbed = nullptr;
	
	bool mIn = false, mOut = false;

	bool mPowerMode = false;
	bool mWireMode = false;
};

