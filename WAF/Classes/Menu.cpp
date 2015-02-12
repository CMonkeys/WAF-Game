#include "Menu.h"
#include "Level_Select.h"
#include "OptionsScene.h"
#include "ShopScene.h"


bool Menu::init()
{
	bool setTouchEnabled(true);

	CCLabelTTF* pLevel_Label = CCLabelTTF::create("Level Select",  "Comic Sans", 28);

	CCLabelTTF* pScore_Label = CCLabelTTF::create("Scoreboard",  "Comic Sans", 28);

	CCLabelTTF* pOptions_Label = CCLabelTTF::create("Options",  "Comic Sans", 28);

	CCLabelTTF* pShop_Label = CCLabelTTF::create("Shop",  "Comic Sans", 28);

	CCLabelTTF* pQuit_Label = CCLabelTTF::create("Exit Game",  "Comic Sans", 28);



	CCMenuItemLabel* pStartGame = CCMenuItemLabel::create(pLevel_Label, this, menu_selector(Menu::Level_ButtonClick));
	CCMenuItemLabel* pScoreGame = CCMenuItemLabel::create(pScore_Label, this, menu_selector(Menu::Score_ButtonClick));
	CCMenuItemLabel* pOptionsGame = CCMenuItemLabel::create(pOptions_Label, this, menu_selector(Menu::Options_ButtonClick));
	CCMenuItemLabel* pShopGame = CCMenuItemLabel::create(pShop_Label, this, menu_selector(Menu::Shop_ButtonClick));
	CCMenuItemLabel* pEndGame = CCMenuItemLabel::create(pQuit_Label, this, menu_selector(Menu::Quit_ButtonClick));

	CCMenu* pMenu = CCMenu::create(pStartGame, pScoreGame, pOptionsGame,pShopGame, pEndGame, NULL);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	pMenu->setPosition( ccp( winSize.width * 0.5f, winSize.height * 0.5f));

	pStartGame->setPosition( ccp(0.0f, 128.0f));
	pScoreGame->setPosition( ccp(0.0f, 64.0f));
	pOptionsGame->setPosition( ccp(0.0f, 0.0f));
	pShopGame->setPosition( ccp(0.0f, -64.0f));
	pEndGame->setPosition( ccp(0.0f, -128.0f));
	addChild(pMenu);
	
	return true;
}

void Menu::Level_ButtonClick(CCObject* obj)
{
	Level_Select* Game = Level_Select::create();
	CCDirector::sharedDirector()->pushScene(Game);
}

void Menu::Score_ButtonClick(CCObject* obj)
{
}

void Menu::Options_ButtonClick(CCObject* obj)
{
	CCDirector::sharedDirector()->pushScene( OptionsScene::create() );
}
void Menu::Shop_ButtonClick(CCObject* obj)
{
	CCDirector::sharedDirector()->pushScene( ShopScene::create() );
}

void Menu::Quit_ButtonClick(CCObject* obj)
{
	exit(0);
}





