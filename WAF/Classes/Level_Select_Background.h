#ifndef __LEVEL_SELECT_BACKGROUND__
#define __LEVEL_SELECT_BACKGROUND__

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Level_Select_Background : public CCLayer
{
public:

	virtual bool init();

	void OneButtonClick(CCObject* obj);
	void TwoButtonClick(CCObject* obj);
	void ThreeButtonClick(CCObject* obj);

	CREATE_FUNC(Level_Select_Background);
};

#endif __LEVEL_SELECT_BACKGROUND__

