#include "Level_Select.h"
#include "Level_Select_Background.h"
USING_NS_CC;

bool Level_Select::init()
{
	CCScene::init();
	m_pLevel_Select_Background = Level_Select_Background::create();
	addChild(m_pLevel_Select_Background, 0);
	return true;
}
