#include "floor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "item/itemfactory.h"
#include "character/enemy/enemyfactory.h"
using namespace std;

const string Floor::DEFAULT_MAP_NAME = "map/default.map";

Floor::Floor(string map_name, int width, int height) : WIDTH(width), HEIGHT(height), MAP_NAME(map_name),
													 player(0), NUM_GOLDS(10), NUM_POTIONS(10), NUM_ENEMIES(20) {
	// allocate array of golds	
	golds = new Gold*[NUM_GOLDS];
	for(int i=0; i<10; i++) {
		golds[i] = 0;
	}
	
	// allocate array of potions	
	potions = new Potion*[NUM_POTIONS];
	for(int i=0; i<10; i++) {
		potions[i] = 0;
	}

	// allocate array of enemies	
	enemies = new Enemy*[NUM_ENEMIES];
	for(int i=0; i<10; i++) {
		enemies[i] = 0;
	}

	// allocate cells
	cells = new Cell*[HEIGHT];
	for(int i=0; i<HEIGHT; i++) {
		cells[i] = new Cell[WIDTH];
	}
	// add neighbors
	for(int i=0; i<HEIGHT; i++) {
		for(int j=0; j<WIDTH; j++) {
			addNeighbors(i, j);
		}
	}
	// build cells using map provided
	ifstream map;
	map.open(MAP_NAME.c_str());
	for(int i=0; i<HEIGHT; i++) {
		string hor_line;
		getline(map, hor_line);
		for(int j=0; j<WIDTH; j++) {
			cells[i][j].setType(hor_line[j]);
		}
	}
	
}

Floor::~Floor() {
	// delete golds
	for(int i=0; i<NUM_GOLDS; i++) {
		if(golds[i]) delete golds[i];
	}
	delete[] golds;
	// delete potions
	for(int i=0; i<NUM_POTIONS; i++) {
		if(potions[i]) delete potions[i];
	}
	delete[] potions;
	// delete enemies
	for(int i=0; i<NUM_ENEMIES; i++) {
		if(enemies[i]) delete enemies[i];
	}
	delete[] enemies;
	// delete cells
	for(int i=0; i<HEIGHT; i++) {
		delete[] cells[i];
	}
	delete[] cells;

}

bool Floor::onFloor(int i, int j) {
	return ((0 <= i) && (i <= HEIGHT) && (0 <= j) && (j <= WIDTH));
}

void Floor::addNeighbors(int i, int j) {
	// check north	
	(onFloor(i-1, j))?	cells[i][j].attachNeighbor(&cells[i-1][j]) :
						cells[i][j].attachNeighbor(0);
	// check north east
	(onFloor(i-1, j+1))?	cells[i][j].attachNeighbor(&cells[i-1][j+1]) :
							cells[i][j].attachNeighbor(0);
	// check east	
	(onFloor(i, j+1))?	cells[i][j].attachNeighbor(&cells[i][j+1]) :
						cells[i][j].attachNeighbor(0);
	// check south east	
	(onFloor(i+1, j+1))?	cells[i][j].attachNeighbor(&cells[i+1][j+1]) :
							cells[i][j].attachNeighbor(0);
	// check south	
	(onFloor(i+1, j))?	cells[i][j].attachNeighbor(&cells[i+1][j]) :
						cells[i][j].attachNeighbor(0);
	// check south west
	(onFloor(i+1, j-1))?	cells[i][j].attachNeighbor(&cells[i+1][j-1]) :
							cells[i][j].attachNeighbor(0);
	// check west	
	(onFloor(i, j-1))?	cells[i][j].attachNeighbor(&cells[i][j-1]) :
						cells[i][j].attachNeighbor(0);
	// check north west	
	(onFloor(i-1, j-1))?	cells[i][j].attachNeighbor(&cells[i-1][j-1]) :
							cells[i][j].attachNeighbor(0);
}

// sets x and y according to dir
// dir is a direction
void Floor::changeCoordinate(int &x, int &y, std::string dir) {
	if(dir == "no") {
		x += 0;		
		y += -1;
	} else if(dir == "ne") {
		x += 1;		
		y += -1;
	} else if(dir == "ea") {
		x += 1;		
		y += 0;
	} else if(dir == "se") {
		x += 1;		
		y += 1;
	} else if(dir == "so") {
		x += 0;		
		y += 1;
	} else if(dir == "sw") {
		x += -1;		
		y += 1;
	} else if(dir == "we") {
		x += -1;		
		y += 0;
	} else {
		x += -1;		
		y += -1;
	}
}

// randomly sets x and y into a valid position
void Floor::generateRandPos(int &x, int &y) {	
	do {
		x = rand() % (WIDTH -2) + 1;	// Default: 1 ~ 77
		y = rand() % (HEIGHT -2) + 1;	// Default: 1 ~ 23
	} while(cells[y][x].canMove() != 1);
}

// convert n to corresponding enemy type
// n: 0~6
char Floor::toEnemyType(int n) {
	char ret = 0;	
	switch(n) {
	case 0:
		ret = 'V';
		break;
	case 1:
		ret = 'W';
		break;
	case 2:
		ret = 'N';
		break;
	case 3:
		ret = 'M';
		break;
	case 4:
		ret = 'X';
		break;
	case 5:
		ret = 'T';
		break;
	case 6:
		ret = 'D';
		break;
	default:
		cout << "EnemyConvert ERROR" << endl;
	}
	return ret;
}

