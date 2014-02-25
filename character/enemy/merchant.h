#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "enemy.h"

class Merchant: public Enemy {
	bool hostile;
public:
	Merchant();
	~Merchant();
	void defense(int target_atk);
	bool isHostile();
};

#endif
