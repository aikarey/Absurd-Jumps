#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Splash
{
    public:
        Splash(float width, float height);
        virtual ~Splash();
        void draw(RenderWindow &window);
        Texture splash;
       Sprite sSplash;
       float splashTime;
       bool isSplash;

    protected:

    private:
};

