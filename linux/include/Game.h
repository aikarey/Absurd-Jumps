#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 533

using namespace sf;
struct pos
{int x ,y;};
class Game
{
    public:
        Game(float width, float height);
        virtual ~Game();
        Texture tPlayer,
                tGround,
                tBackground,
                tBgScore,
                tGimOver,
                tBoostBar;
        Sprite sPlayer,
               sGround,
               sBackground,
               sBgScore,
               sGimOver,
               sBoostBar;
        SoundBuffer bufferJump,
                    bufferGimOver;
        Sound soundJump,
              soundGimOver;
        Music bgMusic;
        Text score,
             textBoost,
             hintBoost;
        Font font;
        void play(RenderWindow &window);
        bool isGameOver();
        bool isMoveOverLeft();
        bool isMoveOverRight();
        void updateValueScore();
        pos ground[20];
        int x=100,y=100,h=200;
        float dx=0,dy=0;
        int scoreValue;
        std::string scoreValueFix;
        std::string boostFix;
        bool isLife = true;
         bool isBoosted = false;
         bool showHintBoosted = false;
        void waitNextEvent(int durations);
        void playerMoveLeft();
        void playerMoveRight();
        void drawNewGround();
        void updateValueBoost();
        bool menuIsOpen = true;
        double boost=0;
    protected:

    private:
};


