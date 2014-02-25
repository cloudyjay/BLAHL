#include "dragonhoard.h"
using namespace std;

DragonHoard::DragonHoard() : Gold(6), lock(true) {

}

bool DragonHoard::isPickable() {
	return !lock;
}

void DragonHoard::unlock() {
	lock = false;
}

DragonHoard::~DragonHoard() {
}
