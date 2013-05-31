#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "SplashScreen.h"
#include "menu.h"
#include "padel.h"
//#include "GameScreen.h"
#include "ball.h"
#include "block.h"

class world 
{
public :
	world();
	sf::RenderWindow GameWindow ;
	void GameLoop() ;
	
private :
	SplashScreen * GameSplashScreen ;
	menu * MenuScreen ;
	//GameScreen screen ;
	padel PlayerPadel ;
	ball GameBall ;
	void updateWorld();
	sf::Clock WorldTime ;
	sf::Event GameWindowEvent ;
	block blocks[5][5] ;
	void drawBlocks() ;

};