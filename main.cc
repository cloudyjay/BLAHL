#include <string>
#include "interface.h"
using namespace std;

int main(int argc, char *argv[]) {
	if(argc == 1)	Interface main_game("map/default");
	else 			Interface main_game(argv[1]);

	while(!main_game.isEnd()) {
	
	}
}

