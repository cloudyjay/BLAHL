#include "interface.h"
#include <iostream>
#include "character/player/playerfactory.h"

using namespace std;

/******************* PRIVATE ************************/
bool Interface::isDirection(string cmd) {
	return (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
			cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw");
}
void Interface::displayScreen() {
	// display on screen
	game_floors[cur_lvl]->printFloor();
	cout << "Race: ";	player->printRace();
	cout << "  Gold: ";	player->printGold();
	cout << "                     Floor " << cur_lvl+1 << endl;
	cout << "HP: ";		player->printHealth();	cout << endl;
	cout << "Atk: ";	player->printAttack();	cout << endl;
	cout << "Def: ";	player->printDefence();	cout << endl;
	cout << "Action: " << endl;
}

/******************* PUBLIC ************************/
Interface::Interface(string map_name, int max_lvl) : MAX_LVL(max_lvl), cur_lvl(0) {
	// allocate & build floors
	game_floors = new Floor*[MAX_LVL];
	for(int i=0; i < MAX_LVL; i++) {
		game_floors[i] = new Floor(map_name);
	}
	// create player
	PlayerFactory player_factory;
	player = player_factory.generatePlayer('h');

	// initialize current floor
	game_floors[cur_lvl]->init(player);

	// print
	displayScreen();
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
	while(!valid_cmd) {
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
			int go_up = game_floors[cur_lvl]->movePlayer(cmd);
			if(go_up) {
				cur_lvl++;
				if(cur_lvl < MAX_LVL) {	// still in the game
					game_floors[cur_lvl]->init(player);	
				}
				else {	// game ends
					return;
				}		
			}
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

	displayScreen();
}

