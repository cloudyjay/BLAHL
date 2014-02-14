#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <string>
#include "floor.h"

// Interface class is reponsible for:
//		Reading user input
//		Displaying game board
//		Interact with games
class Interface {
	// KeyboardIn key_in;
	// ScreenOut scn_out;
	const int MAX_LVL;
	int cur_lvl;
	std::string MAP_NAME;
	Floor **game_floors;
	
public:
	Interface(std::string map_name, int max_lvl=8);
	~Interface();
};

#endif
