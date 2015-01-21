#include "MainGameScene.h"

#include "GameplayLayer.h"

bool MainGameScene::init()
{
	CCScene::init();

	Gameplay = GameplayLayer::create();
	addChild(Gameplay);

	return true;
};

CCScene* MainGameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameplayLayer *layer = GameplayLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}