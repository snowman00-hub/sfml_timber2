#include "stdafx.h"
#include "SpriteGo.h"
#include "TextGo.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
        
    TEXTURE_MGR.Load(
        {
            "graphics/player.png",
            "graphics/tree.png"
        } 
    ); 
    FONT_MGR.Load("fonts/KOMIKAP_.ttf");

    SCENE_MGR.Init();

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
        SCENE_MGR.Update(0.f);

        // Draw
        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
    }
    SCENE_MGR.Release();

    return 0;
}