#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <string>
#include "cell.h"
#include "character/player/player.h"
#include "item/gold/gold.h"
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
	const std::string MAP_NAME;
	const static std::string DEFAULT_MAP_NAME;
	Player *player;
	const int NUM_GOLDS;
	Gold **golds;

	bool onFloor(int i, int j);
	void addNeighbors(int i, int j);
	void generateRandPos(int &x, int &y);

public:
	Floor(std::string map_name, int width=79, int height=25);
	~Floor();
	void init(Player *player);
	// return true if it hits a stairs
	bool movePlayer(std::string cmd);
	void printFloor();
};

#endif
