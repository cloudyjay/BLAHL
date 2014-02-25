#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__

#include "gold.h"

class DragonHoard: public Gold {
	bool lock;
public:
	DragonHoard();
	bool isPickable();
	void unlock();
	~DragonHoard();
};

#endif
