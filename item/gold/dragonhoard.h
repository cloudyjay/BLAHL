#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__

#include "gold.h"

class DragonHoard: public Gold {
	bool lock;
	int neighbors_x[8];
	int neighbors_y[8];
public:
	DragonHoard();
	void move(int x, int y);
	bool inRange(int x, int y);
	bool isPickable();
	void unlock();
	~DragonHoard();
};

#endif
