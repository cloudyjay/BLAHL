#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../character.h"
#include "../../item/gold/gold.h"
class Player: public Character {
	int gold;

public:
	Player(int hp, int atk, int def);
	virtual	~Player()=0;
	virtual void printRace()=0;
	void pick(Gold &gold);
	bool isPlayer();
	int getGold();
};

#endif
