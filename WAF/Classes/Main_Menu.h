#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Main_Menu : public cocos2d::CCScene
{
public:
	virtual bool init();

	CREATE_FUNC(Main_Menu);

protected:

	Main_Menu* m_pMenu;

};

#endif __MAIN_MENU_H__
