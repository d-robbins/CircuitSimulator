#include "PinIn.h"

#include "PinnedComponent.h"

CPinIn::CPinIn(sf::Vector2f position, const std::string& fileLocation)
	:  CPin(position, fileLocation)
{

}

CPinIn::CPinIn(sf::Vector2f position, CPinnedComponent* comp, const std::string& fileLocation)
	: CPin(position, fileLocation), mComp(comp)
{
	
}

sf::Vector2f CPinIn::GetCompPos()
{
	if (mComp != nullptr)
		return mComp->GetPosition();
}

