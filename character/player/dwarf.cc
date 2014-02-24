#include <iostream>
#include "dwarf.h"
using namespace std;

Dwarf::Dwarf() : Player(100, 20, 30) {}

Dwarf::~Dwarf() {}

void Dwarf::printRace() {
	cout << "Dwarf";
}
