#ifndef __INTERFACE_H__
#define __INTERFACE_H__


#include <string>
#include "screenout.h"
#include "floor.h"

// Interface class is reponsible for:
//		Reading user input
//		Displaying game board
//		Interact with games
class Interface {
	const int MAX_LVL;
	int cur_lvl;
	std::string MAP_NAME;
	Floor **game_floors;

	// KeyboardIn key_in;
	// ScreenOut scn_out;
public:
	Interface(std::string map_name, int max_lvl=8);
	~Interface();
	bool isEnd();
	void playTurn();
};

#endif
