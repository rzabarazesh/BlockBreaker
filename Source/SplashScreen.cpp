#include "SplashScreen.h"

void SplashScreen::show (sf::String fileName,sf::RenderWindow & GameWindow ) 
{

	sf::Texture SplashTexture ;
	SplashTexture.loadFromFile(fileName);
	sf::Sprite SplashSprite(SplashTexture) ;

	GameWindow.draw(SplashSprite);
	GameWindow.display();

	sf::Event GameWindowEvent ;
	while (true)
	{
		while(GameWindow.pollEvent(GameWindowEvent))
		{
			if(GameWindowEvent.type ==sf::Event::EventType::KeyPressed || GameWindowEvent.type == sf::Event::EventType::MouseButtonPressed)
				return ;
		}
	}

}