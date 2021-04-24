#include "Wire.h"

CWire::CWire() 
{
}

void CWire::Render(sf::RenderWindow& context)
{
	if (mIn != nullptr && mOut != nullptr)
	{
		sf::Vertex a, b;
		a = sf::Vector2f(mOut->GetPosition().x + mOut->GetWidth(), mOut->GetPosition().y);
		b = mIn->GetPosition();

		if (!mState)
		{
			a.color = sf::Color::Black;
			b.color = sf::Color::Black;
		}
		else
		{
			a.color = sf::Color::Red;
			b.color = sf::Color::Red;
		}
		
		sf::Vertex line[] =
		{
			a, b
		};
		
		context.draw(line, 2, sf::Lines);		
	}
	
}

void CWire::PropogatePower(bool pow)
{
	if (pow)
		mState = true;
	else
		mState = false;

	if (mIn != nullptr)
	{
		mIn->ReceivePower(pow);
	}
}
