#include "Splash.h"
#include <Game.h>
Splash::Splash(float width, float height)
{
    splash.loadFromFile("assets/img/splash.png");
    sSplash.setTexture(splash);
    isSplash=true;
    splashTime=100;
}

Splash::~Splash()
{
    //dtor
}

void Splash::draw(RenderWindow &window)
{
while(isSplash)
{
splashTime-=0.5;
sSplash.setColor(Color(255,255,255,20));
if(splashTime<=0)
{
sSplash.setColor(Color(0,0,0,20));
Game game(400,533);
game.waitNextEvent(1000);
isSplash=false;
}

window.draw(sSplash);
window.display();
}
}
