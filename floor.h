#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <string>
#include "cell.h"
#include "character/player/player.h"
#include "item/gold/gold.h"
#include "item/potion/potion.h"
#include "character/enemy/enemy.h"
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
	const int NUM_POTIONS;
	Potion **potions;
	const int NUM_ENEMIES;
	Enemy **enemies;

	bool onFloor(int i, int j);
	void addNeighbors(int i, int j);
	void changeCoordinate(int &x, int &y, std::string dir);
	void generateRandPos(int &x, int &y);
	char toEnemyType(int n);
public:
	Floor(std::string map_name, int width=79, int height=25);
	~Floor();
	void init(Player *player);
	// return true if it hits a stairs
	bool movePlayer(std::string dir);
	bool usePotion(std::string dir);
	bool attackEnemy(std::string dir);
	void printFloor();
};

#endif
