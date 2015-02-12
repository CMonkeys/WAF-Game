#include "OptionsScene.h"
#include "Options.h"
USING_NS_CC;
bool OptionsScene::init()
{
	CCScene::init();
	Options* options = Options::create();
	addChild(options);

	return true;
}