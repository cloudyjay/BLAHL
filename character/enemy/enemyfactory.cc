#include "enemyfactory.h"
using namespace std;

#include "vampire.h"

Enemy *EnemyFactory::generateEnemy(char c) {
	Enemy *ret;
	if(c == 'V') {
		ret = new Vampire();
	}
	else if(c == 'W') {
	}
	else if(c == 'N') {
	}
	else if(c == 'M') {
	}
	else if(c == 'D') {
	}
	else if(c == 'X') {
	}
	else if(c == 'T') {
	}
	else if(c == 'M') {
	}
	else {
		ret = 0;
	}

	return ret;
}
