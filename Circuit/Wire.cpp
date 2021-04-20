#include "Wire.h"



CWire::CWire() 
{
}

void CWire::SetInputPin(CPinnedComponent::InputPin* pin)
{
	mInputPin = pin;
	pin->AttachWire(this);
}

void CWire::SetOutputPin(CPinnedComponent::OutputPin* pin)
{
	mOutputPin = pin;
	pin->AttachWire(this);
}

void CWire::Render(sf::RenderWindow& context)
{
	if (mInputPin != nullptr && mOutputPin != nullptr)
	{
		sf::Vertex a, b;
		a.position = mInputPin->GetPosition();
		b.position = mOutputPin->GetPosition();
		
		// 
		// FIX
		// 

		b.position.x += 40;
		a.position.y += 5;
		b.position.y += 5;
		
		//

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
	this->mInputPin->ReceivePower(pow);
	this->mState = true;
	std::cout << "WIRE POWERED\n";
}