void Floor::init(Player *player) {
	if(MAP_NAME != DEFAULT_MAP_NAME) {
			
	} else {
		int x, y;
		srand(time(0));
		// spawn stairs
		generateRandPos(x, y);
		cells[y][x].setType('/');

		ItemFactory item_factory;
		// generate golds and place randomly 
		for(int i=0; i<NUM_GOLDS; i++) {
			int gold_type = rand() % 3 + 6;	// 6 ~ 9
			golds[i] = dynamic_cast<Gold*>(item_factory.generateItem(gold_type));
			generateRandPos(x, y);
			golds[i]->move(x, y);
			cells[golds[i]->getY()][golds[i]->getX()].setPiece(golds[i]);
		}
		
		// generate potions and place randomly
		for(int i=0; i<NUM_POTIONS; i++) {
			int potion_type = rand() % 6;	// 0 ~ 5
			potions[i] = dynamic_cast<Potion*>(item_factory.generateItem(potion_type));
			generateRandPos(x, y);
			potions[i]->move(x, y);
			cells[potions[i]->getY()][potions[i]->getX()].setPiece(potions[i]);
		}

		// generate enemies and place randomly 
		EnemyFactory enemy_factory;
		for(int i=0; i<NUM_ENEMIES; i++) {
			char enemy_type = toEnemyType(rand() % 6);
			enemies[i] = enemy_factory.generateEnemy(enemy_type);
			generateRandPos(x, y);
			enemies[i]->move(x, y);
			cells[enemies[i]->getY()][enemies[i]->getX()].setPiece(enemies[i]);
		}
	
		// set player and locate it randomly
		this->player = player;
		player->reset();
		generateRandPos(x, y);
		player->move(x, y);
		cells[player->getY()][player->getX()].setPiece(player);
	}
}

void Floor::tick() {
	for(int i=0; i<NUM_ENEMIES; i++) {
		if(enemies[i] && !enemies[i]->isDead()) {	// if not dead
			int enem_x = enemies[i]->getX();
			int enem_y = enemies[i]->getY();
			if(enemies[i]->isHostile() && cells[enem_y][enem_x].findPlayer()) {	// if hostile && find a player
				Player *target = dynamic_cast<Player*>(cells[enem_y][enem_x].findPlayer());
				enemies[i]->attack(*target);
			} else {
				int rand_x, rand_y, x, y;
				do {
					rand_x = rand() % 3 -1;
					rand_y = rand() % 3 -1;
					x = enem_x + rand_x;
					y = enem_y + rand_y;
				} while(cells[y][x].canMove() != 1);
				enemies[i]->move(x, y);
				cells[enem_y][enem_x].releasePiece();
				cells[enemies[i]->getY()][enemies[i]->getX()].setPiece(enemies[i]);
			}
		}
	}
}

int Floor::movePlayer(string dir) {
	int ret = 0;
	int x = player->getX();
	int y = player->getY();
	changeCoordinate(x, y, dir);
	
	// check if it's movable cell
	if(1 <= cells[y][x].canMove() && cells[y][x].canMove() <= 4) {		
		if(cells[y][x].canMove() == 3) {	// starirs go up the floor
			ret = 3;
		} else if(cells[y][x].canMove() == 4) {	// golds
			player->pick(*dynamic_cast<Gold*>(cells[y][x].getPiece()));
			for(int i=0; i<NUM_GOLDS; i++) {
				if(golds[i] == cells[y][x].getPiece()) {
					delete golds[i];
					golds[i]=0;
					break;
				}
			}
			cells[y][x].releasePiece();
			ret = 2;
		} else {	// normal move
			ret = 1;
		}
		cells[player->getY()][player->getX()].releasePiece();
		player->move(x, y);
		cells[player->getY()][player->getX()].setPiece(player);
	} else {	// cannot move
		ret = 0;
	}
	return ret;
}

bool Floor::usePotion(string dir) {
	int x = player->getX();
	int y = player->getY();
	changeCoordinate(x, y, dir);

	GamePiece *target = cells[y][x].getPiece();
	if(target && target->isUsable()) {
		player->use(*dynamic_cast<Potion*>(target));
		for(int i=0; i<NUM_POTIONS; i++) {
			if(potions[i] == target) {
				delete potions[i];
				potions[i]=0;
				break;
			}
		}
		cells[y][x].releasePiece();
		return true;
	} else {
		cout << "Can't use that!" << endl;
		return false;
	}
}

bool Floor::attackEnemy(string dir) {
	int x = player->getX();
	int y = player->getY();
	changeCoordinate(x, y, dir);

	GamePiece *target = cells[y][x].getPiece();
	if(target && target->isAttackable()) {
		player->attack(*dynamic_cast<Enemy*>(target));
		if(dynamic_cast<Enemy*>(target)->isDead()) {		// enemy died
			// drop/pick gold
			Gold *drop_item = dynamic_cast<Enemy*>(target)->dropItem();
			if(drop_item) {	// if gold is returned
				player->pick(*drop_item);
				delete drop_item;
			}
			for(int i=0; i<NUM_ENEMIES; i++) {
				if(enemies[i] == target) {
					delete enemies[i];
					enemies[i]=0;
					break;
				}
			}
			cells[y][x].releasePiece();
		}
		return true;
	} else {
		cout << "Can't attack that!" << endl;
		return false;
	}
}

void Floor::printFloor() {
	for(int i=0; i<HEIGHT; i++) {
		for(int j=0; j<WIDTH; j++) {
			cells[i][j].printCell();
		}
		cout << endl;
	}
}
