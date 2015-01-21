#ifndef __LEVEL_SELECT_H__
#define __LEVEL_SELECT_H__

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Level_Select : public CCScene
{
public:

	virtual bool init();

	CREATE_FUNC(Level_Select);

protected:

	Level_Select* m_pLevel_Select;
};

#endif __LEVEL_SELECT_H__
