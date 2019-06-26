#include "Menu.h"

Menu::Menu(float width, float height)
{
    font.loadFromFile("assets/arial.ttf");
    tBackground.loadFromFile("assets/img/background.png");
    tSelectedMenu.loadFromFile("assets/img/select-menu.png");
    tTitle.loadFromFile("assets/img/title.png");
    bufferPress.loadFromFile("assets/sound/press-menu.wav");
    bufferSelect.loadFromFile("assets/sound/select-menu.wav");
    BgmMenu.openFromFile("assets/sound/bgm-menu.ogg");
    BgmMenu.setLoop(true);
    soundPress.setBuffer(bufferPress);
    soundSelect.setBuffer(bufferSelect);
    sBackground.setTexture(tBackground);
    sSelectedMenu.setTexture(tSelectedMenu);
    sTitle.setTexture(tTitle);
    sTitle.setPosition(5,50);
    ver.setFont(font);
    ver.setColor(Color::Black);
    ver.setString("Ver 2.0");
    ver.setPosition(10,500);
    ver.setCharacterSize(20);
    menu[0].setFont(font);
    menu[0].setColor(Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(width / 2.5, height / (MAX_MENU + 1) * 3));
    BgmMenu.play();

    menu[2].setFont(font);
    menu[2].setColor(Color::Black);
    menu[2].setString("Exit");
    menu[2].setPosition(Vector2f(width / 2.5, height / (MAX_MENU + 1) * 4));
    selectedMenuIndex = 0;
    selectMenuHeight = 3;
    sSelectedMenu.setPosition(Vector2f(400 / 3.5, 533 / (MAX_MENU + 1 ) * selectMenuHeight));
}

Menu::~Menu()
{
    //dtor
}
void Menu::moveUp()
{
    soundSelect.play();
    if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) selectMenuHeight--;
    if( selectMenuHeight == 2 )
    {
    selectMenuHeight ++;

    }

    sSelectedMenu.setPosition(Vector2f(400 / 3.5, 533 / (MAX_MENU + 1 ) * selectMenuHeight - 2));
    if(selectedMenuIndex -1 >=0)
    {
    menu[selectedMenuIndex].setColor(Color::Black);
    selectedMenuIndex-=1;

    menu[selectedMenuIndex].setColor(Color::White);
    }
}
void Menu::moveDown()
{
soundSelect.play();
    if(selectedMenuIndex + 1 <= MAX_MENU)
    {

    if(Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) selectMenuHeight++;
    if( selectMenuHeight == 5 )
    {
    selectMenuHeight --;

    }


    //if()

    sSelectedMenu.setPosition(Vector2f(400 / 3.5, 533 / (MAX_MENU + 1 ) * selectMenuHeight - 2));
    menu[selectedMenuIndex].setColor(Color::Black);
    if(selectedMenuIndex != 2)
    {
    selectedMenuIndex++;
    }
    menu[selectedMenuIndex].setColor(Color::White);
    }
}
void Menu::draw(RenderWindow &window,float width, float height)
{

window.draw(sBackground);
window.draw(sSelectedMenu);
window.draw(sTitle);
window.draw(ver);
for( int i=0; i< MAX_MENU;i++)
{
window.draw(menu[i]);
}
}
