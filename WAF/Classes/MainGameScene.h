#pragma once

#include "cocos2d.h"

USING_NS_CC;

class MainGameScene : public CCScene
{
public:
	
	bool init();

	 static cocos2d::CCScene* scene();

	CREATE_FUNC(MainGameScene);

protected:
	CCLayer* Gameplay;
	CCLayer* GameUI;
};