#include "SimpleAudioEngine.h"
#include "CloseCombatScene.h"
#include "SailScene.h"


Scene* CloseCombatScene::createScene()
{

	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CloseCombatScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool CloseCombatScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	if(SingleTon::getinstance()->getBGM())
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/CloseBgm.mp3");
	auto BGLayer = Layer::create();
	this->addChild(BGLayer,-2);

	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(CloseCombatScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

	auto wave1 = Sprite::create("ShipMove/BG_See000.png");            
	wave1->setAnchorPoint(Point::ZERO);
	wave1->setPosition(Point::ZERO);
	BGLayer->addChild(wave1);

	auto wave2 = Sprite::create("ShipMove/BG_See000.png");         
	wave2->setAnchorPoint(Point::ZERO);
	wave2->setPosition(0, 720);
	BGLayer->addChild(wave2);

	auto move = MoveBy::create(5, Point(0, -720));
	auto replace = Place::create(Point::ZERO);
	auto seque = Sequence::create(move, replace, NULL);
	auto reforever = RepeatForever::create(seque);
	BGLayer->runAction(reforever);

	auto bg = Sprite::create("Combat/bg_0.png");
	bg->setPosition(Vec2(640, 360));
	this->addChild(bg, 0);

	ResumeLayer = LayerColor::create(ccc4(0, 0, 0, 80));
	ResumeLayer->setVisible(false);
	this->addChild(ResumeLayer, 3);


	resume = MenuItemImage::create(
		"Combat/Resume.png",
		"Combat/Resume.png", CC_CALLBACK_0(CloseCombatScene::Resume, this));

	resume->setVisible(false);

	pause = MenuItemImage::create(
		"Combat/Pause.png",
		"Combat/Pause.png", CC_CALLBACK_0(CloseCombatScene::Pause, this));

	auto menu = Menu::create(pause, resume, NULL);
	menu->setPosition(Vec2(1230, 670));
	menu->setAnchorPoint(Vec2(0.5f, 0.5f));
	this->addChild(menu, 2);


	this->setTouchEnabled(true); //터치 활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	unit = new Tower(this); // 코어 생성

	srand(time(NULL));
	if (UserDefault::getInstance()->getBoolForKey("TUTORIAL") == false)
	{
		k = RandomHelper::random_int(10, 10);
	}
	else
	k = RandomHelper::random_int(25, 35);        //생성 갯수 랜덤

	schedule(schedule_selector(CloseCombatScene::CreateUnit), 0.7f, k, 2.0f);
	scheduleUpdate();
	if (SingleTon::getinstance()->getTutorial() == 5)
		scheduleOnce(schedule_selector(CloseCombatScene::tutorial),4.5);

	cheatonoff = Label::create("치트활성", "fonts / JejuGothic - Regular.ttf", 30);
	cheatonoff->setPosition(Vec2(1100, 600));
	this->addChild(cheatonoff, 100);
	cheatonoff->setOpacity(0);

	return true;
}

void CloseCombatScene::CreateUnit(float dt)        //적 유닛 생성
{
	//	일반 25
	//	일반 강화 5
	//	보스 20
	//	탱커 20
	//	탱커 강화 5
	//	스피드 20
	//	스피드 강화 5

	// 1 일반유닛 / 2 보스 / 3 탱커 / 4 스피드 / 5 일반 강화 / 6 보스 / 7 탱커 강화 / 8 스피드 강화
	if (UserDefault::getInstance()->getBoolForKey("TUTORIAL") == false)
	{ 
		unitnum++;
		if (unitnum == 6)
		{
			unitnum++;
		}
		if (unitnum == 9)
		{
			unitnum = 1;
		}
	}
	else
	{
		unitnum = RandomHelper::random_int(1, 100);
		if (unitnum >= 1 && unitnum <= 25) { unitnum = 1; } //일반 25
		else if (unitnum > 25 && unitnum <= 30) { unitnum = 5; } //일반 강화 5
		else if (unitnum > 30 && unitnum <= 50) { unitnum = 2; } // 보스 20
		else if (unitnum > 50 && unitnum <= 70) { unitnum = 3; } // 탱커 20
		else if (unitnum > 70 && unitnum <= 75) { unitnum = 7; } // 탱커 강화 5
		else if (unitnum > 75 && unitnum <= 90) { unitnum = 4; } // 스피드 15
		else if (unitnum > 90 && unitnum <= 100) { unitnum = 8; } //스피드 강화 10
	}
	
	switch (unitnum)
	{
	case 1:
		if (abc == 1)                                  //abc는 위 아래로 나가는걸 결정해주는 변수     1이면 위쪽 2면 아래쪽 
		{
			int a;
			enemyang = new EnemyUnit(this, 1);            // 생성 , 위쪽
			enemyang->Create(1200, a = RandomHelper::random_int(361,720), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);                   //위 아래 판별 , 유닛 번호 1 : 기본해적 , 2 : 원거리 , 3 : 보스 
			enemyunit.push_back(enemyang);
			abc = 2;
		}
		else
		{
			int a;
			enemyang = new EnemyUnit(this, 1);          // 생성 , 아래쪽
			enemyang->Create(1200, a = RandomHelper::random_int(1,360), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);
			enemyunit.push_back(enemyang);
			abc = 1;
		}
		break;


	case 2:

		if (abc == 1)                                  //abc는 위 아래로 나가는걸 결정해주는 변수         
		{
			int a;
			enemyang = new BossEnemyUnit(this, 1);            // 생성 , 위쪽
			enemyang->Create(1100, a = RandomHelper::random_int(361,720), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);                   //위 아래 판별 , 유닛 번호 1 : 기본해적 , 2 : 원거리 , 3 : 보스 
			enemyunit.push_back(enemyang);
			abc = 2;
		}
		else
		{
			int a;
			enemyang = new BossEnemyUnit(this, 1);          // 생성 , 아래쪽
			enemyang->Create(1100, a = RandomHelper::random_int(1,360), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);
			enemyunit.push_back(enemyang);
			abc = 1;
		}
		break;

	case 3:
		
		if (abc == 1)                                  //abc는 위 아래로 나가는걸 결정해주는 변수         
		{
			int a;
			enemyang = new HPUnit(this, 1);            // 생성 , 위쪽
		
			enemyang->Create(1100, a = RandomHelper::random_int(361,720), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);                   //위 아래 판별 , 유닛 번호 1 : 기본해적 , 2 : 공격버프유닛 , 3 : 체력버프유닛 , 4 : 원거리 해적
			enemyunit.push_back(enemyang);
			abc = 2;
		}
		else
		{
			int a;
			enemyang = new HPUnit(this, 1);          // 생성 , 아래쪽
			enemyang->Create(1100, a = RandomHelper::random_int(1,360), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);
			enemyunit.push_back(enemyang);
			abc = 1;
		}
		break;
	case 4:

		if (abc == 1)                                  //abc는 위 아래로 나가는걸 결정해주는 변수         
		{
			int a;
			enemyang = new BombUnit(this, 1);            // 생성 , 위쪽
			enemyang->Create(1100, a = RandomHelper::random_int(361,720), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);                   //위 아래 판별 , 유닛 번호 1 : 기본해적 , 2 : 공격버프유닛 , 3 : 체력버프유닛 
			enemyunit.push_back(enemyang);
			abc = 2;
		}
		else
		{
			int a;
			enemyang = new BombUnit(this, 1);          // 생성 , 아래쪽
			enemyang->Create(1100, a = RandomHelper::random_int(1,360), this);
			enemyang->walkani();
			enemyang->fight(abc, unitnum, a);
			enemyunit.push_back(enemyang);
			abc = 1;
		}

		break;


	case 5:

		if (abc == 1)                                  //abc는 위 아래로 나가는걸 결정해주는 변수     1이면 위쪽 2면 아래쪽 
		{
			int a;
			enemyang = new EnemyUnit(this, 2);            // 생성 , 위쪽
			enemyang->Create(1100, a = RandomHelper::random_int(361,720), this);
			enemyang->walkani();
			enemyang->fight(abc, 1, a);                   //위 아래 판별 , 유닛 번호 1 : 기본해적 , 2 : 원거리 , 3 : 보스 
			enemyunit.push_back(enemyang);
			abc = 2;
		}
		else
		{
			int a;
			enemyang = new EnemyUnit(this, 2);          // 생성 , 아래쪽
			enemyang->Create(1100, a = RandomHelper::random_int(1,360), this);
			enemyang->walkani();
			enemyang->fight(abc, 1, a);
			enemyunit.push_back(enemyang);
			abc = 1;
		}
		break;
	case 7:

		if (abc == 1)                                  //abc는 위 아래로 나가는걸 결정해주는 변수         
		{
			int a;
			enemyang = new HPUnit(this, 2);            // 생성 , 위쪽
			enemyang->Create(1100, a = RandomHelper::random_int(361,720), this);
			enemyang->walkani();
			enemyang->fight(abc, 3, a);                   //위 아래 판별 , 유닛 번호 1 : 기본해적 , 2 : 공격버프유닛 , 3 : 체력버프유닛 , 4 : 원거리 해적
			enemyunit.push_back(enemyang);
			abc = 2;
		}
		else
		{
			int a;
			enemyang = new HPUnit(this, 2);          // 생성 , 아래쪽
			enemyang->Create(1100, a = RandomHelper::random_int(1,360), this);
			enemyang->walkani();
			enemyang->fight(abc, 3, a);
			enemyunit.push_back(enemyang);
			abc = 1;
		}
		break;

	case 8:

		if (abc == 1)                                  //abc는 위 아래로 나가는걸 결정해주는 변수         
		{
			int a;
			enemyang = new BombUnit(this, 2);            // 생성 , 위쪽
			enemyang->Create(1100, a = RandomHelper::random_int(361,720), this);
			enemyang->walkani();
			enemyang->fight(abc, 4, a);                   //위 아래 판별 , 유닛 번호 1 : 기본해적 , 2 : 공격버프유닛 , 3 : 체력버프유닛 
			enemyunit.push_back(enemyang);
			abc = 2;
		}
		else
		{
			int a;
			enemyang = new BombUnit(this, 2);          // 생성 , 아래쪽
			enemyang->Create(1100, a = RandomHelper::random_int(1,360), this);
			enemyang->walkani();
			enemyang->fight(abc, 4, a);
			enemyunit.push_back(enemyang);
			abc = 1;
		}

		break;
	}



	if (k == 0)
	{
		check = true;
	}
	k--;
};

bool CloseCombatScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	vector<Unit*> er;
	vector<Unit*>::iterator eritr;

	TouchPos = touch->getLocation();

	for (enemyitr = enemyunit.begin(); enemyitr != enemyunit.end(); enemyitr++)           //적 유닛 터치 시 피 깎이는거 + 체력 0 이하인 놈 체크
	{
		if ((*enemyitr)->sprite->boundingBox().containsPoint(TouchPos))
		{
			if(SingleTon::getinstance()->getEFFECT())
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/PriateHit.mp3");
			(*enemyitr)->hitani();							//맞는 애니메이션
			(*enemyitr)->Sethp((*enemyitr)->Gethp() - attackHit);		//적 몬스터 체력 감소

			if ((*enemyitr)->Gethp() <= 0)
			{
				er.push_back((*enemyitr));					// 0 이하일시 사망 예정자로 만듦
			}
			else
			{
				(*enemyitr)->hpbar(this);
			}
			break;
		}
	}

	for (eritr = er.begin(); eritr != er.end(); eritr++)                              //체력 0 이하인 놈을 죽인당
	{
		for (enemyitr = enemyunit.begin(); enemyitr != enemyunit.end(); enemyitr++)
		{
			if (*eritr == *enemyitr)
			{
				(*enemyitr)->dieani(); //죽는 애니메이션
				(*enemyitr)->Destroy();
				enemyunit.erase(enemyitr);
				break;
			}
		}
	}
	return true;
}
void CloseCombatScene::tutorial(float dt)
{
	alayer = LayerColor::create(Color4B(0, 0, 0, 200));
	spot = Sprite::create("MainMenu/Trading00.png");
	spot->setPosition(Point(290, 90));
	cliper = ClippingNode::create();
	cliper->setStencil(spot);
	cliper->setPosition(Point(0, 0));
	cliper->setAnchorPoint(Point(0.5, 0.5));
	cliper->setInverted(true);
	cliper->setAlphaThreshold(0.99);
	cliper->addChild(alayer);
	addChild(cliper, 100);
	alayer->setVisible(false);



	_tutorialtalk = Sprite::create("All/windows.png");
	_tutorialtalk->setPosition(Vec2(850-670, 490-450));
	_tutorialtalk->setAnchorPoint(Vec2(0, 0));
	this->addChild(_tutorialtalk, 200);
	NPC = Sprite::create("All/NPC1.png");
	NPC->setFlippedX(true);
	NPC->setPosition(Vec2(0, 0));
	NPC->setAnchorPoint(Vec2(0.0, 0.0));
	NPC->setScale(0.5f);
	this->addChild(NPC, 200);
	_talklabel = Label::create("해적들이 몰려옵니다!", "fonts/JejuGothic-Regular.ttf", 25, Size(400, 150), TextHAlignment::CENTER);
	_talklabel->setPosition(Vec2(860-670, 500-450));
	_talklabel->setColor(Color3B::BLACK);
	_talklabel->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(_talklabel, 200);
	Pause();
	auto listener12 = EventListenerTouchOneByOne::create();
	listener12->onTouchBegan = [=](Touch* touch, Event* event) {
		if (SingleTon::getinstance()->getTutorial() != 6)
		{
			switch (_tutorialLevel)
			{
			case 0:
				_talklabel->setString("해적을 터치하면 물리칠 수 있습니다\n해적들을 빠르게 물리칩시다!");
				_tutorialLevel++;
				break;
			case 1:
				Resume();
				SingleTon::getinstance()->setTutorial(6);
				attackHit = 100;
				_tutorialLevel++;
				_tutorialtalk->setVisible(false);
				NPC->setVisible(false);
				_talklabel->setVisible(false);
				break;
			case 5:
				UserDefault::getInstance()->setIntegerForKey("NOW", SingleTon::getinstance()->getArea());
				UserDefault::getInstance()->setBoolForKey("TUTORIAL", true);
				SingleTon::getinstance()->setBack(false);
				Director::getInstance()->replaceScene(TransitionFade::create(2, MenuScene::createScene()));
				break;
			}
		}
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener12, _tutorialtalk);

}

