#include <iostream>
#include "elf.h"
using namespace std;

Elf::Elf() : Player(140, 30, 10) {}

Elf::~Elf() {}

void Elf::printRace() {
	cout << "Elf";
}
