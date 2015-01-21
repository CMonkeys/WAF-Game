#include "Level_Select_Background.h"
#include "Level_One.h"

#pragma once

bool Level_Select_Background::init()
{
	bool setTouchEnabled(true);

	CCLabelTTF* pLevel1_Label = CCLabelTTF::create("Level One",  "Comic Sans", 38);
	CCPoint labPosition = ccp(0, 150 );
	pLevel1_Label->setPosition(labPosition);
	addChild(pLevel1_Label);

	CCLabelTTF* pLevel2_Label = CCLabelTTF::create("Level Two",  "Comic Sans", 38);
	CCPoint labelPosition = ccp(0, 100 );
	pLevel2_Label->setPosition(labelPosition);
	addChild(pLevel2_Label);

	CCLabelTTF* pLevel3_Label = CCLabelTTF::create("Level Three",  "Comic Sans", 38);
	CCPoint labPos = ccp(0, 0 );
	pLevel3_Label->setPosition(labPos);
	addChild(pLevel3_Label);

	CCMenuItemLabel* LevelOneGame = CCMenuItemLabel::create(pLevel1_Label, this, menu_selector(Level_Select_Background::OneButtonClick));
	CCMenuItemLabel* LevelTwoGame = CCMenuItemLabel::create(pLevel2_Label, this, menu_selector(Level_Select_Background::TwoButtonClick));
	CCMenuItemLabel* LevelThreeGame = CCMenuItemLabel::create(pLevel3_Label, this, menu_selector(Level_Select_Background::ThreeButtonClick));

	CCMenu* pMenu = CCMenu::create(LevelOneGame, LevelTwoGame, LevelThreeGame, NULL);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	pMenu->setPosition( ccp( winSize.width * 0.5f, winSize.height * 0.5f));
	addChild(pMenu, 1);

	return true;
}

void Level_Select_Background::OneButtonClick(CCObject* obj)
{
	Level_One* Game = Level_One::create();
}

void Level_Select_Background::TwoButtonClick(CCObject* obj)
{
}

void Level_Select_Background::ThreeButtonClick(CCObject* obj)
{
}





