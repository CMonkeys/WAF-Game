#ifndef __MENU_H__
#define __MENU_H__

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Menu : public CCLayer
{
public:

	virtual bool init();

	void Level_ButtonClick(CCObject* obj);
	void Quit_ButtonClick(CCObject* obj);
	void Score_ButtonClick(CCObject* obj);
	void Options_ButtonClick(CCObject* obj);
	void Donate_ButtonClick(CCObject* obj);

	CREATE_FUNC(Menu);
};

#endif __MENU_H__
