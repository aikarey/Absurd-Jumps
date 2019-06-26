#include <SFML/Graphics.hpp>
#include <time.h>

#include <thread>
#include <Menu.h>
#include <Game.h>
#include <Splash.h>
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 533
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Absurd Jumps!");
    window.setFramerateLimit(60wwwwwwwwwww);
    Splash san(window.getSize().x, window.getSize().y);
    Menu menu(window.getSize().x, window.getSize().y);
    Game game(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {


        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        san.draw(window);
        while(game.menuIsOpen == true && window.isOpen())
        {

        if(Keyboard::isKeyPressed(Keyboard::Space)) menu.BgmMenu.play();

        Event e;
        while(window.pollEvent(e))
        {

        if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) menu.moveUp();
        if(Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) menu.moveDown();
        if(Keyboard::isKeyPressed(Keyboard::Return))
        {
        menu.soundPress.play();
        if(menu.getPressedMenu() == 0)
        {

        menu.BgmMenu.stop();
        game.waitNextEvent(1000);
        game.isLife = true;
        game.menuIsOpen = false;
        game.y = 200;
        game.dy=0.2;
        }
        if(menu.getPressedMenu() == 2)
        {
        game.waitNextEvent(1000);
        window.close();
        }
        }
        if(e.type == Event::Closed) window.close();
        }

        menu.draw(window,window.getSize().x, window.getSize().y);
        window.display();
        }
        game.play(window);
        window.display();

    }

    return 0;
}
