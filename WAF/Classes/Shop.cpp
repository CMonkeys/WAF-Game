#include "Box2D\Box2D.h"

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "Shop.h"
#include "Main_Menu.h"
#include <CocoStudio\GUI\UIWidgets\UICheckBox.h>
#include <CocoStudio\GUI\UIWidgets\UISlider.h>
#include <CocoStudio\GUI\System\UITouchGroup.h>
#include <CocoStudio\GUI\UIWidgets\Compatible\CompatibleClasses.h>
#include <CocoStudio\Reader\GUIReader.h>

using namespace cocos2d::ui;
USING_NS_CC;

bool Shop::init()
{
	//for positioning:
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	//Create LAbels
	CCLabelTTF* lblBack=CCLabelTTF::create( "Back", "Arial", 24 );
	CCLabelTTF* lblBuyCredit=CCLabelTTF::create( "Buy Credit", "Arial", 24 );
	CCLabelTTF* lblCharacters=CCLabelTTF::create( "Characters", "Arial", 24 );
	CCLabelTTF* lblUpgrades=CCLabelTTF::create( "Upgrades", "Arial", 24 );
	CCLabelTTF* lblSkins=CCLabelTTF::create( "Skins", "Arial", 24 );

	//Create Character Buttons
	CCMenuItemImage* btnChar01 = CCMenuItemImage::create("cocosgui/sliderballnormal.png",
                                        "cocosgui/sliderballpressed.png",this,menu_selector(Shop::cbBuy));
	//make visible
	CCMenu* charMenu = CCMenu::create(btnChar01, NULL);
	charMenu->setPosition( ccp( winSize.width * 0.2f, winSize.height * 0.8 ));
	charMenu->alignItemsVerticallyWithPadding( 5.0f );
	addChild(charMenu,1);

	//Create Upgrade Buttons
	CCMenuItemImage* btnUpgrade01 = CCMenuItemImage::create("cocosgui/sliderballnormal.png",
                                        "cocosgui/sliderballpressed.png",this,menu_selector(Shop::cbBuy));
	//make visible
	CCMenu* upgradesMenu = CCMenu::create(btnUpgrade01, NULL);
	upgradesMenu->setPosition( ccp( winSize.width * 0.2f, winSize.height * 0.6 ));
	upgradesMenu->alignItemsVerticallyWithPadding( 5.0f );
	addChild(upgradesMenu,1);

	//Creade Skin Buttons
	CCMenuItemImage* btnSkin01 = CCMenuItemImage::create("cocosgui/sliderballnormal.png",
                                        "cocosgui/sliderballpressed.png",this,menu_selector(Shop::cbBuy));
	//make visible
	CCMenu* skinsMenu = CCMenu::create(btnSkin01, NULL);
	skinsMenu->setPosition( ccp( winSize.width * 0.2f, winSize.height * 0.4 ));
	skinsMenu->alignItemsVerticallyWithPadding( 5.0f );
	addChild(skinsMenu,1);


	//Create Buttons
	CCMenuItemLabel* btnBack = CCMenuItemLabel::create(lblBack,this,menu_selector(Shop::cbMenuBack));
	CCMenuItemLabel* btnCredit = CCMenuItemLabel::create(lblBuyCredit,this,menu_selector(Shop::cbBuyCredit));
	
	//position & add labels	
	lblCharacters->setPosition( ccp( winSize.width * 0.2f, winSize.height * 0.9 ));
	lblUpgrades->setPosition( ccp( winSize.width * 0.2f, winSize.height * 0.7 ));
	lblSkins->setPosition( ccp( winSize.width * 0.2f, winSize.height * 0.5 ));
	addChild(lblCharacters);
	addChild(lblUpgrades);
	addChild(lblSkins);

	//make them visible
	CCMenu* pMenu = CCMenu::create(btnCredit,btnBack, NULL);
	pMenu->setPosition( ccp( winSize.width * 0.5f, winSize.height * 0.1 ));
	pMenu->alignItemsVerticallyWithPadding( 14.0f );
	addChild(pMenu,1);
	return true;
}

void Shop::cbBuyCredit(CCObject* obj)
{
	//TODO
}

void Shop::cbMenuBack(CCObject* obj)
{
	CCDirector::sharedDirector()->pushScene( Main_Menu::create() );
}
void Shop::cbBuy(CCObject* obj)
{
	//TODO
}
