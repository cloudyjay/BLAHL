#include <cmath>
#include <iostream>
#include <string>
#include "character.h"
using namespace std;

Character::Character(char type, int hp, int atk, int def): GamePiece(type), MAX_HP(hp), 
														hp(hp), atk(atk), def(def), tmp_atk(0), tmp_def(0) {
}

Character::~Character() {
}

int Character::currentAttack() {
	return atk + tmp_atk;
}

int Character::currentDefence() {
	return def + tmp_def;
}

void Character::printHealth() {
	cout << hp;
}

void Character::printAttack() {
	cout << currentAttack();
}

void Character::printDefence() {
	cout << def + tmp_def;
}

void Character::reset() {
	tmp_atk = 0;
	tmp_def = 0;
}

void Character::attack(Character &target) {
	target.defense(currentAttack());
}

void Character::defense(int target_atk) {
	int dmg = (int)ceil( (100/(double)(100+def)) * target_atk);
	hp -= dmg;
}

void Character::use(Potion &potion) {
	string potion_type = potion.getType();
	if(potion_type == "RH" || potion_type == "PH") {
		hp += potion.getEffect();
		if(MAX_HP < hp) {
			hp = MAX_HP;
		}
	} else if(potion_type == "BA" || potion_type == "WA") {
		tmp_atk += potion.getEffect();
		if(currentAttack() < 0) {
			tmp_atk = -atk;
		}
	} else if(potion_type == "BD" || potion_type == "WD") {
		tmp_def += potion.getEffect();
		if(currentDefence() < 0) {
			tmp_def = -def;
		}
	} else {
		cout << "INVALID POTION USED !!!!" << endl;
	}
}

bool Character::isDead() {
	return (hp <= 0);
}

bool Character::isAttackable() {
	return true;
}

bool Character::isUsable() {
	return false;
}

bool Character::isPickable() {
	return false;
}
