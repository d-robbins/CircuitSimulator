#include <iostream>
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Component.h"
#include "Wire.h"

int main()
{

    std::cout << sizeof(double) << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    window.setFramerateLimit(60);

    const auto white = sf::Color(255, 255, 255, 255);

    CBoard board;

    CWire wire;

    auto comp = std::make_shared<CPinnedComponent>(sf::Vector2f(500, 500));
    comp->AddInputPin();
    comp->AddOutputPin();


    auto comp2 = std::make_shared<CPinnedComponent>(sf::Vector2f(500, 600));
    comp2->AddInputPin();
    comp2->AddOutputPin();

    auto comp3 = std::make_shared<CPinnedComponent>(sf::Vector2f(500, 600));
    comp3->AddInputPin();
    comp3->AddOutputPin();

    auto comp4 = std::make_shared<CPinnedComponent>(sf::Vector2f(500, 600));
    comp4->AddInputPin();
    comp4->AddOutputPin();


    board.AddComponent(comp);
    board.AddComponent(comp2);
    board.AddComponent(comp3);
    board.AddComponent(comp4);

    bool toggle = false;

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
                board.OnClick(pos);
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    board.WireMode(!toggle);
                }
                else if (event.key.code == sf::Keyboard::Q)
                {
                }
            }
        }

        window.clear(white);
        board.Render(window, event);
        window.display();
    }

    return 0;
}