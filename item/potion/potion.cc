#include "potion.h"
using namespace std;

Potion::Potion(string type, int effect) : Item('P'), type(type), effect(effect) {
}

bool Potion::isUsable() {
	return true;
}

bool Potion::isPickable() {
	return false;
}

string Potion::getType() {
	return type;
}

int Potion::getEffect() {
	return effect;
}

Potion::~Potion() {
}
