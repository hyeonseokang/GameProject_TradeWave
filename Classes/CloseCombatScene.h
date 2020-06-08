#pragma once

#include "cocos2d.h"
#include "Unit.h"
#include "EnemyUnit.h"
#include "BossEnemyUnit.h"
#include "Tower.h"
#include "SailScene.h"
#include "HPUnit.h"
#include "BombUnit.h"
#include "Singleton.h"
#include "MenuScene.h"
#include <time.h>


USING_NS_CC;
using namespace std;

class CloseCombatScene : public Layer
{
private:
	Unit * ang;

	Unit * enemyang;

	vector<Unit*> enemyunit; //적 유닛 벡터
	vector<Unit*>::iterator enemyitr;
	vector<Unit*>::iterator eneitr;

	Unit* unit; //포탑

	Vec2 TouchPos;
	UIProgressBar * progressBar; // 코어 체력바

	Layer* ResumeLayer; //일시정지 

	MenuItemImage* pause;
	MenuItemImage* resume;

	int bug = 1;
	int k = 0;   //유닛 수
	int unitnum = 0;
	bool check = false; // 다 잡았는지
	bool replace = false;
	bool hpbosslineup = false;
	bool hpbosslinedown = false;
	int abc = 1; //위 아래 파악
	int attackHit = 1;

	int gtime = 0;
public:
	static Scene* createScene();

	virtual bool init();

	void CreateUnit(float dt); //유닛 생성

	void update(float dt);

	void Pause(); //일시정지
	void Resume(); //일시정지 해제
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void timer(float dt);
				 //튜토리얼
	Sprite *_tutorialtalk;
	void tutorial(float dt);
	int _tutorialLevel = 0;
	Label*_talklabel;
	Sprite*spot;
	Sprite*NPC;
	LayerColor*alayer;
	ClippingNode* cliper;
	//////////
	Label*cheatonoff;//치트활성화됬는지 확인
	void cheatfade();
	CREATE_FUNC(CloseCombatScene);
};

