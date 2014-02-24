#include <iostream>
#include "player.h"
using namespace std;

Player::Player(int hp, int atk, int def) : Character('@', hp, atk, def), gold(0) {
}

Player::~Player() {
}

void Player::pick(Gold *gold) {
	gold += gold->getValue();
}

void Player::printGold() {
	cout << gold;
}
