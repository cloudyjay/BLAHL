#ifndef __POTION_H__
#define __POTION_H__

#include <string>
#include "../item.h"

class Potion: public Item {
	std::string type;
	int effect;		// effect can be +/- 
public:
	Potion(std::string type, int effect);
	bool isUsable();
	bool isPickable();
	std::string getType();
	int getEffect();
	~Potion();
};

#endif
