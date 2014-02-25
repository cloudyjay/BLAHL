#include <string>
#include "interface.h"
using namespace std;

int main(int argc, char *argv[]) {
	string map = (argc == 2)? argv[1] : "map/default.map";
	Interface main_game(map);
	
	while(!main_game.isEnd()) {
		main_game.playTurn();
	}
	main_game.printScore();

	return 0;
}

