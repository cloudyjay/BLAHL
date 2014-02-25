#ifndef __INTERFACE_H__
#define __INTERFACE_H__


#include <string>
#include "floor.h"
#include "character/player/player.h"

// Interface class is reponsible for:
//		Reading user input
//		Displaying game board
//		Interact with games
class Interface {
	const std::string MAP_NAME;
	const int MAX_LVL;
	int cur_lvl;
	Floor **game_floors;
	Player *player;
	// KeyboardIn key_in;
	// ScreenOut scn_out;
	bool isDirection(std::string cmd);
	void displayScreen();
	void cleanFloors();
public:
	Interface(std::string map_name, int max_lvl=8);
	~Interface();
	bool isEnd();
	void playTurn();
	void printScore();
};

#endif
