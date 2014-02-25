#ifndef __GAMEPIECE_H__
#define __GAMEPIECE_H__

class GamePiece {
	char symbol;
	int x, y;
public:
	GamePiece(char symbol);
	void move(int x, int y);
	void printSelf();
	int getX();
	int getY();
	virtual bool isAttackable()=0;
	virtual bool isUsable()=0;
	virtual bool isPickable()=0;
	virtual bool isPlayer();
};

#endif
