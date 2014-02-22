#include <cmath>
#include "character.h"
using namespace std;

Character::Character(char type, int hp, int atk, int def): GamePiece(type), hp(hp), atk(atk), def(def) {
}

Character::~Character() {
}

void Character::attack(Character &target) {
	target.defense(atk);
}

void Character::defense(int target_atk) {
	int dmg = (int)ceil( (100/(double)(100+def)) * target_atk);
	hp -= dmg;
}

bool Character::isAttackable() {
	return true;
}

bool Character::isUsable() {
	return false;
}

bool Character::isPickable() {
	return false;
}
