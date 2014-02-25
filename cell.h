#ifndef __CELL_H__
#define __CELL_H__

#include "gamepiece.h"
// Cell class is one block of Floor class
// It's an observer to its neigboring cells
// It might have a pointer to an object
class Cell {
	char type;		
		// type can be:
		//	' ' - blank
		//	'.' - floor
		//  '\' - vertical wall
		//  '-' - horizontal wall
		//	'+' - door
		//	'#' - passage
		//  '/' - stairs 
	int num_neighbors;
	Cell *neighbors[8];		
		// 0 - north
		// 1 - north east
		// 2 - east
		// 3 - south east
		// 4 - south
		// 5 - south west
		// 6 - west
		// 7 - north west
	GamePiece *piece;
	
public:
	Cell();
	~Cell();
	// PRE: true
	// POST: one of neighbors get filled
	void attachNeighbor(Cell *neighbor);
	void setType(char c);
	GamePiece *getPiece();
	void setPiece(GamePiece *piece);
	GamePiece *releasePiece();
	bool hasPlayer();
	GamePiece *findPlayer();
	void printCell();
	// PRE: true
	// POST:	0 - can't move
	//			1 - can move
	//			2 - door OR passage
	//			3 - stairs
	//			4 - gold
	int canMove();
};

#endif
