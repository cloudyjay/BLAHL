#ifndef __GOLD_H__
#define __GOLD_H__

#include "../item.h"

class Gold: public Item {
	int val;
public:
	Gold(int val=1);
	bool isUsable();
	virtual bool isPickable();
	int getValue();
	~Gold();
};

#endif
