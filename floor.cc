#include "floor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

Floor::Floor(string map_name, int width, int height) : WIDTH(width), HEIGHT(height), MAP_NAME(map_name), player(0) {
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

void Floor::init(Player *player) {

	// set player and locate it randomly
	int x, y;
	this->player = player;
	do {
		x = rand() % 77 + 1;	// 1 ~ 77
		y = rand() % 23 + 1;	// 1 ~ 23
	} while(cells[y][x].canMove() != 1);
	player->move(x, y);
	cells[player->getY()][player->getX()].setPiece(player);
}

void Floor::movePlayer(string cmd) {
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
		if(cells[y][x].canMove() == 4) {	// golds
			
		}
		cells[player->getY()][player->getX()].releasePiece();
		player->move(x, y);
		cells[player->getY()][player->getX()].setPiece(player);
		
		if(cells[y][x].canMove() == 3) {	// starirs goup the floor	
	
		}	
	} else {														// cannot move
		cout << "Can't move!" << endl;
	}
}

void Floor::printFloor() {
	for(int i=0; i<HEIGHT; i++) {
		for(int j=0; j<WIDTH; j++) {
			cells[i][j].printCell();
		}
		cout << endl;
	}
}
