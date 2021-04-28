#include <iostream>
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Component.h"
#include "Wire.h"

#include "Menu.h"

int main()
{
    std::cout << sizeof(double) << std::endl;
    sf::View view(sf::FloatRect(0, 0, 1280, 720));
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Circuit Sim");

    window.setFramerateLimit(60);

    window.setView(view);

    const auto white = sf::Color(255, 255, 255, 255);

    auto board = std::make_shared<CBoard>();
    auto menu = std::make_shared<CMenu>(board.get());


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
                sf::Vector2i p = sf::Mouse::getPosition(window);
                board->OnClick(sf::Vector2f((float)p.x, (float)p.y));
                menu->OnClick(sf::Vector2f((float)p.x, (float)p.y));
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    board->WireMode(!toggle);
                }
                else if (event.key.code == sf::Keyboard::G)
                {
                    board->PowerToggle(!powerToggle);
                }
                else if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }

        window.clear(white);
        board->Render(window, event);
        menu->Render(window);
        window.display();
    }

    return 0;
}