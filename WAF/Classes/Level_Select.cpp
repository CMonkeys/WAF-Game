#include "Level_Select.h"
#include "Level_Select_Background.h"
USING_NS_CC;

bool Level_Select::init()
{
	CCScene::init();
	m_pLevel_Select = Level_Select::create();

	return true;
}
