#include "itemfactory.h"
#include "gold/gold.h"
#include "gold/smallhoard.h"
#include "gold/merchanthoard.h"
#include "gold/dragonhoard.h"
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
		ret = new SmallHoard();
		break;
	case 8:
		ret = new MerchantHoard();
		break;
	case 9:
		ret = new DragonHoard();
		break;
	default:
		ret = 0;
		break;

	}

	return ret;
}
