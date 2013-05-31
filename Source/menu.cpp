#include "menu.h"

int menu::show(sf::RenderWindow &GameWindow)
{
	
	//loading the menu
	sf::Texture MenuTexture ; 
	MenuTexture.loadFromFile("menu.png");
	sf::Sprite MenuSprite(MenuTexture);
	GameWindow.draw(MenuSprite);
	GameWindow.display();

	sf::Event GameWindowEvent ;
	while(true)
	{
		while(GameWindow.pollEvent(GameWindowEvent))
		{
			if(GameWindowEvent.type == sf::Event::EventType::MouseButtonPressed)
			{
			
			
				//if the mouse clicks on the exit button
				if(GameWindowEvent.mouseButton.x>13&&GameWindowEvent.mouseButton.x<465&&
					GameWindowEvent.mouseButton.y>276&&GameWindowEvent.mouseButton.y<468)
				{
					exit(0);
				}
				//if the mouse clicks on the start button
				if(GameWindowEvent.mouseButton.x>13&&GameWindowEvent.mouseButton.x<465&&
					GameWindowEvent.mouseButton.y>26&&GameWindowEvent.mouseButton.y<220)
				{
					return 1 ;
				}

			}

		}
	}


}