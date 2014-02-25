#ifndef __ENEMYFACTORY__H
#define __ENEMYFACTORY__H

#include "enemy.h"

class EnemyFactory {
public:
	Enemy *generateEnemy(char c);
};

#endif
