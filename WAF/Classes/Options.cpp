#include "Options.h"
#include "ShopScene.h"
#include "Main_Menu.h"
#include "cocos2d.h"
#include <CocoStudio\GUI\UIWidgets\UICheckBox.h>
#include <CocoStudio\GUI\UIWidgets\UISlider.h>
#include <CocoStudio\GUI\System\UITouchGroup.h>
#include <CocoStudio\GUI\UIWidgets\Compatible\CompatibleClasses.h>
#include <CocoStudio\Reader\GUIReader.h>


using namespace cocos2d::ui;
USING_NS_CC;

bool Options::init()
{
	m_pLayer = UILayer::create();
    addChild(m_pLayer);

	//for positioning:
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//Create Labels
	CCLabelTTF* lblBack=CCLabelTTF::create( "Back", "Arial", 24 );
	CCLabelTTF* lblReset=CCLabelTTF::create( "Reset Score", "Arial", 24 );
	CCLabelTTF* lblDefault=CCLabelTTF::create( "Default Settings", "Arial", 24 );
	CCLabelTTF* lblVibrations=CCLabelTTF::create( "Vibrations", "Arial", 24 );
	CCLabelTTF* lblVolume=CCLabelTTF::create( "Sound", "Arial", 24 );

	//Create Checkbox
	checkVibrations = UICheckBox::create();
	checkVibrations->setTouchEnabled(true);
	checkVibrations->loadTextures("cocosgui/check_box_normal.png",
						   "cocosgui/check_box_normal_press.png",
					       "cocosgui/check_box_active.png",
                           "cocosgui/check_box_normal_disable.png",
                           "cocosgui/check_box_active_disable.png");
	checkVibrations->setPosition(ccp(winSize.width / 2.0f, winSize.height - winSize.height / 4.0f));
	checkVibrations->addEventListenerCheckBox(this,checkboxselectedeventselector(Options::cdSetVibrations));
  
	//ADD Checkbox
	lblVibrations->setPosition(ccp(winSize.width / 4.0f, winSize.height - winSize.height / 4.0f));
	m_pLayer->addWidget(checkVibrations);
	m_pLayer->addChild(lblVibrations);

	//Create Slider
	volSlider = UISlider::create();
	volSlider->setTouchEnabled(true);
    volSlider->loadBarTexture("cocosgui/sliderTrack.png");
    volSlider->loadSlidBallTextures("cocosgui/sliderThumb.png", "cocosgui/sliderThumb.png", "");
    volSlider->loadProgressBarTexture("cocosgui/sliderProgress.png");
	volSlider->setPosition(ccp(winSize.width / 1.5f,winSize.height - winSize.height / 2.0f));
	volSlider->addEventListenerSlider(this, sliderpercentchangedselector(Options::cdPercentChangedEvent));
	
	//Add Slider
	lblVolume->setPosition(ccp(winSize.width / 4.0f, winSize.height - winSize.height / 2.0f));
	m_pLayer->addWidget(volSlider);
	m_pLayer->addChild(lblVolume);


	//Create Buttons
	CCMenuItemLabel* btnBack = CCMenuItemLabel::create(lblBack,this,menu_selector(Options::cbMenuBack));
	CCMenuItemLabel* btnReset = CCMenuItemLabel::create(lblReset,this,menu_selector(Options::cbOptionsReset));
	CCMenuItemLabel* btnDefault = CCMenuItemLabel::create(lblDefault,this,menu_selector(Options::cbOptionsDefault));

	//make them visible	
	CCMenu* pMenu = CCMenu::create(btnDefault,btnReset, btnBack, NULL);
	pMenu->setPosition( ccp(winSize.width * 0.5f, winSize.height * 0.2) );
	pMenu->alignItemsVerticallyWithPadding( 14.0f );
	addChild(pMenu,1);
	return true;
}

void Options::cbMenuBack(CCObject* obj)
{
	CCDirector::sharedDirector()->pushScene( Main_Menu::create() );
}

void Options::cbOptionsReset(CCObject* obj)
{
	//TODO
}

void Options::cbOptionsDefault(CCObject* obj)
{
	//TODO
}

void Options::cdSetVibrations(CCObject* pSender, CheckBoxEventType type)
{
	switch(type)
	{
	case CHECKBOX_STATE_EVENT_SELECTED:
		  //_displayValueLabel->setString(CCString::createWithFormat("Selected")->getCString());
          //TODO  
		  break;

    case CHECKBOX_STATE_EVENT_UNSELECTED:
            //_displayValueLabel->setString(CCString::createWithFormat("Unselected")->getCString());
           //TODO
			break;

    default:
            break;

	}
}
 void Options::cdPercentChangedEvent(CCObject *pSender, SliderEventType type)
   {
        if (type == SLIDER_PERCENTCHANGED)
        {
            UISlider* slider = dynamic_cast<UISlider*>(pSender);
            int percent = slider->getPercent();
          // m_pDisplayValueLabel->setText(CCString::createWithFormat("Percent %d", percent)->getCString());
       }
    }

