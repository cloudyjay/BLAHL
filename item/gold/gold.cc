#include "gold.h"
using namespace std;

Gold::Gold(int val) : Item('G'), val(val) {
}

bool Gold::isUsable() {
	return false;
}

bool Gold::isPickable() {
	return true;
}

int Gold::getValue() {
	return val;
}

Gold::~Gold() {
}
