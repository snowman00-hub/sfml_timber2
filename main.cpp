#include "stdafx.h"
#include "SpriteGo.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
        
    TEXTURE_MGR.Load(
        {
            "graphics/player.png",
            "graphics/player.png",
            "graphics/tree.png"
        } 
    );

    SpriteGo spriteGo("graphics/player.png");
    spriteGo.Init();

    spriteGo.setOrigin(Origins::ML);

    spriteGo.Reset();

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
        spriteGo.Update(0.f);

        // Draw
        window.clear();
        //window.draw(shape);
        spriteGo.Draw(window);
        window.display();
    }

    spriteGo.Release();

    return 0;
}