#include "floor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "item/itemfactory.h"
using namespace std;

const string Floor::DEFAULT_MAP_NAME = "map/default.map";

Floor::Floor(string map_name, int width, int height) : WIDTH(width), HEIGHT(height), MAP_NAME(map_name),
													 player(0), NUM_GOLDS(10) {
	// allocate array of golds	
	golds = new Gold*[NUM_GOLDS];
	for(int i=0; i<10; i++) {
		golds[i] = 0;
	}
	// allocate cells
	cells = new Cell*[HEIGHT];
	for(int i=0; i<HEIGHT; i++) {
		cells[i] = new Cell[WIDTH];
	}
	// add neighbors
	for(int i=0; i<HEIGHT; i++) {
		for(int j=0; j<WIDTH; j++) {
			addNeighbors(i, j);
		}
	}
	// build cells using map provided
	ifstream map;
	map.open(MAP_NAME.c_str());
	for(int i=0; i<HEIGHT; i++) {
		string hor_line;
		getline(map, hor_line);
		for(int j=0; j<WIDTH; j++) {
			cells[i][j].setType(hor_line[j]);
		}
	}
	
}

Floor::~Floor() {
	// delete golds
	for(int i=0; i<NUM_GOLDS; i++) {
		delete golds[i];
	}
	delete[] golds;
	// delete cells
	for(int i=0; i<HEIGHT; i++) {
		delete[] cells[i];
	}
	delete[] cells;

}

bool Floor::onFloor(int i, int j) {
	return ((0 <= i) && (i <= HEIGHT) && (0 <= j) && (j <= WIDTH));
}

void Floor::addNeighbors(int i, int j) {
	// check north	
	(onFloor(i-1, j))?	cells[i][j].attachNeighbor(&cells[i-1][j]) :
						cells[i][j].attachNeighbor(0);
	// check north east
	(onFloor(i-1, j+1))?	cells[i][j].attachNeighbor(&cells[i-1][j+1]) :
							cells[i][j].attachNeighbor(0);
	// check east	
	(onFloor(i, j+1))?	cells[i][j].attachNeighbor(&cells[i][j+1]) :
						cells[i][j].attachNeighbor(0);
	// check south east	
	(onFloor(i+1, j+1))?	cells[i][j].attachNeighbor(&cells[i+1][j+1]) :
							cells[i][j].attachNeighbor(0);
	// check south	
	(onFloor(i+1, j))?	cells[i][j].attachNeighbor(&cells[i+1][j]) :
						cells[i][j].attachNeighbor(0);
	// check south west
	(onFloor(i+1, j-1))?	cells[i][j].attachNeighbor(&cells[i+1][j-1]) :
							cells[i][j].attachNeighbor(0);
	// check west	
	(onFloor(i, j-1))?	cells[i][j].attachNeighbor(&cells[i][j-1]) :
						cells[i][j].attachNeighbor(0);
	// check north west	
	(onFloor(i-1, j-1))?	cells[i][j].attachNeighbor(&cells[i-1][j-1]) :
							cells[i][j].attachNeighbor(0);
}

// randomly sets x and y into a valid position
void Floor::generateRandPos(int &x, int &y) {	
	do {
		x = rand() % (WIDTH -2) + 1;	// Default: 1 ~ 77
		y = rand() % (HEIGHT -2) + 1;	// Default: 1 ~ 23
	} while(cells[y][x].canMove() != 1);
}

void Floor::init(Player *player) {
	if(MAP_NAME != DEFAULT_MAP_NAME) {
			
	} else {
		int x, y;
		// spawn stairs
		generateRandPos(x, y);
		cells[y][x].setType('/');

		ItemFactory item_factory;
		// generate golds and place randomly
		for(int i=0; i<NUM_GOLDS; i++) {
			golds[i] = item_factory.generateGold(6);
			generateRandPos(x, y);
			golds[i]->move(x, y);
			cells[golds[i]->getY()][golds[i]->getX()].setPiece(golds[i]);
		}
	
		// set player and locate it randomly
		this->player = player;
		generateRandPos(x, y);
		player->move(x, y);
		cells[player->getY()][player->getX()].setPiece(player);
	}
}

bool Floor::movePlayer(string cmd) {
	int x = player->getX();
	int y = player->getY();
	if(cmd == "no") {
		x += 0;		
		y += -1;
	} else if(cmd == "ne") {
		x += 1;		
		y += -1;
	} else if(cmd == "ea") {
		x += 1;		
		y += 0;
	} else if(cmd == "se") {
		x += 1;		
		y += 1;
	} else if(cmd == "so") {
		x += 0;		
		y += 1;
	} else if(cmd == "sw") {
		x += -1;		
		y += 1;
	} else if(cmd == "we") {
		x += -1;		
		y += 0;
	} else {
		x += -1;		
		y += -1;
	}
	
	// check if it's movable cell
	if(1 <= cells[y][x].canMove() && cells[y][x].canMove() <= 4) {		
		if(cells[y][x].canMove() == 3) {	// starirs go up the floor
			return true;
		}
		if(cells[y][x].canMove() == 4) {	// golds
			
		}
		cells[player->getY()][player->getX()].releasePiece();
		player->move(x, y);
		cells[player->getY()][player->getX()].setPiece(player);
		
		
	} else {	// cannot move
		cout << "Can't move!" << endl;
	}
	return false;
}

void Floor::printFloor() {
	for(int i=0; i<HEIGHT; i++) {
		for(int j=0; j<WIDTH; j++) {
			cells[i][j].printCell();
		}
		cout << endl;
	}
}
