#include "itemfactory.h"
#include "gold/gold.h"
#include "potion/potion.h"
using namespace std;

Item *ItemFactory::generateItem(int n) {
	Item *ret = 0;
	switch(n) {
	case 0:
		ret = new Potion("RH", 10);
		break;
	case 1:
		ret = new Potion("BA", 5);
		break;
	case 2:
		ret = new Potion("BD", 5);
		break;
	case 3:
		ret = new Potion("PH", -10);
		break;
	case 4:
		ret = new Potion("WA", -5);
		break;
	case 5:
		ret = new Potion("WD", -5);
		break;
	case 6:
		ret = new Gold();
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	default:
		ret = 0;
		break;

	}

	return ret;
}
