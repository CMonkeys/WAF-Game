#include "Level_Select_Background.h"
#include "Level_One.h"

#pragma once

bool Level_Select_Background::init()
{
	bool setTouchEnabled(true);

	CCLabelTTF* pLevel1_Label = CCLabelTTF::create("Level One",  "Comic Sans", 38);

	CCLabelTTF* pLevel2_Label = CCLabelTTF::create("Level Two",  "Comic Sans", 38);

	CCLabelTTF* pLevel3_Label = CCLabelTTF::create("Level Three",  "Comic Sans", 38);

	CCMenuItemLabel* pLevelOneGame = CCMenuItemLabel::create(pLevel1_Label, this, menu_selector(Level_Select_Background::OneButtonClick));
	CCMenuItemLabel* pLevelTwoGame = CCMenuItemLabel::create(pLevel2_Label, this, menu_selector(Level_Select_Background::TwoButtonClick));
	CCMenuItemLabel* pLevelThreeGame = CCMenuItemLabel::create(pLevel3_Label, this, menu_selector(Level_Select_Background::ThreeButtonClick));

	CCMenu* pMenu = CCMenu::create(pLevelOneGame, pLevelTwoGame, pLevelThreeGame, NULL);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	pMenu->setPosition( ccp( winSize.width * 0.5f, winSize.height * 0.5f));

	pLevelOneGame->setPosition( ccp(0.0f, 64.0f));
	pLevelTwoGame->setPosition( ccp(0.0f, 32.0f));
	pLevelThreeGame->setPosition( ccp(0.0f, 0.0f));
	addChild(pMenu);

	return true;
}

void Level_Select_Background::OneButtonClick(CCObject* obj)
{
	Level_One* Game = Level_One::create();
	CCDirector::sharedDirector()->pushScene(Game);
}

void Level_Select_Background::TwoButtonClick(CCObject* obj)
{
}

void Level_Select_Background::ThreeButtonClick(CCObject* obj)
{
}





