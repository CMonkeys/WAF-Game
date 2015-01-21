#include <time.h>

#include "GameplayLayer.h"
#include "B2DebugDrawLayer.h"

USING_NS_CC;

float GameplayLayer::xPTM = 10;
float GameplayLayer::xMTP = 1.0f/xPTM;
float offset = 0.0f;
float scrollSpeed = 0.5f;
CCSize winSize;
int GameplayLayer::score = 0;
//--
char GameplayLayer::strBuff[64];
float GameplayLayer::timeC=0.0f;
CCLabelTTF* GameplayLayer:: lblTimer;
CCLabelTTF* GameplayLayer:: lblScore;

void GameplayLayer::initPhysics()
{
	b2Vec2 gravity(0, 0.0f);
	gameWorld = new b2World(gravity);
	gameWorld->SetContactListener(this);
	B2DebugDrawLayer* debugdraw = B2DebugDrawLayer::create(gameWorld, xPTM);
	addChild(debugdraw, 9999);
}

bool GameplayLayer::init()
{
	//seeding the RNG for platform placement
	srand(time(NULL));
	initPhysics();

	winSize = CCDirector::sharedDirector()->getWinSize();

	//Adding terrible background


	//defining the player ball character thing
	b2BodyDef playerDef;
	playerDef.type = b2_dynamicBody;
	playerDef.position.Set(2.6f*xPTM, 1.6f*xPTM);
	playerDef.linearDamping = 0.5f;

	CCSprite* playerSprite = CCSprite::create("testplayer1.png");
	addChild(playerSprite, 100);
	playerDef.userData = playerSprite;

	CCSprite* LevelGround = CCSprite::create("testlevel.png");
	addChild(LevelGround, 10);
	LevelGround->setPosition(ccp(winSize.width/2 - 18,winSize.height/2)); 

	b2CircleShape playershape;
	playershape.m_radius = 1.5f;

	b2FixtureDef playerfixdef;
	playerfixdef.shape = &playershape;
	playerfixdef.restitution = 0.8f;

	playerBody = gameWorld->CreateBody(&playerDef);
	playerBody->CreateFixture( &playerfixdef);

	//defining the Level



	//Defining the edges of the world
	b2EdgeShape worldEdgeShape;
	b2BodyDef EdgesDef;

	EdgesDef.position = b2Vec2(0.0f,0.0f);
	EdgesDef.type = b2_kinematicBody;

	worldEdges = gameWorld->CreateBody(&EdgesDef);

	worldEdgeShape.Set(b2Vec2(0.0f, 0.0f), b2Vec2(0.0f, winSize.height * xMTP));
	worldEdges->CreateFixture(&worldEdgeShape, 1.0f);

	worldEdgeShape.Set(b2Vec2(0.0f, winSize.height * xMTP), b2Vec2(winSize.width * xMTP, winSize.height * xMTP));
	worldEdges->CreateFixture(&worldEdgeShape, 1.0f);

	worldEdgeShape.Set(b2Vec2(winSize.width * xMTP, 0.0f), b2Vec2(winSize.width * xMTP, winSize.height * xMTP));
	worldEdges->CreateFixture(&worldEdgeShape, 1.0f);

	worldEdgeShape.Set(b2Vec2(0.0f, 0.0f), b2Vec2(winSize.width * xMTP, 0.0f));
	worldEdges->CreateFixture(&worldEdgeShape, 1.0f);
	
	
	//Schedule the update function

	schedule(schedule_selector(GameplayLayer::updateFunc));

	return true;
};

void GameplayLayer::updateFunc(float dt)
{
	gameWorld->Step(dt, 10, 8);

	//Player falling off level checks.
	if(((playerBody->GetTransform().p.y + 1.5f)*xPTM < -offset)||((playerBody->GetTransform().p.y - 1.5f)*xPTM > winSize.height - offset))
	{
		CCDirector::sharedDirector()->popScene();
	}

	//drawing the platforms and player
	for(b2Body* b = gameWorld->GetBodyList(); b!= NULL; b = b->GetNext())
	{
		if(b->GetUserData())
		{
			CCSprite* display = (CCSprite*)b->GetUserData();
			display->setPosition(ccp(b->GetPosition().x * xPTM, b->GetPosition().y * xPTM));
			display->setRotation(CC_RADIANS_TO_DEGREES(-b->GetAngle()));
		}
	}

	//update time
	timeC+=0.01;
	score+=timeC/1.5;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	removeChild(lblTimer);
	sprintf(strBuff, "%.2f", timeC);
	lblTimer=CCLabelTTF::create(strBuff,"Arial",24);
	//position label:
	lblTimer->setPosition(ccp(origin.x+visibleSize.width-lblTimer->getContentSize().width,origin.y+visibleSize.height-lblTimer->getContentSize().height));
	//make it visible:
	addChild(lblTimer);
	//score:
	removeChild(lblScore);
	sprintf(strBuff,  "%d", score);
	lblScore=CCLabelTTF::create(strBuff,"Arial",24);
	//position label:
	lblScore->setPosition(ccp(origin.x+visibleSize.width-lblTimer->getContentSize().width,origin.y+visibleSize.height-lblTimer->getContentSize().height*2));
	//make it visible:
	addChild(lblScore);
	
	gameWorld->DrawDebugData();
};

void GameplayLayer::onEnter()
{
	score = 0;
	CCLayer::onEnter();
	setAccelerometerEnabled(true);
};

void GameplayLayer::onExit()
{
	scrollSpeed = 0.5f;
	offset = 0;
	CCLayer::onExit();
	setAccelerometerEnabled(false);
};

void GameplayLayer::didAccelerate(CCAcceleration* pAccelerationValue)
{
	if(pAccelerationValue)
	{
		b2Vec2 playertomovement = b2Vec2(pAccelerationValue->x * 1.5, pAccelerationValue->y * 1.5);
		b2Vec2 playeroldmovement = playerBody->GetLinearVelocity();
		playertomovement = playeroldmovement + playertomovement;

		if(playertomovement.x > 20.0f)
			playertomovement.x = 20.0f;

		playerBody->SetLinearVelocity(b2Vec2(playertomovement));
	}
};

void GameplayLayer::BeginContact(b2Contact* contact)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();
	if(fixtureB->GetBody()->GetType() == b2_dynamicBody)
	{
		//normalise player linear velocity to get direction
		b2Vec2 fixBVector = fixtureB->GetBody()->GetLinearVelocity();
		fixBVector.Normalize();

		if(fixtureB->GetBody()->GetTransform().p.y - 1.5f > fixtureA->GetBody()->GetTransform().p.y && fixBVector.y <= -0.8f)
		{
			score += 10 * scrollSpeed;
		}
	}
}