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

}

void Cell::attachNeighbor(Cell *neighbor) {
	neighbors[num_neighbors] = neighbor;	
	num_neighbors++;
}

void Cell::setType(char c) {
	type = c;
}

void Cell::printCell() {
	cout << type;
}

int Cell::canMove() {
	return 	(type == '.')? 1 :
			(type == '+' || type == '#')? 2 :
			(type == '/')? 3 : 0;
}
