#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#pragma once
#include "cocos2d.h"
#include "Menu.h"
USING_NS_CC;

class Main_Menu : public cocos2d::CCScene
{
public:
	virtual bool init();

	//static cocos2d::CCScene* scene();

	CREATE_FUNC(Main_Menu);

protected:

	Menu* m_pMenu;

};

#endif __MAIN_MENU_H__
