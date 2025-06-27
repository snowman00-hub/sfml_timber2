#include "stdafx.h"
#include "SpriteGo.h"
#include "TextGo.h"

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

    FONT_MGR.Load("fonts/KOMIKAP_.ttf");
    TextGo textGo("fonts/KOMIKAP_.ttf");
    textGo.Init();

    textGo.setColor(sf::Color::Red);
    textGo.setString("Hello");
    textGo.setCharSize(100);
    textGo.setPosition(sf::Vector2f(600.f, 360.f));
    textGo.setOrigin(Origins::ML);

    textGo.Reset();

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
        textGo.Update(0.f);

        // Draw
        window.clear();
        //window.draw(shape);
        spriteGo.Draw(window);
        textGo.Draw(window);
        window.display();
    }

    spriteGo.Release();

    return 0;
}