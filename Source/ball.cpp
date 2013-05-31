#include "ball.h"
#include "SplashScreen.h"

//ball constructor
ball::ball () 
{
	load("ball.png");
	setPositon(250 , 250);
	angle = 0 ;
	posx = 250 ;
	posy = 250 ;
	brokenBlocksCount = 0 ;

}

void ball::update(sf::RenderWindow &GameWindow,padel &PlayerPadel,block (&blocks)[5][5])
{
	// make the angle stay between -360 & +360
	 while(angle>360)
		 angle = angle -360 ;
	 while(angle<-360)
		 angle = angle +360 ;
	 //converting degree to gradian
	float degree = (angle*3.141)/180 ;
	//calculating the new positon
	posx = posx + 0.2*std::sin(degree);
	posy = posy + 0.2*std::cos(degree);
	//collision with left & right walls
	if (posx > 500 || posx < 0) 
		angle = - angle ;
	//collision with up wall 
	if( posy <0 )
		angle = angle -90 ;
	//collision with padle
	if(( posy >PlayerPadel.getY()-15
		&& (posx  >= PlayerPadel.getX()
		&& posx  < PlayerPadel.getX()+50)))
		angle = angle -90 -PlayerPadel.getXVelocity()*30;
	if(( posy >PlayerPadel.getY()-15
		&& (posx  >= PlayerPadel.getX()+50
		&& posx  <= PlayerPadel.getX()+100)))
		angle = angle +90 +PlayerPadel.getXVelocity()*30;
	
		//collision with upper and downer side of blocks
		for (int i = 0 ; i < 5 ; i++)
			{
				for (int j = 0 ; j < 5 ; j++ )
				{
					if(posy < blocks[i][j].getY()+20 
						&& posx > blocks[i][j].getX()
						&& posx < blocks[i][j].getX()+100
						&&blocks[i][j].doesExist
						)
							{
								if (angle<=180)
								angle = angle-120  ;
								if (angle>180)
								angle = angle+120;
								blocks[i][j].doesExist = false;		
								brokenBlocksCount +=1 ;
							}
					if(posy < blocks[i][j].getY()
						&& posx > blocks[i][j].getX()
						&& posx < blocks[i][j].getX()+100
						&&blocks[i][j].doesExist
						)
							{
								if (angle<=0)
								angle = angle-120  ;
								if (angle>0)
								angle = angle+120;
								blocks[i][j].doesExist = false;	
								brokenBlocksCount +=1 ;
							}
				}
			}
	//if ball falls out of screen
	if(posy>500)
	{
		SplashScreen lost;
		lost.show("lose.png",GameWindow);
		exit(0);
		
	}
	if (brokenBlocksCount==25)
	{
		SplashScreen won;
		won.show("win.png",GameWindow);
		exit(0);
	}
		
	//setting the new position
	setPositon(posx,posy);



}