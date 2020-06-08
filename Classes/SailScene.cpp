#include"SailScene.h"
#include "CloseCombatScene.h"
#include "MenuScene.h"
Scene* SailScene::createScene()
{
	Scene *scene = Scene::create();
	SailScene *layer = SailScene::create();
	scene->addChild(layer);	return scene;
}
bool SailScene::init()
{
	if (!LayerColor::initWithColor(Color4B::GRAY))
	{
		return false;
	}
	if(SingleTon::getinstance()->getBGM())
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/Shipyardbgm.mp3",true);
	//칭호
	SingleTon::getinstance()->setTitle(0);
	LoadEXP = UserDefault::getInstance()->getIntegerForKey("EXP");
	//
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	//래이어
	inter_layer = Layer::create();
	this->addChild(inter_layer, 10);
	back_layer = Layer::create();
	back_layer->setAnchorPoint(Vec2::ZERO);
	this->addChild(back_layer, 0);
	ship_layer = Layer::create();
	this->addChild(ship_layer, 5);
	p_ship_layer = Layer::create();
	this->addChild(p_ship_layer, 6);
	caution_layer = LayerColor::create(Color4B(255, 0, 0, 100));
	caution_layer->setVisible(false);
	inter_layer->addChild(caution_layer);
	//체력바
	hp = UserDefault::getInstance()->getIntegerForKey("NSHIPHP");
	f_hp = UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 10+90;
	auto hp_font = Sprite::create("ShipMove/Hp.png");
	hp_font->setPosition(Vec2(400, 100));
	hp_font->setScale(1.2f);
	inter_layer->addChild(hp_font);
	hp_back = Sprite::create("ShipMove/Hpbar00.png");
	hp_back->setPosition(Vec2(750, 100));
	inter_layer->addChild(hp_back);
	hp_bar = Sprite::create("ShipMove/Hpbar01.png");
	HpProgress = ProgressTimer::create(hp_bar);
	HpProgress->setAnchorPoint(Vec2::ZERO);
	HpProgress->setMidpoint(ccp(0, 0.5));
	HpProgress->setBarChangeRate(ccp(1, 0));
	HpProgress->setType(kCCProgressTimerTypeBar);
	HpProgress->setPercentage(/*now현재체력/최대체력*/(((float)hp / f_hp) * 100));
	hp_back->addChild(HpProgress);
	//해적선채력
	p_hp = 100;
	auto p_HpBar = Sprite::create("p_hp.png");
	p_HpProgress = ProgressTimer::create(p_HpBar);
	p_HpProgress->setVisible(false);
	p_HpProgress->setAnchorPoint(Vec2::ZERO);
	p_HpProgress->setMidpoint(ccp(0, 0.5));
	p_HpProgress->setBarChangeRate(ccp(1, 0));
	p_HpProgress->setType(kCCProgressTimerTypeBar);
	p_HpProgress->setPercentage(100);
	this->addChild(p_HpProgress, 7);
	//총알개수
	abc = Sprite::create("Cannon/can.png");
	Reload = ProgressTimer::create(abc);
	Reload->setPosition(1100, 100);
	Reload->setPercentage(100);
	Reload->setType(kCCProgressTimerTypeRadial);
	inter_layer->addChild(Reload);
	def = Label::createWithTTF("X 10", "fonts/JejuGothic-Regular.ttf", 40);
	def->setColor(Color3B::BLACK);
	def->setPosition(Vec2(130, 40));
	Reload->addChild(def);
	b_count = 10;
	//진행도
	progress = Sprite::create("ShipMove/progress00.png");
	progress->setPosition(Vec2(640, 650));
	inter_layer->addChild(progress, 5);
	Pro_ship = Sprite::create("ShipMove/progress_ship_00.png");
	Pro_ship->setAnchorPoint(Vec2(0, -0.5));
	progress->addChild(Pro_ship, 4);
	//배경생성
	distance = 10;
	Dock = Sprite::create("ShipMove/Arrive.png");
	Dock->setPosition(Vec2(640, 1440*distance-100));
	this->addChild(Dock, 3);
	SpriteFrameCache::getInstance()->addSpriteFrame(Sprite::create("ShipMove/BG_See000.png")->getDisplayFrame(), "back");
	for (int i = 0; i <= distance; i++)
	{
		Background[i] = Sprite::createWithSpriteFrameName("back");
		Background[i]->setAnchorPoint(Vec2::ZERO);
		Background[i]->setPosition(Vec2(-640, 1440 * i));
		back_layer->addChild(Background[i]);
	}
	auto place = Place::create(Vec2::ZERO);
	auto down = MoveBy::create(40, Vec2(0, -1440));
	back_layer->runAction(RepeatForever::create(Sequence::create(down, place, nullptr)));
	//장애물생성
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= (distance - 1)*2-1; j++)
		{
			obs[i][j] = new Obstacle(this,RandomHelper::random_int(1,10));
			obs[i][j]->setPos(Vec2(RandomHelper::random_int(i*20,(i+1)*20)*16-640
				, RandomHelper::random_int(j * 20, (j + 1) * 20)*36+720));
		}
	}
	//캐논
	can = new Cannon(inter_layer, this);
	can_damge = (20 + UserDefault::getInstance()->getIntegerForKey("SHIPATTACK")*1.6f);
	//해적선생성
	p_ship = new Priate_ship(p_ship_layer);
	p_ship->setVis(false);
	//화살표
	arrow = Sprite::create("arrow.png");
	arrow->setAnchorPoint(Vec2(0.5, 0));
	arrow->setVisible(false);
	this->addChild(arrow, 10);
	//배생성
	ship = new Ship(ship_layer);
	left = false;
	right = false;
	ship->setPos(Vec2(640, 0));
	//핸들생성
	handle = new Handle(inter_layer);
	handle->setPos(135, 135);
	//성공
	black = LayerColor::create();
	black->setVisible(false);
	black->setOpacity(125);
	black->setAnchorPoint(Vec2::ZERO);
	success = Sprite::create("ShipMove/Success.png");
	success->setPosition(Vec2(640, 360));
	black->addChild(success);
	for (int i = 0; i <= 3; i++)
	{
		end[i] = Label::createWithTTF("", "fonts/JejuGothic-Regular.ttf", 40, Size(500, 100), TextHAlignment::LEFT);
		end[i]->setPosition(Vec2(650, 420 - 80 * i));
		success->addChild(end[i]);
	}
	//경험치 바
	auto ex_back = Sprite::create("All/hpbar.png");
	ex_back->setPosition(Vec2(670, 140));
	black->addChild(ex_back);
	auto ex_bar = Sprite::create("ShipMove/Hpbar01.png");
	ExpProgress = ProgressTimer::create(ex_bar);
	ExpProgress->setAnchorPoint(Vec2::ZERO);
	ExpProgress->setMidpoint(ccp(0, 0.5));
	ExpProgress->setBarChangeRate(ccp(1, 0));
	ExpProgress->setType(kCCProgressTimerTypeBar);
	ex_back->addChild(ExpProgress);
	//
	inter_layer->addChild(black, 10);
	if (SingleTon::getinstance()->getTutorial() == 0 || SingleTon::getinstance()->getTutorial() == 7)
	{
		tutorialship = false;
		unbeatable = true;
		//	ship->lay->runAction(Sequence::create(Blink::create(1.5f, 5), CallFunc::create([&] { unbeatable = true; }), nullptr));
		this->setTouchEnabled(true);
		pirate_set();
		this->schedule(schedule_selector(SailScene::main_update));
	}
	else
	{
		tutorialship = true;
		unbeatable = true;
		this->setTouchEnabled(false);
		ship->setPos(Vec2(640, 360));
		tutorial();
	}
	//
	cheat_label = Label::createWithTTF("", "fonts/JejuGothic-Regular.ttf", 40);
	cheat_label->setVisible(false);
	cheat_label->setPosition(Vec2(1000, 600));
	inter_layer->addChild(cheat_label, 3);
	//카메라
	main_cam = Camera::create();
	this->addChild(main_cam);
	hud_cam = Camera::create();
	this->addChild(hud_cam);
	this->setCameraMask(static_cast<unsigned short>(CameraFlag::USER1));
	main_cam->setCameraFlag(CameraFlag::USER1);
	inter_layer->setCameraMask(static_cast<unsigned short>(CameraFlag::USER2));
	hud_cam->setCameraFlag(CameraFlag::USER2);
	//
	touched = false;
	can_active = false;
	can_delay = true;
	can_touched = false;
	save = true;
	p_enabled(false);
	cheat1 = false;
	cheat2 = false;
	finish = false;

	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(SailScene::onKeyPressed, this);
	//keylistener->onKeyReleased = CC_CALLBACK_2(SailScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
	this->schedule(schedule_selector(SailScene::timer), 1.0f);
	return true;
}
void SailScene::timer(float dt)
{
	time++;
}
void SailScene::main_update(float dt)
{
	if (touched&&handlebool == true)
	{
		//핸들
		H_angle = handle->getRotate();
		if (right) handle->setRotate(H_angle + 5);
		if (left)  handle->setRotate(H_angle - 5);
		//배 각도
		S_angle = ship->getRotate();
		if (right) ship->setRotate(S_angle + 0.5f);
		if (left)  ship->setRotate(S_angle - 0.5f);
	}
	//전투후
	if(save)
	BeBack = SingleTon::getinstance()->getBack();
	if (BeBack)
	{
		HpProgress->runAction(ProgressFromTo::create(1,
			(((float)hp / (f_hp) * 100)),
			(((float)UserDefault::getInstance()->getIntegerForKey("NSHIPHP") / (f_hp) * 100))));
		ship->setPos(Vec2(SingleTon::getinstance()->getPos()));
		SingleTon::getinstance()->setBack(false);
		time = SingleTon::getinstance()->getTime();
		main_cam->setPosition(SingleTon::getinstance()->getCamPos());
		b_count = SingleTon::getinstance()->getShell();
		def->setString(StringUtils::format("X %02d", b_count));
	}
	//충돌처리
	if (CircleCollision(ship->getPos(), 100, p_ship->getPos(), 100) && p_dead && save)
	{
		save = false;
		SingleTon::getinstance()->setPos(ship->getPos());
		SingleTon::getinstance()->setBack(true);
		SingleTon::getinstance()->setCamPos(main_cam->getPosition());
		SingleTon::getinstance()->setShell(b_count);
		SingleTon::getinstance()->setTime(time);
		UserDefault::getInstance()->setIntegerForKey("NSHIPHP", hp);
		Director::getInstance()->replaceScene(TransitionFade::create(1,CloseCombatScene::createScene(), Color3B::WHITE));
	}
	if (CircleVsRectCollision(ship->getPos(), Dock->getPosition(), 50, Dock->getBoundingBox()))
	{//항해성공
		p_ship->setVis(false);
		setExp();
		p_enabled(false);
		this->unscheduleAllSelectors();
		black->setVisible(true);

		int n_exp = UserDefault::getInstance()->getIntegerForKey("EXP");
		int max;
		if (n_exp < 300)max = 300;
		else if (n_exp < 1000) max = 1000;
		else if (n_exp < 3000)max = 3000;
		else if (n_exp < 8000)max = 8000;
		ExpProgress->runAction(ProgressFromTo::create(1, (float)LoadEXP / (max - LoadEXP) * 100, (float)n_exp / (max - n_exp) * 100));
		end[0]->setString(StringUtils::format("경과시간 : %d 초", time));
		end[1]->setString(StringUtils::format("받은피해 : %d", damaged));
		end[2]->setString(StringUtils::format("획득경험치 : %d", addExp));
		end[3]->setString(StringUtils::format("다음칭호까지 %d/%d", n_exp, max));
		UserDefault::getInstance()->setIntegerForKey("NOW", SingleTon::getinstance()->getArea());
		SingleTon::getinstance()->setBack(false);
		UserDefault::getInstance()->setBoolForKey("DISASTER", false);//항해성공후 재해 초기화
		scheduleOnce(schedule_selector(SailScene::BgmCh), 0);
		finish = true;
	}
	hp = UserDefault::getInstance()->getIntegerForKey("NSHIPHP");
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= (distance - 1) * 2 - 1; j++)
		{
			if (CircleCollision(ship->getPos(), 70, obs[i][j]->getPos(), 50) && unbeatable && !cheat1)
			{
				if (obs[i][j]->getNum() == 1)//바위
				{
					ship_damaged(10, 1.5f);
				}
				if (obs[i][j]->getNum() == 2)//잔해물
				{
					ship_damaged(15, 1.5f);
				}
				if (obs[i][j]->getNum() == 3)//소용돌이
				{
					this->runAction(Sequence::create(CallFunc::create([&] {ship->setSpeed(S_speed * 8 / 10); }), DelayTime::create(3)
						, CallFunc::create([&] {ship->setSpeed(S_speed * 10 / 8); }), nullptr));
					ship_damaged(5, 3.0f);
				}
				UserDefault::getInstance()->setIntegerForKey("NSHIPHP", hp);
				unbeatable = false;
				break;
			}
		}
	}
	//해적선과 대포 충돌
	if (CircleCollision(can->cannonsprite->getPosition(), 30, p_ship->getPos(), 70) && can_active)
	{
		if (SingleTon::getinstance()->getTutorial() == 2)
		{
			p_hp -= 100;
			p_HpProgress->runAction(Sequence::create(Show::create()
				, ProgressFromTo::create(0.5f, 100, 0), DelayTime::create(0.5f), Hide::create(), nullptr));
		}
		else
		{
			p_hp -= can_damge;
			p_HpProgress->runAction(Sequence::create(Show::create()
				, ProgressFromTo::create(0.01f, p_hp, p_hp - can_damge), DelayTime::create(0.5f), Hide::create(), nullptr));
		}
		p_ship->explosion_ani();
		can_active = false;
		can->cannonsprite->setVisible(false);
		can->miss_enabled = false;
	}
	//체력관련
	p_HpProgress->setPosition(p_ship->getPos() + Vec2(-50, 100));
	if (p_HpProgress->getPercentage()<=0&&p_dead)
	{
		if (tutorialship == false)
			pirate_set();

		p_HpProgress->setPercentage(100);
		p_enabled(false);
		if(SingleTon::getinstance()->getEFFECT())
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/Shipdead.mp3");
		if (SingleTon::getinstance()->getTutorial() == 2)
		{
			p_hp = 100;
			_talklabel->setString("잘하셨습니다!");
			CharacterEYE(true);
			_tutorialLevel = 10;
		}
		p_HpProgress->setVisible(false);
		can->miss_enabled = false;
	}
	if (HpProgress->getPercentage() <= 1)
	{
		Director::getInstance()->replaceScene(MenuScene::createScene());
		UserDefault::getInstance()->setIntegerForKey("NSHIPHP", 0);
	}
	//진행도
	Pro_ship->setPositionX(ship->getPosY()/distance*0.5f);
	//속도
	S_speed = ship->getSpeed();
	//해적선 각도정하기
	float Width_x = p_ship->getPosX() - ship->getPosX();
	float height_y = p_ship->getPosY() - ship->getPosY();
	float Angle = atan2f(height_y, Width_x) * 180 / M_PI;
	p_ship->setRotate(Angle*-1 - 90);
	//배이동
	p_ship->setPos(moving(p_ship->getPos(), p_ship->getRotate(), 3.8f));
	ship->setPos(moving(ship->getPos(), ship->getRotate(), S_speed));
	if (ship->getPosX() > 1920 || ship->getPosX() < -640)
		if(cannontutorial==false)ship->setRotate(ship->getRotate()*-1);
	if (ship->getPosY() < 0)
		if (cannontutorial == false)ship->setRotate(0);
	//화살표
	arrow->setPosition(ship->getPos());
	arrow->setRotation(angle);
	arrow->setScaleY(length);
	//대포끝!
	if (b_count <= 0)
	{
		can->Destroy();
	}
	//카메라
	if (ship->getPosX() < 1280 && ship->getPosX() > 0)main_cam->setPositionX(ship->getPosX());
	if (ship->getPosY() > 360 && ship->getPosY() < 1440*distance-360)main_cam->setPositionY(ship->getPosY());

	if (SingleTon::getinstance()->getTutorial() == 2)
	{
	//	SingleTon::getinstance()->setTutorial(3);
	}
}
Vec2 SailScene::moving(Vec2 pos, float angle, float speed)
{
	float X = sinf(CC_DEGREES_TO_RADIANS(angle));
	float Y = cosf(CC_DEGREES_TO_RADIANS(angle));
	float x1 = pos.x + X*speed;
	float y1 = pos.y + Y*speed;
	return Vec2(x1, y1);
}
void SailScene::p_enabled(bool enabled)
{
	p_dead = enabled;
	Reload->setVisible(enabled);
	def->setVisible(enabled);
	p_ship->setVis(enabled);
}
void SailScene::pirate_set()
{
	p_hp = 100;
	p_dead = true;

	if (tutorialship == false)
	{
		auto seq = Sequence::create(ToggleVisibility::create(), DelayTime::create(0.2f), nullptr);
		caution_layer->runAction(Sequence::create(DelayTime::create(RandomHelper::random_int(7, 10))
			, CallFunc::create([&] {
			p_enabled(true);
			p_ship->setPos(Vec2(main_cam->getPositionX() - 640 + 1280 * RandomHelper::random_int(0, 1), ship->getPosY())); })
			, Repeat::create(seq->clone(), 2), Repeat::create(seq->clone(), 4), nullptr));
	}
	else
	{
		auto seq = Sequence::create(ToggleVisibility::create(), DelayTime::create(0.2f), nullptr);
		caution_layer->runAction(Sequence::create(
			CallFunc::create([&] {
			p_enabled(true);
			p_ship->setPos(Vec2(main_cam->getPositionX() - 640 + 1280 * RandomHelper::random_int(0, 1), ship->getPosY())); })
			, Repeat::create(seq->clone(), 2)
				, CallFunc::create([=] {
				if (SingleTon::getinstance()->getTutorial() == 1) {
					NPC->setVisible(true);
					_talklabel->setVisible(true);
					_tutorialtalk->setVisible(true);
					_tutorialtalk->setPosition(690, 500);
					_talklabel->setPosition(_tutorialtalk->getPositionX() + 10, _tutorialtalk->getPositionY());
					NPC->setPosition(Vec2(_tutorialtalk->getPositionX() + 590, _tutorialtalk->getPositionY()));
					CharacterEYE(true);
					_talklabel->setString("이런, 해적선이 출현 했습니다");
					handlebool = false;
					setTouchEnabled(false);
					cannontutorial = true;
					_tutorialLevel = 6;
					SingleTon::getinstance()->setTutorial(2);
				}
				if (SingleTon::getinstance()->getTutorial() == 3) {
					NPC->setVisible(true);
					_talklabel->setVisible(true);
					_tutorialtalk->setVisible(true);
					SingleTon::getinstance()->setTutorial(4);
					_tutorialtalk->setPosition(690, 500);
					_talklabel->setPosition(_tutorialtalk->getPositionX() + 10, _tutorialtalk->getPositionY());
					NPC->setPosition(Vec2(_tutorialtalk->getPositionX() + 590, _tutorialtalk->getPositionY()));
					CharacterEYE(true);
					handlebool = false;
					_talklabel->setString("이런 또다시...");
					cannontutorial = true;
					_tutorialLevel = 13;
				}
			}), Repeat::create(seq->clone(), 4), nullptr));
	}

}
void SailScene::ship_damaged(int dmg, float dur)
{
	HpProgress->runAction(ProgressFromTo::create(1,
		(((float)hp / f_hp) * 100)
		, (((float)(hp - 10) / f_hp) * 100)));
	ship->lay->runAction(Sequence::create(Blink::create(dur, dur * 3), CallFunc::create([&] { unbeatable = true; }), nullptr));
	hp -= dmg;
	damaged += dmg;
}
bool SailScene::crash(Rect A, Rect B)
{
	return A.intersectsRect(B);
}
bool SailScene::CircleCollision(Vec2 point1, float fRad1, Vec2 point2, float fRad2)
{
	float fTemp = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));

	if (fTemp <= fRad1 + fRad2)
		return true;
	return false;
}
bool SailScene::CircleVsRectCollision(Vec2 target1, Vec2 target2, float radian1, Rect rect2)
{
	float left = (rect2.getMinX() - (radian1));
	float bottom = (rect2.getMinY() - (radian1));
	float top = (rect2.getMaxY() + (radian1));
	float right = (rect2.getMaxX() + (radian1));

	if ((target1.x >= left && target1.x <= right) &&
		(target1.y <= top && target1.y >= bottom))
		return true;
	return false;
}
//터치 이벤트 
bool SailScene::onTouchBegan(Touch * touch, Event * event)
{
	if (cannontutorial == false)
	{
		BeganTouchPos = touch->getLocation();
		if (handle->handle_png->getBoundingBox().containsPoint(touch->getLocation()))
		{
			ship->setSpeed(S_speed * 8 / 10);
			began_pos = touch->getLocation().x;
			touched = true;
		}

		if (b_count > 0 && !touched && p_dead && can_delay)
		{
			ship->setSpeed(S_speed * 8 / 10);
			can->touched(touch->getLocation(), ship->getPos());
			can_touched = true;
			arrow->setVisible(true);
			length = 1;
		}
	}
	if (finish)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		Director::getInstance()->replaceScene(TransitionFade::create(1, MenuScene::createScene()));
	}
	return true;
}
void SailScene::onTouchMoved(Touch * touch, Event * event)
{
	if (cannontutorial == false)
	{
		ship->setRotate(ship->getRotate());
		float pos = touch->getLocation().x;
		if (pos - began_pos > 0)
		{
			right = true;
			left = false;
		}
		if (pos - began_pos < 0)
		{
			right = false;
			left = true;
		}
		if (!touched && b_count > 0 && can_delay)
		{
			Vec2 location = touch->getLocation();
			angle = atan2f(BeganTouchPos.y - location.y, BeganTouchPos.x - location.x)*-180 / M_PI - 90;
			length = sqrt(pow(BeganTouchPos.x - location.x, 2) + pow(BeganTouchPos.y - location.y, 2))*0.01 + 1;
			can->moved(touch->getLocation());
		}
	}
}
void SailScene::onTouchEnded(Touch * touch, Event * event)
{
	if (cannontutorial == false)
	{
		EndedTouchPos = touch->getLocation();
		if (!touched&&b_count > 0 && p_dead && can_delay && can_touched)
		{
			if (SingleTon::getinstance()->getEFFECT())
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/CannonBang.mp3");
			ship->setSpeed(S_speed * 10 / 8);
			b_count--;
			def->setString(StringUtils::format("X %02d", b_count));
			can->ended(EndedTouchPos, ship->getPos());
			can_active = true;
			can_delay = false;
			Reload->runAction(Sequence::create(ProgressFromTo::create(2, 0, 100)
				, CallFunc::create([&] {can_delay = true; }), nullptr));
		}
		else if (touched)
		{
			ship->setSpeed(S_speed * 10 / 8);
		}
		left = false;
		right = false;
		touched = false;
		can_touched = false;
		angle = 0;
		arrow->setVisible(false);
		handle->setRotate(0);
	}
}

