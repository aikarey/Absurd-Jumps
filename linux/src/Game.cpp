#include "Game.h"

Game::Game(float width, float height)
{
    tPlayer.loadFromFile("assets/img/stick.png");
    tBackground.loadFromFile("assets/img/background.png");
    tGround.loadFromFile("assets/img/ground.png");
    tBgScore.loadFromFile("assets/img/score.png");
    tGimOver.loadFromFile("assets/img/gim-over.png");
    tBoostBar.loadFromFile("assets/img/boost.png");
    font.loadFromFile("assets/arial.ttf");
    bgMusic.openFromFile("assets/sound/bg-music.wav");
    bufferJump.loadFromFile("assets/sound/jump.wav");
    bufferGimOver.loadFromFile("assets/sound/gim-over.wav");
    soundJump.setBuffer(bufferJump);
    soundGimOver.setBuffer(bufferGimOver);
    sPlayer.setTexture(tPlayer);
    sBackground.setTexture(tBackground);
    sGround.setTexture(tGround);
    sBgScore.setTexture(tBgScore);
    sGimOver.setTexture(tGimOver);
    sBoostBar.setTexture(tBoostBar);
    sBoostBar.setTextureRect(IntRect(0,0,0,0));
    sBgScore.setPosition(10,10);
    sBoostBar.setPosition(280,10);
    scoreValue = 0;
    scoreValueFix = std::to_string(scoreValue);
    score.setFont(font);
    score.setString("Score : " + scoreValueFix);
    score.setColor(Color::Black);
    score.setCharacterSize(15);
    score.setPosition(20,20);
    boostFix = std::to_string(boost);
    textBoost.setFont(font);
    textBoost.setString(boostFix + " %");
    textBoost.setColor(Color::Black);
    textBoost.setPosition(290,17);
    textBoost.setCharacterSize(13);
    hintBoost.setFont(font);
    hintBoost.setString("Press Space To Boost!");
    hintBoost.setCharacterSize(20);
    hintBoost.setColor(Color::Red);
    hintBoost.setPosition(100,45);


   for(int i =0;i<10;i++)
    {
    ground[i].x = rand()%SCREEN_WIDTH-100;
    ground[i].y = rand()%SCREEN_HEIGHT;
    }


}

Game::~Game()
{
    //dtor
}
void Game::waitNextEvent(int durations)
{

std::chrono::duration<int, std::milli> timespan(durations);
std::this_thread::sleep_for(timespan);
}
void Game::updateValueScore()
{
    scoreValue+=3;
    scoreValueFix = std::to_string(scoreValue);
    score.setString("Score : " + scoreValueFix);
}
bool Game::isMoveOverLeft()
{
if(x< -65)
{
return true;
}else
{
return false;
}
}
bool Game::isMoveOverRight()
{
if( x > 379 )
{
return true;
}else
{
return false;
}
}
void Game::playerMoveLeft()
{
   if(Keyboard::isKeyPressed(Keyboard::Left))
    {
    tPlayer.loadFromFile("assets/img/stick.png");
    x-=3;
    }
}
void Game::playerMoveRight()
{

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
    tPlayer.loadFromFile("assets/img/stick-right.png");
    x+=3;
    }

}
bool Game::isGameOver()
{

    if(y>550)
    {
    return true;
    }else
    {
    return false;
    }
}
void Game::drawNewGround()
{
    for (int i=0;i<10;i++)
    {
      y=h;
      ground[i].y=ground[i].y-dy;
      if (ground[i].y>SCREEN_HEIGHT)
      {
      ground[i].y=0;
      ground[i].x=rand()%SCREEN_WIDTH;
      }
    }
}
void Game::updateValueBoost()
{
     boost+=0.05;
     boostFix = std::to_string(int(boost));
     textBoost.setString("Boost : " + boostFix + " %");
    sBoostBar.setTextureRect(IntRect(0,0,boost,32));

}
void Game::play(RenderWindow &window)
{
 bgMusic.setLoop(true);
     bgMusic.play();
while(isLife && window.isOpen() && menuIsOpen == false)
{



dy+=0.2;
y+=dy;
      Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();

        }
    if( this->isMoveOverLeft() == true) x = 379;
    if( this->isMoveOverRight() == true) x = -65;
    //pergerakan player jika player menekan tombol kiri / kanan
    //mengupdate posisi player
    this->playerMoveLeft();
    this->playerMoveRight();
	if (y<h)
	{
	//menggambar pijakan baru jika player bergerak keatasq
    this->drawNewGround();

    //mengupdate nilai score
    this->updateValueScore();
    //boost
    if(boost !=100.000000)
    {
    //mengupdate nilai boost
    this->updateValueBoost();
    }
    //jika nilai boost adalah 100% / bosst bar sudah penuh
    if(boost >= 100.000000)
    {
    //jangan biarkan nilai boost bertambah lebih dari 100
    boost=100.000000;
    //tampilkan pesan boost
    showHintBoosted = true;
    //jika player menekan tombol space, lakukan boost
    if(Keyboard::isKeyPressed(Keyboard::Space))
    {
    dy-=35;
    boost=0;
    isBoosted = true;
    showHintBoosted = false;
    }
    }
    //saat boost sedang berlangsung
    while(isBoosted)
    {
    //update sprite player
    tPlayer.loadFromFile("assets/img/stick-boosted.png");
    if(Keyboard::isKeyPressed(Keyboard::Left)) tPlayer.loadFromFile("assets/img/stick-boosted.png");
    if(Keyboard::isKeyPressed(Keyboard::Right)) tPlayer.loadFromFile("assets/img/stick-boosted-right.png");


    window.draw(sPlayer);

    if(boost <=0.000000) isBoosted = false;
    }

    }
    //jika player menyentuh pijakan, loncatkan player keatas
	for (int i=0;i<10;i++)
    if ((x+50>ground[i].x) && (x+20<ground[i].x+68) && (y+70>ground[i].y) && (y+70<ground[i].y+14) && (dy>0))
    {
    soundJump.play();
     dy=-10;
    }

    sPlayer.setPosition(x,y);
    window.draw(sBackground);
    window.draw(sPlayer);
    for (int i=0;i<10;i++)
    {
    sGround.setPosition(ground[i].x,ground[i].y);
    window.draw(sGround);
    }
    window.draw(sBgScore);
    window.draw(score);
    window.draw(sBoostBar);
    window.draw(textBoost);

    if( this->isGameOver() == true )
    {
    bgMusic.stop();
    soundGimOver.play();
    sGimOver.setPosition(55, 220);

    isLife = false;

    }

if(showHintBoosted == true) window.draw(hintBoost);
window.display();
}
window.draw(sBackground);
window.draw(sPlayer);
window.draw(sBgScore);
window.draw(score);
window.draw(sGimOver);
if(Keyboard::isKeyPressed(Keyboard::Return))
{

menuIsOpen = true;
bgMusic.stop();

}
window.display();
}

