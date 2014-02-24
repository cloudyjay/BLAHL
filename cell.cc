#include "cell.h"
#include <iostream>
using namespace std;

Cell::Cell() : type(' '), num_neighbors(0) {
	for(int i=0; i<8; i++) {
		neighbors[i] = 0;
	}
	piece = 0;
}

Cell::~Cell() {
	for(int i=0; i < 8; i++) {
		neighbors[i] = 0;
	}
	piece = 0;
}

void Cell::attachNeighbor(Cell *neighbor) {
	neighbors[num_neighbors] = neighbor;	
	num_neighbors++;
}

void Cell::setType(char c) {
	type = c;
}

GamePiece *Cell::getPiece() {
	return piece;
}

void Cell::setPiece(GamePiece *piece) {
	this->piece = piece;
}

GamePiece *Cell::releasePiece() {
	GamePiece *ret = piece;
	piece = 0;
	return ret;
}

void Cell::printCell() {
	if(piece != 0) {
		piece->printSelf();
	}
	else {
		cout << type;	
	}
	
}

int Cell::canMove() {
	return 	(piece != 0 && piece->isPickable())? 4 :
			(piece != 0)? 0 :
			(type == '.')? 1 :
			(type == '+' || type == '#')? 2 :
			(type == '/')? 3 : 0;
}
