#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"
#include "../../item/gold/dragonhoard.h"

class Dragon: public Enemy {
	DragonHoard *treasure;
public:
	Dragon(DragonHoard *treasure);
	
	Gold *dropItem();
	~Dragon();
};

#endif
