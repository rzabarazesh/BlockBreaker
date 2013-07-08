#include "GameObject.h"
#include <cmath>
#include "padel.h"
#include "block.h"


class ball : public GameObject
{
public:
	ball();
	float angle ;
	void update(sf::RenderWindow &GameWindow,padel &PlayerPadel,block (&blocks)[5][5]);
	int brokenBlocksCount ;
private:
	
};

