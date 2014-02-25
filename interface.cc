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
	cout << "   Gold: " << player->getGold();
	cout << setw(54) << "Floor " << cur_lvl+1 << endl;
	cout << "HP: ";		player->printHealth();	cout << endl;
	cout << "Atk: ";	player->printAttack();	cout << endl;
	cout << "Def: ";	player->printDefence();	cout << endl;
	cout << "Action: " << action << endl;
}

/******************* PUBLIC ************************/
Interface::Interface(string map_name, int max_lvl) : MAP_NAME(map_name), MAX_LVL(max_lvl), cur_lvl(0)
													, action("Game started. Good luck!") {
	// allocate & build floors
	game_floors = new Floor*[MAX_LVL];
	for(int i=0; i < MAX_LVL; i++) {
		game_floors[i] = new Floor(map_name);
	}
	// create player
	PlayerFactory player_factory;
	char race='h';
	cout << "Choose your race! ('h'uman, 'e'lf, 'd'warf, 'o'rc): "; 
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
				if(game_floors[cur_lvl]->usePotion(dir)) {
					action = "You used a potion.";
				} else {
					action = "Cannot use that.";
				}
				game_floors[cur_lvl]->tick();
				valid_cmd = true;
			} else {
				action = "Invalid command. Usage: u <direction>";
			}
		}
		else if(cmd == "a") {		// attack Enemy
			string dir;
			cin >> dir;
			if(isDirection(dir)) {
				if(game_floors[cur_lvl]->attackEnemy(dir)) {
					action = "You attacked an enemy.";
				} else {
					action = "Cannot attack that.";
				}
				game_floors[cur_lvl]->tick();
				valid_cmd = true;
			} else {
				action = "Invalid command. Usage: a <direction>";
			}
			valid_cmd = true;
		}
		else if(isDirection(cmd)) {		// move Player
			int go_up = game_floors[cur_lvl]->movePlayer(cmd);
			if(go_up == 3) {		// go upstairs
				cur_lvl++;
				if(cur_lvl < MAX_LVL) {	// still in the game
					game_floors[cur_lvl]->init(player);
					action = "You went to one floor up.";
				}
				else {	// game ends
					return;
				}		
			} else {
				if(go_up == 2) {	// pick gold
				action = "You picked a gold.";	
				} else if(go_up == 1) {		// normal move
				action = "You moved.";	
				} else {	// failed to move
				action = "Cannot move there.";	
				}
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
			action = "Game restarted. Best luck!";
			valid_cmd = true;
		}
		else if(cmd == "q") {		// quit
			player->defense(200000);
			return;
		}	
		else {
			action = "Invalid command, wasted a turn.";
		} 
	}

	displayScreen();
}

void Interface::printScore() {
	cout << "/ ************************************************************************** /" << endl;
	cout << setw(45) << right << "GAME END" << endl;
	cout << "/ ************************************************************************** /" << endl;
	cout << setw(48) << right << "Your Score is: " << player->getGold() << endl;
	cout << "/ ************************************************************************** /" << endl;
}
