#include "enemy.h"
using namespace std;

Enemy::Enemy(char type, int hp, int atk, int def) : Character(type, hp, atk, def) {
}

bool Enemy::isHostile() {
	return true;
}

Gold *Enemy::dropItem() {
	Gold *ret = new Gold();
	return ret;
}

Enemy::~Enemy() {
}
