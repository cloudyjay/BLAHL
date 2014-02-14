#include "cell.h"
using namespace std;

Cell::Cell() : type(' '), num_neighbors(0) {
	for(int i=0; i<8; i++) {
		neighbors[i] = 0;
	}
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
