#ifndef __SHOP_H__
#define __SHOP_H__

//#include "global\globals.h"


#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include <CocoStudio\GUI\UIWidgets\UICheckBox.h>
#include <CocoStudio\GUI\UIWidgets\UISlider.h>
#include "cocos-ext.h"

using namespace cocos2d::ui;
USING_NS_CC;

class Shop : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(Shop);
	virtual bool init();
protected:
	void cbMenuBack(CCObject* obj);
	void cbBuyCredit(CCObject* obj);
	void cbBuy(CCObject* obj);
};

#endif // __SHOP_H__