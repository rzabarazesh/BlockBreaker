#include "world.h"


world::world () 
{		// creating the game window
		GameWindow.create(sf::VideoMode(500,500),"Block Breaker v0.2a");

		// showing the splash screen
		GameSplashScreen = new SplashScreen ;
		GameSplashScreen->show("welcome.png",GameWindow);
		delete GameSplashScreen ;

		//showing the main menu
		MenuScreen = new menu ;
		MenuScreen->show(GameWindow);
		delete MenuScreen ;

		//setting up the score ( to 0	)	
		showScore(0);

		sf::Font scoreFont ;
		scoreFont.loadFromFile("dlxfont.ttf");
		score.setFont(scoreFont);
		score.setPosition(20,450);
		
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
				//sf::sleep(sf::microseconds(2000));
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

	if ((int(WorldTime.getElapsedTime().asSeconds() *700) ) % 2 == 1 )

	{
		PlayerPadel.update(GameWindow);
		GameBall.update(GameWindow,PlayerPadel,blocks);

		
		GameWindow.clear(sf::Color(100,30,240));
		
		PlayerPadel.draw(GameWindow);
		GameBall.draw(GameWindow);
		drawBlocks();
		showScore(GameBall.brokenBlocksCount*10);
		sf::sleep(sf::microseconds(300));
		GameWindow.display();
		WorldTime.restart();
	}

}

void world::showScore(int scr)
{
	scoreString = std::to_string(scr) ;
	score.setString(scoreString);
	GameWindow.draw(score); 
}