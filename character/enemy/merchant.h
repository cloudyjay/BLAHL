#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "enemy.h"

class Merchant: public Enemy {
	static bool hostile;
public:
	Merchant();
	~Merchant();
	void defense(int target_atk);
	Gold *dropItem();
	bool isHostile();
};

#endif
