#include "interface.h"
#include <iostream>
#include <iomanip>
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
	cout << "   Gold: ";	player->printGold();
	cout << setw(54) << "Floor " << cur_lvl+1 << endl;
	cout << "HP: ";		player->printHealth();	cout << endl;
	cout << "Atk: ";	player->printAttack();	cout << endl;
	cout << "Def: ";	player->printDefence();	cout << endl;
	cout << "Action: " << endl;
}

/******************* PUBLIC ************************/
Interface::Interface(string map_name, int max_lvl) : MAP_NAME(map_name), MAX_LVL(max_lvl), cur_lvl(0) {
	// allocate & build floors
	game_floors = new Floor*[MAX_LVL];
	for(int i=0; i < MAX_LVL; i++) {
		game_floors[i] = new Floor(map_name);
	}
	// create player
	PlayerFactory player_factory;
	char race='h';
	cout << "Choose your race! (Human, Elf, Dwarf, Orc): "; 
	cin >> race;
	player = player_factory.generatePlayer(race);

	// initialize current floor
	game_floors[cur_lvl]->init(player);

	// print
	displayScreen();
}

Interface::~Interface() {
	cleanFloors();
	delete[] game_floors;
	delete player;
}

void Interface::cleanFloors() {
	for(int i=0; i < MAX_LVL; i++) {
		delete game_floors[i];
	}
}

bool Interface::isEnd() {
	if(MAX_LVL <= cur_lvl || player->isDead()) {
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
		if(cmd == "u") {				// use Potion
			string dir;
			cin >> dir;
			if(isDirection(dir)) {
				game_floors[cur_lvl]->usePotion(dir);
				game_floors[cur_lvl]->tick();
				valid_cmd = true;
			} else {
				cout << "Invalid cmd!!" << endl;
			}
		}
		else if(cmd == "a") {		// attack Enemy
			string dir;
			cin >> dir;
			if(isDirection(dir)) {
				game_floors[cur_lvl]->attackEnemy(dir);
				game_floors[cur_lvl]->tick();
				valid_cmd = true;
			} else {
				cout << "Invalid cmd!!" << endl;
			}
			valid_cmd = true;
		}
		else if(isDirection(cmd)) {		// move Player
			int go_up = game_floors[cur_lvl]->movePlayer(cmd);
			if(go_up) {		// go upstairs
				cur_lvl++;
				if(cur_lvl < MAX_LVL) {	// still in the game
					game_floors[cur_lvl]->init(player);	
				}
				else {	// game ends
					return;
				}		
			} else {
				game_floors[cur_lvl]->tick();		
			}
			valid_cmd = true;
		}
		else if(cmd == "r") {		// restart
			cleanFloors();
			for(int i=0; i < MAX_LVL; i++) {
				game_floors[i] = new Floor(MAP_NAME);
			}
			cur_lvl = 0;
			game_floors[cur_lvl]->init(player);
			valid_cmd = true;
		}
		else if(cmd == "q") {		// quit
			player->defense(200000);
			return;
		}	
		else {
			cout << "INVALID" << endl;
		} 
	}

	displayScreen();
}

void Interface::printScore() {
	cout << "/ ************************************************************************** /" << endl;
	cout << setw(45) << right << "GAME END" << endl;
	cout << "/ ************************************************************************** /" << endl;
	cout << setw(48) << right << "Your Score is: "; player->printGold(); cout << endl;
	cout << "/ ************************************************************************** /" << endl;
}
