#include "playerfactory.h"
using namespace std;

#include "human.h"

Player *PlayerFactory::generatePlayer(char c) {
	Player *ret;
	if(c == 'h') {
		ret = new Human();
	}
	else if(c == 'e') {

	}
	else if(c == 'd') {

	}
	else if(c == 'o') {

	}
	else {
		ret = 0;
	}

	return ret;
}
