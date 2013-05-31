#ifndef PADEL_H
#define PADEL_H

#include "GameObject.h"

class padel : public GameObject 
{
public :
	padel();
	
	void goLeft ();
	void goRight ();
	int direction ;
	
	

	void update(sf::RenderWindow &GameWindow);

	void setTimer() ;
	sf::Clock timer;
	void stop () ;
	void timerStart ();
	bool timerStarted ;
};

#endif