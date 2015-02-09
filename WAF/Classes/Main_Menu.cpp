#include "Main_Menu.h"
#include "Menu.h"
USING_NS_CC;


/*cocos2d::CCScene* Main_Menu::scene()
{
	CCScene *scene = CCScene::create();

	Mai
}*/

bool Main_Menu::init()
{
	CCScene::init();
	m_pMenu = Menu::create();
	addChild(m_pMenu, 0);
	return true;
}












