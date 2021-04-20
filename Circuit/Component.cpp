#include "Component.h"

CComponent::CComponent(sf::Vector2f position, const std::string& fileLocation)
{
	mSprite.setPosition(position);
	if (!mTexture.loadFromFile(fileLocation))
	{
		std::cerr << "Error opening: " << fileLocation << std::endl;
	}
	else
	{
		mSprite.setTexture(mTexture);
	}
}

void CComponent::Render(sf::RenderWindow& context)
{
	context.draw(mSprite);
}

bool CComponent::HitTest(const sf::Vector2f& pos)
{
	if (mSprite.getGlobalBounds().contains(pos))
	{
		return true;
	}
	else
	{
		return false;
	}
}
 