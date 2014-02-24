#include "itemfactory.h"
using namespace std;

Gold *ItemFactory::generateGold(int n) {
	Gold *ret = 0;
	switch(n) {
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
