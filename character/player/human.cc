#include <iostream>
#include "human.h"
using namespace std;

Human::Human() : Player(140, 20, 20) {}

Human::~Human() {}

void Human::defense(int target_atk) {
	Character::defense(target_atk);
	if(isDead()) {
		
	}
}

void Human::printRace() {
	cout << "Human";
}
