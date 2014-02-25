#ifndef __ENEMYFACTORY__H
#define __ENEMYFACTORY__H

#include "enemy.h"
class DragonHoard;

class EnemyFactory {
public:
	Enemy *generateEnemy(char c, DragonHoard *treasure=0);
};

#endif
