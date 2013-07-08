#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "SplashScreen.h"
#include "menu.h"
#include "padel.h"
#include "ball.h"
#include "block.h"
#include <string>

class world 
{
public :
	world();
	sf::RenderWindow GameWindow ;
	void GameLoop() ;
	sf::Text score;
	
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
	void showScore(int);
	//int score_num;
	std::string scoreString ;

};