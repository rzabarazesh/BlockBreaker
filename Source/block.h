#ifndef BLOCK_H
#define BLOCK_H
#include "GameObject.h"

class block : public GameObject 
{
public:
	//block(sf::Texture &BlockTexture);
	block();
	bool doesExist; 
	
};
#endif