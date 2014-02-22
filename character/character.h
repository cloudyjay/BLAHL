#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "../gamepiece.h"
class Character: public GamePiece {
	int hp;
	int atk;
	int def;
	
public:
	Character(char type, int hp, int atk, int def);
	void printHealth();
	void printAttack();
	void printDefence();
	virtual bool isAttackable();
	virtual bool isUsable();
	virtual bool isPickable();
	virtual void attack(Character &target);
	virtual void defense(int target_atk);
	virtual ~Character()=0;
};

#endif
