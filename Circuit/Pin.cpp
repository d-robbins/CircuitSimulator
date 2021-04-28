#include "Pin.h"

#include "PinnedComponent.h"

CPin::CPin(sf::Vector2f position, CPinnedComponent* comp) : mPos(position), mComp(comp)
{
	this->mShape.setFillColor(sf::Color::Black);
	this->mShape.setSize(sf::Vector2f(20, 10));
}

bool CPin::HitTest(sf::Vector2f pos)
{
	auto pB = mShape.getGlobalBounds();
	auto cP = mComp->GetPosition();
	auto pP = GetPinPos();
	sf::FloatRect pBound(cP.x + pP.x, cP.y + pP.y, pB.width, pB.height);
	auto val = pBound.contains(pos);
	return val;
}

void CPin::Render(sf::RenderWindow& window)
{
	mShape.setPosition(mComp->GetPosition() + mPos);
	window.draw(mShape);
}

sf::Vector2f CPin::GetPinComponentPos()
{
	return mComp->GetPosition();
}
