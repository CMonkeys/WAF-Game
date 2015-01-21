#ifndef __LEVEL_ONE_H__
#define __LEVEL_ONE_H__

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Level_One : public CCScene
{
public:

	virtual bool init();

	CREATE_FUNC(Level_One);

protected:

	Level_One* m_pLevel_One;
};

#endif __LEVEL_ONE_H__