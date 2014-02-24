#include "item.h"
using namespace std;

Item::Item(char type) : GamePiece(type) {
}

bool Item::isAttackable() {
	return false;
}

Item::~Item() {
}
