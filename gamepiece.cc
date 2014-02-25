#include <iostream>
#include "gamepiece.h"
using namespace std;

GamePiece::GamePiece(char symbol) : symbol(symbol), x(0), y(0) {}

void GamePiece::move(int x, int y) {
	this->x = x;
	this->y = y;
}

void GamePiece::printSelf() {
	cout << symbol;
}

int GamePiece::getX() {
	return x;
}

int GamePiece::getY() {
	return y;
}

bool GamePiece::isPlayer() {
	return false;
}
