#include "GameScreen.h"

void GameScreen::show (sf::RenderWindow & GameWindow) 
{
	
	sf::Texture ScreenTexture ;
	ScreenTexture.loadFromFile("screen.png");
	sf::Sprite ScreenSprite(ScreenTexture) ;


	GameWindow.draw(ScreenSprite);
	GameWindow.display();

}