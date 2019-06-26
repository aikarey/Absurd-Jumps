#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define MAX_MENU 6
using namespace sf;

class Menu
{
    public:
        Menu(float width, float height);
        virtual ~Menu();

        void draw(RenderWindow &window,float widht,float height);
        void moveUp();
        void moveDown();
        int getPressedMenu(){return selectedMenuIndex;}
            int selectMenuHeight;
                    SoundBuffer
                    bufferPress,
                    bufferSelect;
        Sound soundSelect,
              soundPress;
        Music BgmMenu;

    protected:

    private:
        Texture tBackground,
                tSelectedMenu,
                tTitle;
        Sprite sBackground,
               sSelectedMenu,
               sTitle;

        int selectedMenuIndex;
        Font font;
        Text menu[MAX_MENU];
        Text ver;
};


