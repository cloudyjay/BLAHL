#include "merchant.h"

Merchant::Merchant() : Enemy('M', 30, 70, 5), hostile(false) {
}

bool Merchant::isHostile() {
	return hostile;
}

void Merchant::defense(int target_atk) {
	hostile = true;
	Character::defense(target_atk);
}

Merchant::~Merchant() {
}

