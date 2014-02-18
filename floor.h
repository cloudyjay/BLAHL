#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <string>
#include "cell.h"

// Floor class is an observer of its members
// it owns:
//		X x Y Cells
//		Enemies
//		Golds
//		Potions 
// it has:
//		Player
// its responsibility is to manage each of its components
//  and interact in each turn
class Floor {
	Cell **cells;
	const int WIDTH;
	const int HEIGHT;

	bool onFloor(int i, int j);
	void addNeighbors(int i, int j);

public:
	Floor(std::string map_name, int width=79, int height=25);
	~Floor();
	void printFloor();
};

#endif
