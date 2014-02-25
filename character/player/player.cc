#include <iostream>
#include "player.h"
using namespace std;

Player::Player(int hp, int atk, int def) : Character('@', hp, atk, def), gold(0) {
}

Player::~Player() {
}

void Player::pick(Gold &gold) {
	this->gold += gold.getValue();
}

bool Player::isPlayer() {
	return true;
}

int Player::getGold() {
	return gold;
}
