#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../character.h"
class Enemy: public Character {
public:
	Enemy(char type, int hp, int atk, int def);
	~Enemy()=0;
};

#endif
