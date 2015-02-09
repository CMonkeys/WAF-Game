#ifndef __LEVEL_SELECT_H__
#define __LEVEL_SELECT_H__

#pragma once
#include "cocos2d.h"
#include "Level_Select_Background.h"
USING_NS_CC;

class Level_Select : public CCScene
{
public:

	virtual bool init();

	CREATE_FUNC(Level_Select);

protected:

	Level_Select_Background* m_pLevel_Select_Background;
};

#endif __LEVEL_SELECT_H__
