#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#pragma once
#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include <CocoStudio\GUI\UIWidgets\UICheckBox.h>
#include <CocoStudio\GUI\UIWidgets\UISlider.h>
#include "cocos-ext.h"
using namespace cocos2d::ui;
USING_NS_CC;

class Options : public CCLayer
{
public:
	CREATE_FUNC(Options);
	virtual bool init();
	UILayer* m_pLayer;
	UICheckBox* checkVibrations;
	UISlider* volSlider;

protected:

	void cbMenuBack(CCObject* obj);
	void cbOptionsReset(CCObject* obj);
	void cbOptionsDefault(CCObject* obj);
	void cdSetVibrations(CCObject* pSender, CheckBoxEventType type);
	void cdPercentChangedEvent(CCObject *pSender, SliderEventType type);
};

#endif __OPTIONS_H__