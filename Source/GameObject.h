#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class GameObject 
{
public :
	GameObject();
	virtual void draw (sf::RenderWindow &GameWindow ) ;
	virtual void setPositon ( float x , float y ) ;
	virtual void load (sf::String filename) ;
	void setXVelocity(float newVelocity);
	float Xvelocity ;
	float getXVelocity ();
		
	float getX ();
	float getY ();
	float posx , posy ;
	sf::Sprite GameObjectSprite ;
private:
	sf::Texture GameObjectTexture ;
	
	sf::String GameObjectFileName ;
	
	bool loaded ;
	
};

#endif