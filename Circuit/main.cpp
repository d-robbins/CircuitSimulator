#include <iostream>
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Component.h"
#include "Wire.h"
#include "ANDGate.h"

int main()
{

    std::cout << sizeof(double) << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Circuit Sim");

    window.setFramerateLimit(60);

    const auto white = sf::Color(255, 255, 255, 255);

    std::shared_ptr<CBoard> board = std::make_shared<CBoard>();

    CWire wire;

    auto comp = std::make_shared<CPinnedComponent>(sf::Vector2f(500, 500));
    comp->AddOutputPin();
    board->AddComponent(comp);


    bool toggle = false;
    bool powerToggle = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                auto pos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                board->OnClick(pos);
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    board->WireMode(!toggle);
                }
                else if (event.key.code == sf::Keyboard::Q)
                {
                    auto comp = std::make_shared<CPinnedComponent>(sf::Vector2f(100, 100));
                    comp->AddInputPin();
                    comp->AddOutputPin();
                    board->AddComponent(comp);
                }
                else if (event.key.code == sf::Keyboard::G)
                {
                    board->PowerToggle(!powerToggle);
                }
                else if (event.key.code == sf::Keyboard::A)
                {
                    auto comp = std::make_shared<CANDGate>(sf::Vector2f(100, 100), "../images/and.png");
                    board->AddComponent(comp);
                }
                else if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }

        window.clear(white);
        board->Render(window, event);
        window.display();
    }

    return 0;
}