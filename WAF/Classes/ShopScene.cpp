#include "ShopScene.h"
#include "Shop.h"

USING_NS_CC;

bool ShopScene::init()
{
	CCScene::init();
	
	Shop* shop = Shop::create();
	addChild(shop);

	return true;
}
