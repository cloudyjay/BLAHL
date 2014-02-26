#include "dragonhoard.h"
using namespace std;

DragonHoard::DragonHoard() : Gold(6), lock(true) {
	for(int i=0; i<8; i++) {
		neighbors_x[i] = 0;
		neighbors_y[i] = 0;
	}
}

void DragonHoard::move(int x, int y) {
	GamePiece::move(x, y);

	neighbors_x[0] = x;
	neighbors_y[0] = y-1;

	neighbors_x[1] = x+1;
	neighbors_y[1] = y-1;

	neighbors_x[2] = x+1;
	neighbors_y[2] = y;

	neighbors_x[3] = x+1;
	neighbors_y[3] = y+1;

	neighbors_x[4] = x;
	neighbors_y[4] = y+1;

	neighbors_x[5] = x-1;
	neighbors_y[5] = y+1;

	neighbors_x[6] = x-1;
	neighbors_y[6] = y;

	neighbors_x[7] = x-1;
	neighbors_y[7] = y-1;
}

bool DragonHoard::inRange(int x, int y) {
	bool ret = false;
	for(int i=0; i<8; i++) {
		if(neighbors_x[i] == x && neighbors_y[i] == y) {
			ret = true;
		}
	}
	return ret;
}

bool DragonHoard::isPickable() {
	return !lock;
}

void DragonHoard::unlock() {
	lock = false;
}

DragonHoard::~DragonHoard() {
}