void SailScene::setExp()
{
	UserDefault::getInstance()->setIntegerForKey("EXP", LoadEXP + addExp);
	if (LoadEXP < 300 && UserDefault::getInstance()->getIntegerForKey("EXP") >= 300)
		SingleTon::getinstance()->setTitle(1);
	else if (LoadEXP < 1000 && UserDefault::getInstance()->getIntegerForKey("EXP") >= 1000)
		SingleTon::getinstance()->setTitle(2);
	else if (LoadEXP < 3000 && UserDefault::getInstance()->getIntegerForKey("EXP") >= 3000)
		SingleTon::getinstance()->setTitle(3);
	else if (LoadEXP < 8000 && UserDefault::getInstance()->getIntegerForKey("EXP") >= 8000)
		SingleTon::getinstance()->setTitle(4);
}

void SailScene::tutorial()
{
	cannontutorial = true;
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
	inter_layer->addChild(cliper, 100);
	alayer->setVisible(false);



	_tutorialtalk = Sprite::create("All/windows.png");
	_tutorialtalk->setContentSize(Size(400, 150));
	_tutorialtalk->setPosition(Vec2(690, 450));
	_tutorialtalk->setAnchorPoint(Vec2(0, 0));
	inter_layer->addChild(_tutorialtalk, 200);
	NPC = Sprite::create("All/NPC1.png");
	NPC->setPosition(Vec2(1280, 450));
	NPC->setScale(0.5f);
	NPC->setAnchorPoint(Vec2(1.0, 0.35));
	inter_layer->addChild(NPC, 200);
	_talklabel = Label::create("이제 항해에 대해 알아봅시다", "fonts/JejuGothic-Regular.ttf", 25, Size(400, 150), TextHAlignment::CENTER);
	_talklabel->setPosition(Vec2(690, 470));
	_talklabel->setColor(Color3B::BLACK);
	_talklabel->setAnchorPoint(Vec2(0, 0.5));
	inter_layer->addChild(_talklabel, 200);
	auto listener12 = EventListenerTouchOneByOne::create(); 
	auto RockIm = Sprite::create("ShipMove/Rock00.png");
	RockIm->setPosition(Vec2(300, 520));
	RockIm->setVisible(false);
	inter_layer->addChild(RockIm);
	listener12->onTouchBegan = [=](Touch* touch, Event* event) {
		switch (_tutorialLevel)
		{	
		case 0:
			alayer->setVisible(true);
			spot->setTexture("ShipMove/Operate.png");
			CharacterEYE(true);
			_talklabel->setString("키를 슬라이드 하여 \n방향을 전환할 수 있습니다");
			spot->setPosition(Vec2(140, 140));
			_tutorialLevel++;
			break;
		case 1:
			spot->setTexture("ShipMove/progress00.png");
			CharacterEYE(true);
			_talklabel->setString("위에 있는 이 아이콘으로 얼마나 왔는지 \n알수 있습니다");
			spot->setPosition(Vec2(640, 650));
			_tutorialLevel++;
			break;
		case 2:
			_talklabel->setString("장애물에 닿으면 배의 hp가 깎이며 \nhp가 0이 되면 항해를 실패합니다");
			CharacterEYE(true);
			spot->setTexture("ShipMove/Rock00.png");
			RockIm->setVisible(true);
			spot->setPosition(Vec2(300, 520));
			_tutorialLevel++;
			break;
		case 3:
			_talklabel->setString("최대한 장애물과 부딪히지 않게 \n조심하며 피해 가십시오");
			CharacterEYE(true);
			alayer->setVisible(false);
		//	pirate_set();
			_tutorialLevel++;
			break;
		case 4:
			CharacterEYE(true);
			RockIm->setVisible(false);
			NPC->setVisible(false);
			_talklabel->setVisible(false);
			_tutorialtalk->setVisible(false);
			_tutorialLevel++;
			handlebool = true;
			cannontutorial = false;
			this->setTouchEnabled(true);
			this->schedule(schedule_selector(SailScene::main_update));
			break;
		case 6:
			_talklabel->setString("빈공간을 슬라이드 하여 \n포를 쏠 수 있습니다");
			CharacterEYE(true);
			_tutorialLevel++;
			break;
		case 7:
			_talklabel->setString("포를 적중시켜 해적선을 물리치십시오");
			CharacterEYE(true);
			cannontutorial = false;
			setTouchEnabled(true);
			_tutorialLevel++;
			break;
		case 10:
			_talklabel->setString("이제 계속해서 항해를 진행 합시다.");
			CharacterEYE(true);
			b_count = 0;
			def->setString("X 0");
			_tutorialLevel++;
			break;
		case 11:
			handlebool = true;
			NPC->setVisible(false);
			_talklabel->setVisible(false);
			_tutorialtalk->setVisible(false);
			SingleTon::getinstance()->setTutorial(3);
			_tutorialLevel++;
			break;
		case 13:
			_talklabel->setString("포가 부족합니다 이젠 어쩔수 없군요");
			CharacterEYE(true);
			_tutorialLevel++;
			break;
		case 14:
			SingleTon::getinstance()->setTutorial(5);
			_tutorialLevel++;
			ship->setSpeed(0.0);
			break;
		}
		
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener12, _tutorialtalk);

}

