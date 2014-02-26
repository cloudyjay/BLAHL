#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../character.h"
#include "../../item/gold/gold.h"
class Enemy: public Character {
public:
	Enemy(char type, int hp, int atk, int def);
	virtual bool isHostile();
	virtual bool isAllowed(int x, int y);
	virtual Gold *dropItem();
	~Enemy()=0;
};

#endif
