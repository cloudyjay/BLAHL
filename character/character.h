#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "../gamepiece.h"
#include "../item/potion/potion.h"
class Character: public GamePiece {
	int MAX_HP;
	int hp;
	int atk;
	int def;
	int tmp_atk;
	int tmp_def;

	int currentAttack();
	int currentDefence();
public:
	Character(char type, int hp, int atk, int def);
	void printHealth();
	void printAttack();
	void printDefence();
	void reset();
	bool isDead();
	virtual bool isAttackable();
	virtual bool isUsable();
	virtual bool isPickable();
	virtual void attack(Character &target);
	virtual void defense(int target_atk);
	virtual void use(Potion &potion);
	virtual ~Character()=0;
};

#endif
