#include <iostream>
#include "orc.h"
using namespace std;

Orc::Orc() : Player(180, 30, 25) {}

Orc::~Orc() {}

void Orc::printRace() {
	cout << "Orc";
}
