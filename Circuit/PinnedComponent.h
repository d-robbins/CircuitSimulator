#pragma once

#include "Component.h"

#include <vector>

class CWire;

class CPinnedComponent : public CComponent
{
public:
	CPinnedComponent(sf::Vector2f pos);
	~CPinnedComponent() {}

	virtual void Render(sf::RenderWindow& context) override;

	void ReceivePower(bool pow);

	class OutputPin
	{
	public:
		OutputPin(CPinnedComponent* component)
		{
			auto pos = component->GetPosition();
			auto hit = component->GetHeight();
			auto wid = component->GetWidth();
			mPin.setSize(sf::Vector2f(40, 10));
			mPin.setFillColor(sf::Color::Red);
			mPin.setPosition(sf::Vector2f(pos.x + wid, pos.y + (hit / 2)));
		}

		void Render(sf::RenderWindow& context)
		{
			context.draw(mPin);
		}

		void PropogatePower(bool pow);

		//OutputPin() = delete;
		
		void SetPos(const sf::Vector2f& pos)
		{
			mPin.setPosition(pos);
		}

		sf::Vector2f GetPosition() const { return mPin.getPosition(); }

		void AttachWire(CWire* wire) { mWire = wire; }

	private:
		CWire* mWire = nullptr;
		sf::RectangleShape mPin;
		sf::Vector2f mPos;
	};

	class InputPin
	{
	public:
		InputPin(CPinnedComponent* component)
		{
			mComponent = component;
			auto pos = component->GetPosition();
			auto hit = component->GetHeight();
			auto wid = component->GetWidth();
			mPin.setSize(sf::Vector2f(40, 10));
			mPin.setFillColor(sf::Color::Black);
			mPin.setPosition(sf::Vector2f(pos.x - 40, pos.y + (hit / 2)));
		}
		
		//InputPin() = delete;

		void Render(sf::RenderWindow& context)
		{
			context.draw(mPin);
		}

		void SetPos(const sf::Vector2f& pos)
		{
			mPin.setPosition(pos);
		}

		sf::Vector2f GetPosition() const { return mPin.getPosition(); }

		void ReceivePower(bool pow)
		{
			mComponent->ReceivePower(pow);
		}

		void AttachWire(CWire* wire) { mWire = wire; }

	private:
		CWire* mWire = nullptr;
		CPinnedComponent* mComponent = nullptr;
		sf::RectangleShape mPin;
		sf::Vector2f mPos;
	};

	void CreateInputPin();
	void CreateOutputPin();

	void AttachWireInput(CWire* wire);
	void AttachWireOutput(CWire* wire);

	virtual void SendPower();

private:
	std::vector<std::shared_ptr<OutputPin>> mOutputPins;
	std::vector<std::shared_ptr<InputPin>> mInputPins;
};