void SailScene::CharacterEYE(bool _eyemod)
{
	auto delay = DelayTime::create(0.1);
	if (_eyemod == true)//눈감아야하는거
	{
		if (RandomHelper::random_int(0, 1) == 0)
			NPC->setTexture("All/NPC2.png");
		else
			NPC->setTexture("All/NPC4.png");

		NPC->runAction(Sequence::create(delay, CallFunc::create([=] {CharacterEYE(false);
		}), NULL));
	}
	else
	{
		if (RandomHelper::random_int(0, 1) == 0)
			NPC->setTexture("All/NPC1.png");
		else
			NPC->setTexture("All/NPC3.png");
	}
}

void SailScene::MainMenuGo(float dt)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}

void SailScene::BgmCh(float dt)
{
	if (SingleTon::getinstance()->getEFFECT())
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/Shipyardend.mp3");
}

void SailScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_Q&&tutorialship == true)
	{
		unbeatable = true;
		pirate_set();
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_R)
	{
		if (cheat1)
		{
			cheat1 = false;
			cheat_label->setString("무적 비활성");
			cheat_label->runAction(Sequence::create(Show::create(), DelayTime::create(2), Hide::create(), nullptr));
		}
		else if (!cheat1)
		{
			cheat1 = true;
			cheat_label->setString("무적 활성");
			cheat_label->runAction(Sequence::create(Show::create(), DelayTime::create(2), Hide::create(), nullptr));
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		if (cheat2)
		{
			cheat2 = false;
			ship->setSpeed(ship->getSpeed()*0.25f);
			cheat_label->setString("속도업 비활성");
			cheat_label->runAction(Sequence::create(Show::create(), DelayTime::create(2), Hide::create(), nullptr));
		}
		else if (!cheat2)
		{
			cheat2 = true;
			ship->setSpeed(ship->getSpeed() * 4);
			cheat_label->setString("속도업 활성");
			cheat_label->runAction(Sequence::create(Show::create(), DelayTime::create(2), Hide::create(), nullptr));
		}
	}
}