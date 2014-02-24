#ifndef __ITEM_H__
#define __ITEM_H__

#include "../gamepiece.h"
class Item: public GamePiece {
public:
	Item(char type);
	virtual bool isAttackable();
	virtual bool isUsable()=0;
	virtual bool isPickable()=0;
	virtual ~Item()=0;
};

#endif
