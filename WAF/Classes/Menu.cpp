#include "Menu.h"
#include "Level_Select.h"

bool Menu::init()
{
	bool setTouchEnabled(true);

	CCLabelTTF* pLevel_Label = CCLabelTTF::create("Level Select",  "Comic Sans", 38);
	CCPoint labPosition = ccp(0, 150 );
	pLevel_Label->setPosition(labPosition);
	addChild(pLevel_Label);

	CCLabelTTF* pScore_Label = CCLabelTTF::create("Scoreboard",  "Comic Sans", 38);
	CCPoint labelPosition = ccp(0, 100 );
	pScore_Label->setPosition(labelPosition);
	addChild(pScore_Label);

	CCLabelTTF* pOptions_Label = CCLabelTTF::create("Options",  "Comic Sans", 38);
	CCPoint labPos = ccp(0, 0 );
	pLevel_Label->setPosition(labPos);
	addChild(pOptions_Label);

	CCLabelTTF* pQuit_Label = CCLabelTTF::create("Exit Game",  "Comic Sans", 38);
	CCPoint labelPos = ccp(0, -50 );
	pQuit_Label->setPosition(labelPos);

	CCMenuItemLabel* StartGame = CCMenuItemLabel::create(pLevel_Label, this, menu_selector(Menu::Level_ButtonClick));
	CCMenuItemLabel* ScoreGame = CCMenuItemLabel::create(pScore_Label, this, menu_selector(Menu::Score_ButtonClick));
	CCMenuItemLabel* OptionsGame = CCMenuItemLabel::create(pOptions_Label, this, menu_selector(Menu::Options_ButtonClick));
	CCMenuItemLabel* EndGame = CCMenuItemLabel::create(pQuit_Label, this, menu_selector(Menu::Quit_ButtonClick));

	CCMenu* pMenu = CCMenu::create(StartGame, ScoreGame, OptionsGame, EndGame, NULL);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	pMenu->setPosition( ccp( winSize.width * 0.5f, winSize.height * 0.5f));
	addChild(pMenu, 1);

	return true;
}

void Menu::Level_ButtonClick(CCObject* obj)
{
	Level_Select* Game = Level_Select::create();

}

void Menu::Score_ButtonClick(CCObject* obj)
{
}

void Menu::Options_ButtonClick(CCObject* obj)
{
}

void Menu::Quit_ButtonClick(CCObject* obj)
{
	exit(0);
}





