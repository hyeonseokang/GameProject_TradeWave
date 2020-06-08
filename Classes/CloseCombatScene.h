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

	vector<Unit*> enemyunit; //�� ���� ����
	vector<Unit*>::iterator enemyitr;
	vector<Unit*>::iterator eneitr;

	Unit* unit; //��ž

	Vec2 TouchPos;
	UIProgressBar * progressBar; // �ھ� ü�¹�

	Layer* ResumeLayer; //�Ͻ����� 

	MenuItemImage* pause;
	MenuItemImage* resume;

	int bug = 1;
	int k = 0;   //���� ��
	int unitnum = 0;
	bool check = false; // �� ��Ҵ���
	bool replace = false;
	bool hpbosslineup = false;
	bool hpbosslinedown = false;
	int abc = 1; //�� �Ʒ� �ľ�
	int attackHit = 1;

	int gtime = 0;
public:
	static Scene* createScene();

	virtual bool init();

	void CreateUnit(float dt); //���� ����

	void update(float dt);

	void Pause(); //�Ͻ�����
	void Resume(); //�Ͻ����� ����
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void timer(float dt);
				 //Ʃ�丮��
	Sprite *_tutorialtalk;
	void tutorial(float dt);
	int _tutorialLevel = 0;
	Label*_talklabel;
	Sprite*spot;
	Sprite*NPC;
	LayerColor*alayer;
	ClippingNode* cliper;
	//////////
	Label*cheatonoff;//ġƮȰ��ȭ����� Ȯ��
	void cheatfade();
	CREATE_FUNC(CloseCombatScene);
};

