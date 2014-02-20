#include "interface.h"
#include <iostream>
using namespace std;

/******************* PRIVATE ************************/
bool Interface::isDirection(string cmd) {
	return (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
			cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw");
}

/******************* PUBLIC ************************/
Interface::Interface(string map_name, int max_lvl) : MAX_LVL(max_lvl), cur_lvl(0), MAP_NAME(map_name) {
	// allocate & build floors
	game_floors = new Floor*[MAX_LVL];
	for(int i=0; i < MAX_LVL; i++) {
		game_floors[i] = new Floor(MAP_NAME);
	}

	// 
}

Interface::~Interface() {
	for(int i=0; i < MAX_LVL; i++) {
		delete game_floors[i];
	}
	delete[] game_floors;
}

bool Interface::isEnd() {
	if(MAX_LVL <= cur_lvl) {
		return true;
	}
	else {
		return false;
	}
}

void Interface::playTurn() {
	bool valid_cmd = false;
	while(!vaild_cmd) {
		string cmd;
		cout << "Type your next move: ";
		cin >> cmd;
		if(cmd[0] == 'u') {				// use Potion
			cout << "POTION" << endl;
			valid_cmd = true;
		}
		else if(cmd[0] == 'a') {		// attack Enemy
			cout << "ENEMY" << endl;
			valid_cmd = true;
		}
		else if(isDirection(cmd)) {		// move Player
			cout << "PLAYER" << endl;
			valid_cmd = true;
		}
		else if(cmd[0] == 'r') {		// restart
			cout << "RESTART" << endl;
			valid_cmd = true;
		}
		else if(cmd[0] == 'q') {		// quit
			cout << "QUIT" << endl;
			valid_cmd = true;
		}	
		else {
			cout << "INVALID" << endl;
		} 
	}

	
	game_floors[cur_lvl]->printFloor();
}

