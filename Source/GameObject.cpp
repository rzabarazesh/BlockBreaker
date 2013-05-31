#include "GameObject.h"

GameObject::GameObject()
{
	loaded = false  ;
}

void GameObject::load (sf::String filename)
{
	GameObjectFileName = filename ;
	GameObjectTexture.loadFromFile(filename);
	GameObjectSprite.setTexture(GameObjectTexture);
	loaded = true ;

}

void GameObject::draw (sf::RenderWindow &GameWindow )
{

		GameWindow.draw(GameObjectSprite);

}

void GameObject::setPositon(float x , float y )
{

		posx = x ;
		posy = y ;
		GameObjectSprite.setPosition(x,y);

}

float GameObject::getX () 
{
	return(posx);
}
float GameObject::getY()
{
	return(posy);
}

void GameObject::setXVelocity(float newVelocity)
{
	Xvelocity = newVelocity ;
}

float GameObject::getXVelocity ()
{
	return(Xvelocity);
}