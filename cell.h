#ifndef __CELL_H__
#define __CELL_H__

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
	
public:
	Cell();
	~Cell();
	// PRE: true
	// POST: one of neighbors get filled
	void attachNeighbor(Cell *neighbor);
	void setType(char c);
};

#endif
