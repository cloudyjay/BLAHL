#include <iostream>
#include "human.h"
using namespace std;

Human::Human() : Player(140, 20, 20) {}

Human::~Human() {}

void Human::printRace() {
	cout << "Human";
}
