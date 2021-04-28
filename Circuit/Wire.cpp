#include "Wire.h"

CWire::CWire() 
{
}

void CWire::Render(sf::RenderWindow& context)
{
	if (mIn != nullptr && mOut != nullptr)
	{
		sf::Vertex a, b;

		auto opp = mOut->GetPinPos();
		auto ipp = mIn->GetPinPos();
		auto ocp = mOut->GetPinComponentPos();
		auto icp = mIn->GetPinComponentPos();
		auto wid = mOut->GetPinWidth();
		a = sf::Vector2f(opp.x + ocp.x + wid 
			, mOut->GetPinComponentPos().y + mOut->GetPinPos().y);

		b = mIn->GetPinComponentPos() + mIn->GetPinPos();

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