void CloseCombatScene::cheatfade()
{
	cheatonoff->setOpacity(255);
	auto cheatFade = FadeOut::create(1.0f);
	cheatonoff->runAction(cheatFade);
}
void CloseCombatScene::update(float dt)
{
	if (enemyunit.empty() && check == true)  //적들을 전부 잡으면 클리어창
	{
		check = false;
		SingleTon::getinstance()->setTime(SingleTon::getinstance()->getTime() + gtime);
		UserDefault::getInstance()->setIntegerForKey("NSHIPHP", unit->Gethp());
		if (SingleTon::getinstance()->getTutorial() == 6)
		{
			_tutorialtalk->setVisible(true);
			NPC->setVisible(true);
			_talklabel->setVisible(true);
			_talklabel->setString("잘하셨습니다! \n해적을 모두 물리치셨군요");
			_tutorialLevel = 5;
			SingleTon::getinstance()->setTutorial(7);
		}
		else
			Director::getInstance()->replaceScene(TransitionFade::create(2, SailScene::createScene()));
	}
	for (eneitr = enemyunit.begin(); eneitr != enemyunit.end(); eneitr++)    //버프 주는 유닛이 있는가 체크
		if ((*eneitr)->Gethpbuff())
		{
			if ((*eneitr)->Getabc() == 1)
				hpbosslineup = true;
			if ((*eneitr)->Getabc() == 2)
				hpbosslinedown = true;
		}

	/*if (((bosslineup && (*eritr)->Getabc() == 1) || (bosslinedown && (*eritr)->Getabc() == 2))
		&& !(*eritr)->Getboss())*/

	for (vector<Unit*>::iterator eritr = enemyunit.begin(); eritr != enemyunit.end(); eritr++)
	{
		if (hpbosslineup || hpbosslinedown)  //체력 버프
		{
			if ((hpbosslineup && (*eritr)->Getabc() == 1 || hpbosslinedown && (*eritr)->Getabc() == 2)
				&& !(*eritr)->Gethpboss())
			{
				(*eritr)->hpapply(1);
				(*eritr)->Sethpboss(true);
				(*eritr)->Sethp((*eritr)->Gethp() + 2);
				(*eritr)->Setkahp((*eritr)->Getkahp() + 2);
			}
		}
		else   //없으면 버프 삭제
		{
			if ((*eritr)->Gethpboss())
			{
				(*eritr)->hpapply(2);
				(*eritr)->Sethpboss(false);
				(*eritr)->Setkahp((*eritr)->Getkahp() - 2);
				if ((*eritr)->Gethp() > (*eritr)->Getkahp())
					(*eritr)->Sethp((*eritr)->Getkahp());
			}
		}
	}

	if (unit->Gethp() > 0)
		for (enemyitr = enemyunit.begin(); enemyitr != enemyunit.end(); enemyitr++)    //적들이 우리 코어를 공격
			if ((*enemyitr)->Getend() && (*enemyitr)->Gettimer())   //공격 딜레이
			{
				unit->Brr();
				//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/PriateAttack.mp3");
				(*enemyitr)->atkani();             //공격 애니메이션
				if (bug == 1)
				{
					unit->Sethp(unit->Gethp() - (*enemyitr)->Getatk());
					UserDefault::getInstance()->setIntegerForKey("NSHIPHP", unit->Gethp()); //가지고있는 배체력 
					unit->progressBar->SetPercentage((float)unit->Gethp() / unit->Getkahp());
				}
				(*enemyitr)->Settimer(false);						//공격 딜레이
				(*enemyitr)->ex();									//딜레이 초기화
			}




	hpbosslineup = false;
	hpbosslinedown = false;

	if (unit->Gethp() <= 0 && !replace)    //코어가 파괴되면 실패창
	{
		replace = true;
		UserDefault::getInstance()->setIntegerForKey("NSHIPHP", 0);
		SingleTon::getinstance()->setBack(false);
		Director::getInstance()->replaceScene(TransitionFade::create(2, MenuScene::createScene()));
	}
}

void CloseCombatScene::Pause() //일시정지
{
	resume->setVisible(true);
	pause->setVisible(false);
	ResumeLayer->setVisible(true);
	this->setTouchEnabled(false);
	Director::sharedDirector()->pause();
}

void CloseCombatScene::Resume()  //개임 재개
{
	resume->setVisible(false);
	pause->setVisible(true);
	ResumeLayer->setVisible(false);
	this->setTouchEnabled(true);
	Director::sharedDirector()->resume();
}
void CloseCombatScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	//이런 식으로 키 값에 따라 처리를 하면 된다

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_Q:
		if (bug == 1)
		{
			cheatonoff->setString("치트활성화");
			cheatfade();
			bug = 0;
		}
		else
		{
			cheatonoff->setString("치트비활성화");
			cheatfade();
			bug = 1;
		}
		break;
	case EventKeyboard::KeyCode::KEY_B:

		UserDefault::getInstance()->setIntegerForKey("NSHIPHP", unit->Gethp());
		Director::getInstance()->replaceScene(TransitionFade::create(2, SailScene::createScene()));
		break;
	}
}

void CloseCombatScene::timer(float dt)             //KGS
{
	gtime++;
}