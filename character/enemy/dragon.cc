#include "dragon.h"

Dragon::Dragon(DragonHoard *treasure) : Enemy('D', 150, 20, 20), treasure(treasure) {
}

bool Dragon::isAllowed(int x, int y) {
	return treasure->inRange(x, y);
}

Gold *Dragon::dropItem() {
	return 0;
}

Dragon::~Dragon() {
	treasure->unlock();
}

