#include "merchant.h"
#include "../../item/gold/merchanthoard.h"
using namespace std;

bool Merchant::hostile = false;

Merchant::Merchant() : Enemy('M', 30, 70, 5) {
}

bool Merchant::isHostile() {
	return hostile;
}

void Merchant::defense(int target_atk) {
	hostile = true;
	Character::defense(target_atk);
}

Gold *Merchant::dropItem() {
	Gold *ret = new MerchantHoard();
	return ret;
}

Merchant::~Merchant() {
}

