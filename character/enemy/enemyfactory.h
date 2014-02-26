#ifndef __ENEMYFACTORY__H
#define __ENEMYFACTORY__H

#include "enemy.h"
class Gold;

class EnemyFactory {
public:
	Enemy *generateEnemy(char c, Gold *treasure=0);
};

#endif
