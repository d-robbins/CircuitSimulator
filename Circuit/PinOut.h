#pragma once

#include "SFML/Graphics.hpp"
#include "Pin.h"
#include <vector>

class CWire;
class CPinOut : public CPin
{
public:
	CPinOut(sf::Vector2f position, const std::string& fileLocation = "../images/default.png");
	~CPinOut() {}

	virtual void ProcessPower(bool power) override;
	void AddWire(std::shared_ptr<CWire> wire);
private:
	std::vector<std::shared_ptr<CWire>> mWires;
};

