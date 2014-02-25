#include "dragon.h"

Dragon::Dragon(DragonHoard *treasure) : Enemy('D', 150, 20, 20), treasure(treasure) {
}

Gold *Dragon::dropItem() {
	return 0;
}

Dragon::~Dragon() {
	treasure->unlock();
}

