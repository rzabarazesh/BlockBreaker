#include "world.h"


world::world () 
{		// creating the game window
		GameWindow.create(sf::VideoMode(500,500),"Brick Breaker v0.1");

		// showing the splash screen
		GameSplashScreen = new SplashScreen ;
		GameSplashScreen->show("welcome.png",GameWindow);
		delete GameSplashScreen ;

		//showing the main menu
		MenuScreen = new menu ;
		MenuScreen->show(GameWindow);
		delete MenuScreen ;
		
		//setting up the blocks
		sf::Texture BlockTexture;
		BlockTexture.loadFromFile("block.png");
		for (int i = 0 ; i < 5 ; i++)
			{
				for (int j = 0 ; j < 5 ; j++ )
				{
					blocks[i][j].GameObjectSprite.setTexture(BlockTexture);
					blocks[i][j].setPositon(i*100,j*25);
					
				}
			}
		drawBlocks();
		GameWindow.display();
		
		// entering the game loop
			while(true)
			{
				GameLoop();
			}
}
void world::drawBlocks()
{
			for (int i = 0 ; i < 5 ; i++)
			{
				for (int j = 0 ; j < 5 ; j++ )
				{
					if (blocks[i][j].doesExist)
					{
						blocks[i][j].draw(GameWindow);

					}
				}
			}
}

void world::GameLoop()
{
	//checking the keyboard events
	while(GameWindow.pollEvent(GameWindowEvent))
	{
		if(GameWindowEvent.type==sf::Event::EventType::KeyPressed &&
			(GameWindowEvent.key.code == sf::Keyboard::Left|| GameWindowEvent.key.code == sf::Keyboard::Right))
			{
				PlayerPadel.timerStart();	
			}
		if(GameWindowEvent.type==sf::Event::EventType::KeyReleased &&
			(GameWindowEvent.key.code == sf::Keyboard::Left|| GameWindowEvent.key.code == sf::Keyboard::Right))
			{
				PlayerPadel.stop();
			}	

	}
	//making the changes per frame to the world
	updateWorld();
}

void world::updateWorld() 
{

	if ((int(WorldTime.getElapsedTime().asSeconds() *1000) ) % 2 == 1 )

	{
		PlayerPadel.update(GameWindow);
		GameBall.update(GameWindow,PlayerPadel,blocks);
		GameWindow.clear(sf::Color(150,0,255));
		PlayerPadel.draw(GameWindow);
		GameBall.draw(GameWindow);
		drawBlocks();
		GameWindow.display();
		WorldTime.restart();
	}

}