#include "player.h"
using namespace std;

Player::Player(int hp, int atk, int def) : Character('@', hp, atk, def), gold(0) {
}

Player::~Player() {
}
