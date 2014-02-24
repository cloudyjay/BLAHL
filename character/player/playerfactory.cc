#include "playerfactory.h"
using namespace std;

#include "human.h"
#include "elf.h"
#include "orc.h"
#include "dwarf.h"

Player *PlayerFactory::generatePlayer(char c) {
	Player *ret;
	if(c == 'h') {
		ret = new Human();
	}
	else if(c == 'e') {
		ret = new Elf();
	}
	else if(c == 'd') {
		ret = new Dwarf();
	}
	else if(c == 'o') {
		ret = new Orc();
	}
	else {
		ret = 0;
	}

	return ret;
}
