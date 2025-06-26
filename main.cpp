#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "InputMgr.h"
#include "ResourceMgr.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ResourceMgr<sf::Texture>::Instance().Load(
        {
            "graphics/player.png",
            "graphics/player.png",
            "graphics/tree.png"
        } 
    );

    sf::Sprite sprite;
    sprite.setTexture(ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));
    sf::Sprite sprite2;
    sprite2.setTexture(ResourceMgr<sf::Texture>::Instance().Get("graphics/tree.png"));

    while (window.isOpen())
    {
        InputMgr::Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::UpdateEvent(event);
        }

        // Update
        InputMgr::Update(0.f);

        if (InputMgr::GetKeyDown(sf::Keyboard::A))
        {
            std::cout << "Key Down: A" << std::endl;
        }

        if (InputMgr::GetKey(sf::Keyboard::A))
        {
            std::cout << "Key Held: A" << std::endl;
        }

        if (InputMgr::GetKeyUp(sf::Keyboard::A))
        {
            std::cout << "Key Up: A" << std::endl;
        }

        // Draw
        window.clear();
        window.draw(shape);
        window.draw(sprite2);
        window.draw(sprite);
        window.display();
    }

    return 0;
}