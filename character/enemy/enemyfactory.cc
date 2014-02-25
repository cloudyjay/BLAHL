#include "enemyfactory.h"
using namespace std;

#include "vampire.h"
#include "werewolf.h"
#include "goblin.h"
#include "merchant.h"
#include "dragon.h"
#include "phoenix.h"
#include "troll.h"


Enemy *EnemyFactory::generateEnemy(char c, DragonHoard *treasure) {
	Enemy *ret;
	if(c == 'V') {
		ret = new Vampire();
	}
	else if(c == 'W') {
		ret = new Werewolf();
	}
	else if(c == 'N') {
		ret = new Goblin();
	}
	else if(c == 'M') {
		ret = new Merchant();
	}
	else if(c == 'D') {
		ret = new Dragon(treasure);
	}
	else if(c == 'X') {
		ret = new Phoenix();
	}
	else if(c == 'T') {
		ret = new Troll();	
	}
	else {
		ret = 0;
	}

	return ret;
}
