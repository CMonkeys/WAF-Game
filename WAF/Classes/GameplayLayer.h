#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

USING_NS_CC;

class GameplayLayer : public cocos2d::CCLayer, public b2ContactListener
{
public:
	
	virtual bool init();  
    
    CREATE_FUNC(GameplayLayer);

	void initPhysics();

	void updateFunc(float dt);

	static int score;

	void onEnter();
	void onExit();

	void BeginContact(b2Contact* contact);

	void didAccelerate(CCAcceleration* pAccelerationValue);

	//---
	static float timeC;
	static char strBuff[64];
	static CCLabelTTF* lblTimer;
	static CCLabelTTF* lblScore;


protected:
	static float xPTM;
	static float xMTP;
	
	b2World* gameWorld;
	b2Body* platformBody[5];
	CCSprite* scrollingBackground[2];
	b2Body* playerBody;
	b2Body* worldEdges;
};

#endif
