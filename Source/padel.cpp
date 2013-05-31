#include "padel.h"


padel::padel()
{
	this->load("padel.png");
	this->setPositon(200 , 460);
	posx = 200 ;
	posy = 460 ;
	Xvelocity = 0 ;
	timerStarted = false ;
	direction = 0 ;
}

//timer indicates how long we have hold the left/right buttons
void padel::goLeft()
{
	direction = 1 ;
	Xvelocity = timer.getElapsedTime().asSeconds()+0.5 ;
	if(getX() - 0.5*Xvelocity >= 0)
		setPositon(getX()-0.5*Xvelocity,460);			
}

void padel::goRight()
{
	direction = -1 ;
	Xvelocity = timer.getElapsedTime().asSeconds()+0.5 ;
	if(getX() + 0.5*Xvelocity <= 400)
		setPositon(getX()+ 0.5*Xvelocity,460);	
}

void padel::update(sf::RenderWindow &GameWindow)
{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{	
			goRight();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
			goLeft();
			}

}

void padel::stop() 
{
	setXVelocity(0);
	timerStarted = false;
	
}

void padel::timerStart ()
{ //timer indicates how long we have hold the left/right buttons
	if(!timerStarted)
	{		
		timer.restart();
		timerStarted = true;
	}
}