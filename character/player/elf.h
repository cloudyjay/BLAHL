#ifndef __ELF_H__
#define __ELF_H__
	
#include "player.h"

class Elf: public Player {
	
public:
	Elf();
	~Elf();
	void printRace();
};
#endif
