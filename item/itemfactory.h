#ifndef __ITEMFACTORY_H__
#define __ITEMFACTORY_H__

#include "item.h"

class ItemFactory {
public:
	// PRE: n is 0 ~ 9
	Item *generateItem(int n);
};

#endif
