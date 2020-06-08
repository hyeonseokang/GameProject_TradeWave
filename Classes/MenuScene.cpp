#include"MenuScene.h"
#include"SailScene.h"
#include"Singleton.h"
#include"Credit.h"
#pragma execution_character_set("utf-8")

Scene* MenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = MenuScene::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
	//////////////////////////////
	if (!Layer::init())
	{
		return false;
	}
	this->setTouchEnabled(true); //터치 활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	this->setKeyboardEnabled(true);
	if(SingleTon::getinstance()->getBGM())
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/MainBgm.mp3", true);
	/*auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(MenuScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);*/
	insignia_Layer = Layer::create();
	insignia_Layer->setAnchorPoint(Vec2(0.5, 0.5));         ///////////////////////////////////////////////////////1
	insignia_Layer->setPosition(Vec2(-500, 4));             //UI모음창 레이어
	this->addChild(insignia_Layer,1);//
	Optionlayer = LayerColor::create(Color4B(0, 0, 0, 125));
	Optionlayer->setPosition(Vec2::ZERO);
	this->addChild(Optionlayer,2);
	Optionlayer->setVisible(false);
	auto Touch = MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
	Touch->setPosition(Vec2(640, 360));
	auto touchmenu = Menu::create(Touch, NULL);
	touchmenu->setPosition(Vec2::ZERO);
	Optionlayer->addChild(touchmenu);
	BgMainMenu(); // 뒷배경 
	BgMainButton(); //메인메뉴 버튼들
	StatusLabel(); //상태 표시 라벨
	OtherUI(); // 기타 ui
	EmbarkCreate(); //승선
	if (UserDefault::getInstance()->getBoolForKey("TUTORIAL") == true && SingleTon::getinstance()->getTutorial() != 7)
		News();
	this->schedule(schedule_selector(MenuScene::GoldCheck), 0.1, -1, 0);

	shipyard = new Shipyard(this);	

	trade = new Trade;
	trade->Tradeinit(this, Disaster());
	trade->Tradedelete();
	if(SingleTon::getinstance()->getTitle()!=0)
		TitleOn();//칭호
	if(UserDefault::getInstance()->getBoolForKey("TUTORIAL")==false||SingleTon::getinstance()->getTutorial()==7)
		tutorial();
	return true;
}

void MenuScene::menuCloseCallback(Ref* pSender)
{
	switch (((Node*)pSender)->getTag())
	{
	case 1://옵션
		OptionCreate();
		Optionlayer->setVisible(true);
		break;
	case 2: //교역소
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/trade_upgrade.mp3");
		trade->Tradecreate();
		trade->Tradelayer->setSwallowsTouches(true);
		break;
	case 3:
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/trade_upgrade.mp3");
		shipyard->init();
		break;
	case 4://승선
		EmbarkON();
		break;
	case 5:
		trade->inventory->InventoryLayer->setVisible(true);
		break;
	case 6:       //항해->메뉴화면
		EmbarkTF = false;


		Bounce();

		SelecMenu->setScale(1.0);
		SelecMenu->cleanup();

		EmbarkA1B->setPosition(Vec2(460, 500));
		EmbarkA2B->setPosition(Vec2(1120, 390));
		EmbarkA3B->setPosition(Vec2(560, 400));
		EmbarkB1B->setPosition(Vec2(310, 290));
		EmbarkB2B->setPosition(Vec2(430, 145));
		EmbarkC1B->setPosition(Vec2(700, 220));
		EmbarkC2B->setPosition(Vec2(925, 135));

		int SelectArea = UserDefault::getInstance()->getIntegerForKey("NOW");
		switch (SelectArea)
		{
		case 1:
			SelecMenu = EmbarkA1B;
			AreaNum = 1;
			break;
		case 2:
			SelecMenu = EmbarkA2B;
			AreaNum = 2;
			break;
		case 3:
			SelecMenu = EmbarkA3B;
			AreaNum = 3;
			break;
		case 4:
			SelecMenu = EmbarkB1B;
			AreaNum = 4;
			break;
		case 5:
			SelecMenu = EmbarkB2B;
			AreaNum = 5;
			break;
		case 6:
			SelecMenu = EmbarkC1B;
			AreaNum = 6;
			break;
		case 7:
			SelecMenu = EmbarkC2B;
			AreaNum = 7;
			break;
		}
		SelecMenu->setScale(2.0);
		SelecMenu->runAction(rep);

		News();
		hp_font->setVisible(false);
		hp_back->setVisible(false);
		hp_bar->setVisible(false);
		insignia_Layer->setVisible(true);
		EmbarkBack->setVisible(false);
		EmbarkMenu->setVisible(false);
		BelltenMenu->setVisible(true);
		TradeButton->setVisible(true);
		ShipyardButton->setVisible(true);
		InventoryButton->setVisible(true);
		BgArea->setPosition(Vec2(710, 657));
		BgGold->setVisible(true);
		GoldLabel->setVisible(true);
		DiamondLabel->setVisible(true);
		TitleLabel->setVisible(true);
		DaysLabel->setVisible(true);
		T_button->setVisible(true);
		break;
	}
	
	
	switch (((Node*)pSender)->getTag())
	{
	case 30:
		Disaterlayer->removeAllChildren();
		Disaterlayer->setVisible(false);
		break;
	case 31:
		Titlelayer->removeAllChildren();
		Titlelayer->setVisible(false);
	case 24:
		Optionlayer->removeAllChildren();
		Optionlayer->setVisible(false);
		break;

	}
}


void MenuScene::BgMainMenu()
{
	BgMap = Sprite::create("MainMenu/4.png"); // 메인 메뉴 뒷배경 지도맵 
	BgMap->setPosition(Vec2(640, 360));
	this->addChild(BgMap);
	BgMap2 = Sprite::create("MainMenu/5.png");
	BgMap2->setPosition(Vec2(640, 496));
	BgMap2->setScaleX(1.001f);
	BgMap2->setVisible(false);
	this->addChild(BgMap2, -2);
	BgMap3 = Sprite::create("MainMenu/2.png");
	BgMap3->setPosition(Vec2(640, 496));
	BgMap3->setScaleX(1.001f);
	this->addChild(BgMap3, -3);
	Pop = Sprite::create("MainMenu/pop.png");
	Pop->setAnchorPoint(Vec2(0, 1));
	Pop->setPosition(Vec2(0, 630));
	Pop->setScaleY(0);
	this->addChild(Pop);

	for (int i = 0; i <= 4; i++)
	{
		ab_label[i] = Label::createWithTTF("", "fonts/JejuGothic-Regular.ttf", 20, Size(500, 100)/*, TextHAlignment::LEFT*/);
		ab_label[i]->setPosition(Vec2(260, 280 - 65 * i));
		Pop->addChild(ab_label[i]);
	}

	int a, b, c, d; a = 0; b = 0; c = 0; d = 0;
	int _nowexp = UserDefault::getInstance()->getIntegerForKey("EXP");
	if (_nowexp >= 8000)d = 10;
	if (_nowexp >= 3000)c = 10;
	if (_nowexp >= 1000)b = 10;
	if (_nowexp >= 300)a = 10;
	ab_label[0]->setColor(Color3B::YELLOW);
	ab_label[0]->setString("             현재 적용중인 효과");
	ab_label[0]->setScale(1.3f);
	ab_label[1]->setString(StringUtils::format("해적 출현율 %d %% 감소", a));
	ab_label[2]->setString(StringUtils::format("시크릿교역품 출현율 %d %% 증가", b));
	ab_label[3]->setString(StringUtils::format("교역품 구입가 %d %% 감소", c));
	ab_label[4]->setString(StringUtils::format("항해거리 %d %% 감소", d));

	BgGold = Sprite::create("MainMenu/GoldBox.png");
	BgGold->setAnchorPoint(Vec2(0, 1));
	BgGold->setPosition(Vec2(0, 720));
	this->addChild(BgGold);

	BgArea = Sprite::create("MainMenu/NameBox.png");
	BgArea->setPosition(Vec2(710, 657));
	this->addChild(BgArea);

	NewsLabel = Label::create("ㅅ댜ㅓ", "fonts / JejuGothic - Regular.ttf", 30);    //KG , 위치바꿈
	NewsLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
	NewsLabel->setVisible(false);
	this->addChild(NewsLabel, -1);
}

void MenuScene::OptionCreate()
{
	Sprite*onoffBox=Sprite::create("MainMenu/onoffBox.png");
	Sprite*onoffBox2 = Sprite::create("MainMenu/onoffBox.png");
	BgOption = Sprite::create("MainMenu/BgOption.png");
	BgOption->setPosition(Vec2(640, 340));
	Optionlayer->addChild(BgOption, 1);
	auto BGMbutton=MenuItemSprite::create(onoffBox, onoffBox, CC_CALLBACK_1(MenuScene::BGMonoff, this));
	BGMbutton->setTag(1);
	BGMbutton->setPosition(Vec2(540, 350));
	auto effectBGMbutton = MenuItemSprite::create(onoffBox2, onoffBox2, CC_CALLBACK_1(MenuScene::BGMonoff, this));
	effectBGMbutton->setTag(2);
	effectBGMbutton->setPosition(Vec2(800, 350));
	Check1 = Sprite::create("MainMenu/CheckBox.png");
	Check1->setPosition(Vec2(540, 351));
	Check1->setScale(0.9);
	if (BGM == false)
		Check1->setVisible(false);
	Check2 = Sprite::create("MainMenu/CheckBox.png");
	if (effectBGM == false)
		Check2->setVisible(false);
	Check2->setPosition(Vec2(800, 351));
	Check2->setScale(0.9);
	Optionlayer->addChild(Check2, 3);
	Optionlayer->addChild(Check1, 3);
	closeoption = MenuItemImage::create("All/CloseButton00.png", "All/CloseButton01.png",
		CC_CALLBACK_1(
			MenuScene::menuCloseCallback, this));
	closeoption->setTag(24);
	closeoption->setPosition(Vec2(925, 575));
	MenuItemImage *CreditButton = MenuItemImage::create("All/Credit0.png", "All/Credit1.png", [](Ref*pSender) {Director::getInstance()->pushScene(Credit::createScene()); });
	CreditButton->setPosition(Vec2(550, 210));
	MenuItemImage *InitButton = MenuItemImage::create("All/bankruptcy0.png", "All/bankruptcy1.png", [](Ref*pSender) {});
	InitButton->setPosition(Vec2(750, 210));
	Close = Menu::create(BGMbutton, effectBGMbutton,closeoption, CreditButton, InitButton, NULL);
	Close->setPosition(Vec2::ZERO);
	Optionlayer->addChild(Close, 2);
}

void MenuScene::BGMonoff(Ref * pSender)
{
	switch (((Node*)pSender)->getTag())
	{
	case 1:
		if (BGM == true)
		{
			Check1->setVisible(false);
			BGM = false;
			SingleTon::getinstance()->setBGM(false);
			CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		}
		else
		{
			Check1->setVisible(true);
			BGM = true;
			SingleTon::getinstance()->setBGM(true);
			CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		}
		break;
	case 2:
		if (effectBGM == true)
		{
			Check2->setVisible(false);
			effectBGM = false;
			SingleTon::getinstance()->setEFFECT(false);
			CocosDenshion::SimpleAudioEngine::getInstance()->pauseAllEffects();
		}
		else
		{
			Check2->setVisible(true);
			effectBGM = true;
			SingleTon::getinstance()->setEFFECT(true);
			CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();
		}
		break;
	}
}

void MenuScene::BgMainButton()
{
	OptionButton = MenuItemImage::create("MainMenu/Option00.png", "MainMenu/Option01.png", CC_CALLBACK_1(
		MenuScene::menuCloseCallback, this));
	OptionButton->setTag(1);//옵션
	OptionButton->setPosition(Vec2(1200, 650));
	TradeButton = MenuItemImage::create("MainMenu/Trading00.png", "MainMenu/Trading01.png", CC_CALLBACK_1(
		MenuScene::menuCloseCallback, this));
	TradeButton->setTag(2);//교역소
	TradeButton->setPosition(Vec2(260, 75));
	ShipyardButton = MenuItemImage::create("MainMenu/Upgrade00.png", "MainMenu/Upgrade01.png", CC_CALLBACK_1(
		MenuScene::menuCloseCallback, this));
	ShipyardButton->setTag(3);// 조선소
	ShipyardButton->setPosition(Vec2(450, 73));
	EmbarkButton = MenuItemImage::create("MainMenu/Embark00.png", "MainMenu/Embark01.png", CC_CALLBACK_1(
		MenuScene::menuCloseCallback, this));
	EmbarkButton->setTag(4);// 승선
	EmbarkButton->setPosition(Vec2(1154, 72));
	InventoryButton = MenuItemImage::create("MainMenu/Inventory00.png", "MainMenu/Inventory01.png", CC_CALLBACK_1(
		MenuScene::menuCloseCallback, this));
	InventoryButton->setTag(5);// 인벤토리
	InventoryButton->setPosition(Vec2(70, 75));
	EmbarkBack = MenuItemImage::create("Embark/Back00.png", "Embark/Back01.png", CC_CALLBACK_1(
		MenuScene::menuCloseCallback, this));
	EmbarkBack->setTag(6);// 항해 뒤로가기버튼
	EmbarkBack->setPosition(Vec2(90, 90));
	EmbarkBack->setVisible(false);


	Sprite* insignia = Sprite::create("MainMenu/insignia.png");
	insignia->setPosition(Vec2(304, 75));
	insignia_Layer->addChild(insignia, 2);
	
	Belltten = MenuItemImage::create("MainMenu/insignia1.png", "MainMenu/insignia1.png", CC_CALLBACK_1(MenuScene::UI_push_pull, this));
	Belltten->setPosition(Vec2(558, 75));

	insignia_Menu = Menu::create(TradeButton, ShipyardButton, InventoryButton, NULL);
	insignia_Menu->setPosition(Vec2::ZERO);
	insignia_Layer->addChild(insignia_Menu, 3);

	BelltenMenu = Menu::create(Belltten, NULL);
	BelltenMenu->setPosition(Vec2::ZERO);
	insignia_Layer->addChild(BelltenMenu, 2);


	MainMenu = Menu::create(OptionButton, EmbarkButton , EmbarkBack ,NULL);
	MainMenu->setPosition(Vec2::ZERO);
	this->addChild(MainMenu);
	


}

void MenuScene::StatusLabel()
{
	AreaLabel = Label::createWithTTF("브리타니아", "fonts/JejuGothic-Regular.ttf", 40);
	AreaLabel->setPosition(Vec2(147, 60));
	switch (UserDefault::getInstance()->getIntegerForKey("NOW"))
	{
	case 1:
		AreaLabel->setString("콜로니아");
		break;
	case 2:
		AreaLabel->setString("빌른");
		break;
	case 3:
		AreaLabel->setString("메디올리움");
		break;
	case 4:
		AreaLabel->setString("브리타니아");
		break;
	case 5:
		AreaLabel->setString("알비온");
		break;
	case 6:
		AreaLabel->setString("시르");
		break;
	case 7:
		AreaLabel->setString("아레카테");
		break;
	}

	BgArea->addChild(AreaLabel);

	GoldLabel = Label::create("10, 000", "fonts/JejuGothic-Regular.ttf", 30);
	GoldLabel->setPosition(Vec2(243, 686));
	this->addChild(GoldLabel);

	DiamondLabel = Label::createWithTTF("0", "fonts/JejuGothic-Regular.ttf", 30);
	DiamondLabel->setPosition(Vec2(411, 686));
	this->addChild(DiamondLabel);

	DaysLabel = Label::create(StringUtils::format("항해 %d일차", UserDefault::getInstance()->getIntegerForKey("COUNT")), "fonts/JejuGothic-Regular.ttf", 21);
	DaysLabel->setPosition(Vec2(210, 592));
	this->addChild(DaysLabel);
	TitleLabel = Label::createWithTTF("초보상인", "fonts/JejuGothic-Regular.ttf", 30);
	TitleLabel->setPosition(Vec2(318, 638));
	this->addChild(TitleLabel);
	int _nowexp = UserDefault::getInstance()->getIntegerForKey("EXP");
	if (_nowexp >= 8000)
		TitleLabel->setString("무역왕");
	else if (_nowexp >= 3000)
		TitleLabel->setString("거상");
	else if (_nowexp >= 1000)
		TitleLabel->setString("대부호");
	else if (_nowexp >= 300)
		TitleLabel->setString("중견상인");
	
}

void MenuScene::GoldCheck(float delta)
{
	GoldLabel->setString(StringUtils::format("%d",
		UserDefault::getInstance()->getIntegerForKey("MONEY")));
	DiamondLabel->setString(StringUtils::format("%d",
		UserDefault::getInstance()->getIntegerForKey("CASH")));
}

void MenuScene::OtherUI()
{
	hp = UserDefault::getInstance()->getIntegerForKey("NSHIPHP");
	f_hp = 90+UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 10;
	hp_font = Sprite::create("ShipMove/progress_ship_00.png");
	hp_font->setPosition(Vec2(300, 60));
	hp_font->setScale(0.9f);
	this->addChild(hp_font);
	hp_back = Sprite::create("All/hpbar.png");
	hp_back->setPosition(Vec2(530, 60));
	hp_back->setScaleX(0.6f);
	hp_back->setScaleY(0.7f);
	this->addChild(hp_back);
	hp_bar = Sprite::create("ShipMove/Hpbar01.png");
	hp_bar->setScaleX(0.6f);
	hp_bar->setScaleY(0.7f);
	HpProgress = ProgressTimer::create(hp_bar);
	HpProgress->setAnchorPoint(Vec2::ZERO);
	HpProgress->setMidpoint(ccp(0, 0.5));
	HpProgress->setBarChangeRate(ccp(1, 0));
	HpProgress->setType(kCCProgressTimerTypeBar);

	HpProgress->setPercentage(/*now현재체력/최대체력*/(((float)hp / f_hp) * 100));
	hp_back->addChild(HpProgress);


	hp_font->setVisible(false);
	hp_back->setVisible(false);
	hp_bar->setVisible(false);

	opened = false;
	TitleSpr[0] = Sprite::create("MainMenu/designation.png");
	TitleSpr[1] = Sprite::create("MainMenu/designation1.png");
	T_button = MenuItemSprite::create(TitleSpr[0], TitleSpr[1], CC_CALLBACK_0(MenuScene::down, this));
	T_button->setPosition(Vec2(-560, 280));
	TitleMenu = Menu::create(T_button, nullptr);
	TitleMenu->setAnchorPoint(Vec2::ZERO);
	this->addChild(TitleMenu);
}

void MenuScene::EmbarkON()
{
	if (EmbarkTF == false)                 /////////////////////승선부분
	{
		hp = UserDefault::getInstance()->getIntegerForKey("NSHIPHP");
		f_hp = 90 + UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 10;
		HpProgress->setPercentage(/*now현재체력/최대체력*/(((float)hp / f_hp) * 100));
		hp_font->setVisible(true);
		hp_back->setVisible(true);
		hp_bar->setVisible(true);
		this->unschedule(schedule_selector(MenuScene::secondsnews30));
		EmbarkTF = true;
		insignia_Layer->setVisible(false);
		BelltenMenu->setVisible(false);
		BgGold->setVisible(false);
		opened = true;
		down();
		T_button->setVisible(false);
		GoldLabel->setVisible(false);
		DiamondLabel->setVisible(false);
		TitleLabel->setVisible(false);
		DaysLabel->setVisible(false);
		TradeButton->setVisible(false);
		ShipyardButton->setVisible(false);
		InventoryButton->setVisible(false);
		BgMap2->setVisible(false);                       //KGSH
		NewsLabel->setVisible(false);
		
		BgArea->setPosition(Vec2(640, 657));

		EmbarkBack->setVisible(true);
		EmbarkMenu->setVisible(true);
		if (UserDefault::getInstance()->getBoolForKey("TUTORIAL") == false)
		{
			_tutorialLevel++;
			alayer->setVisible(false);
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(579, 219));
			_talklabel->setString("현재 있는 곳은 브리타니아 입니다 ");
			EmbarkButton->setEnabled(false);
		}
	}

	else if (EmbarkTF == true)           //////////////////////항해 시작
	{
		if (UserDefault::getInstance()->getIntegerForKey("NOW") != AreaNum && UserDefault::getInstance()->getIntegerForKey("NSHIPHP") > 0)
		{
			switch (AreaNum)
			{
			case 1:
				SingleTon::getinstance()->setArea(1);
				break;
			case 2:
				SingleTon::getinstance()->setArea(2);
				break;
			case 3:
				SingleTon::getinstance()->setArea(3);
				break;
			case 4:
				SingleTon::getinstance()->setArea(4);
				break;
			case 5:
				SingleTon::getinstance()->setArea(5);
				break;
			case 6:
				SingleTon::getinstance()->setArea(6);
				break;
			case 7:
				SingleTon::getinstance()->setArea(7);
				break;
			}
			UserDefault::getInstance()->setIntegerForKey("COUNT", UserDefault::getInstance()->getIntegerForKey("COUNT") + 1);
			trade->SaveloadPirce();//전시세저장
			Director::getInstance()->replaceScene(TransitionFade::create(1, SailScene::createScene(),Color3B(255,255,255)));
		}
	}
}

void MenuScene::EmbarkCreate()
{
	Bounce();


	EmbarkA1 = Sprite::create("All/B_Anchor00.png");
	EmbarkA2 = Sprite::create("All/B_Anchor00.png");
	EmbarkA3 = Sprite::create("All/B_Anchor00.png");
	EmbarkB1 = Sprite::create("All/B_Anchor00.png");
	EmbarkB2 = Sprite::create("All/B_Anchor00.png");
	EmbarkC1 = Sprite::create("All/B_Anchor00.png");
	EmbarkC2 = Sprite::create("All/B_Anchor00.png");
	SelectEmbark = EmbarkC1;



	EmbarkA1B=MenuItemSprite::create(EmbarkA1, EmbarkA1, CC_CALLBACK_1(MenuScene::EmabrkMenuR, this));
	EmbarkA1B->setPosition(Vec2(460, 500));
	EmbarkA1B->setAnchorPoint(Vec2(0.5, 0));
	EmbarkA1B->setTag(1);
	EmbarkA2B = MenuItemSprite::create(EmbarkA2, EmbarkA2, CC_CALLBACK_1(MenuScene::EmabrkMenuR, this));
	EmbarkA2B->setPosition(Vec2(1120, 390));
	EmbarkA2B->setAnchorPoint(Vec2(0.5, 0));
	EmbarkA2B->setTag(2);
	EmbarkA3B = MenuItemSprite::create(EmbarkA3, EmbarkA3, CC_CALLBACK_1(MenuScene::EmabrkMenuR, this));
	EmbarkA3B->setPosition(Vec2(560, 400));
	EmbarkA3B->setAnchorPoint(Vec2(0.5, 0));
	EmbarkA3B->setTag(3);
	EmbarkB1B = MenuItemSprite::create(EmbarkB1, EmbarkB1, CC_CALLBACK_1(MenuScene::EmabrkMenuR, this));
	EmbarkB1B->setPosition(Vec2(310, 290));
	EmbarkB1B->setAnchorPoint(Vec2(0.5, 0));
	EmbarkB1B->setTag(4);
	EmbarkB2B = MenuItemSprite::create(EmbarkB2, EmbarkB2, CC_CALLBACK_1(MenuScene::EmabrkMenuR, this));
	EmbarkB2B->setPosition(Vec2(430, 145));
	EmbarkB2B->setAnchorPoint(Vec2(0.5, 0));
	EmbarkB2B->setTag(5);
	EmbarkC1B = MenuItemSprite::create(EmbarkC1, EmbarkC1, CC_CALLBACK_1(MenuScene::EmabrkMenuR, this));
	EmbarkC1B->setPosition(Vec2(700, 220));
	EmbarkC1B->setAnchorPoint(Vec2(0.5, 0));
	EmbarkC1B->setTag(6);
	EmbarkC2B = MenuItemSprite::create(EmbarkC2, EmbarkC2, CC_CALLBACK_1(MenuScene::EmabrkMenuR, this));
	EmbarkC2B->setPosition(Vec2(925, 135));
	EmbarkC2B->setAnchorPoint(Vec2(0.5, 0));
	EmbarkC2B->setTag(7);
	EmbarkMenu = Menu::create(EmbarkA1B, EmbarkA2B, EmbarkA3B, EmbarkB1B, EmbarkB2B, EmbarkC1B, EmbarkC2B, NULL);
	EmbarkMenu->setPosition(Vec2::ZERO);
	int SelectArea = UserDefault::getInstance()->getIntegerForKey("NOW");
	switch (SelectArea)
	{
	case 1:
		SelecMenu = EmbarkA1B;
		AreaNum = 1;
		break;
	case 2:
		SelecMenu = EmbarkA2B;
		AreaNum = 2;
		break;
	case 3:
		SelecMenu = EmbarkA3B;
		AreaNum = 3;
		break;
	case 4:
		SelecMenu = EmbarkB1B;
		AreaNum = 4;
		break;
	case 5:
		SelecMenu = EmbarkB2B;
		AreaNum = 5;
		break;
	case 6:
		SelecMenu = EmbarkC1B;
		AreaNum = 6;
		break;
	case 7:
		SelecMenu = EmbarkC2B;
		AreaNum = 7;
		break;
	}
	SelecMenu->setScale(2.0);
	SelecMenu->runAction(rep);
	this->addChild(EmbarkMenu);
	EmbarkMenu->setVisible(false);
}

void MenuScene::EmabrkMenuR(Ref * pSender)
{
	Bounce();
	SelecMenu->cleanup();
	EmbarkA1B->setPosition(Vec2(460, 500));
	EmbarkA2B->setPosition(Vec2(1120, 390));
	EmbarkA3B->setPosition(Vec2(560, 400));
	EmbarkB1B->setPosition(Vec2(310, 290));
	EmbarkB2B->setPosition(Vec2(430, 145));
	EmbarkC1B->setPosition(Vec2(700, 220));
	EmbarkC2B->setPosition(Vec2(925, 135));
	SelecMenu->setScale(1.0);
	switch (((Node*)pSender)->getTag())
	{
	case 1:
		SelecMenu = EmbarkA1B;
		AreaNum = 1;
		break;
	case 2:
		SelecMenu = EmbarkA2B;
		AreaNum = 2;
		break;
	case 3:
		SelecMenu = EmbarkA3B;
		AreaNum = 3;
		break;
	case 4:
		SelecMenu = EmbarkB1B;
		AreaNum = 4;
		break;
	case 5:
		SelecMenu = EmbarkB2B;
		AreaNum = 5;
		if (UserDefault::getInstance()->getBoolForKey("TUTORIAL") == false)
		{
			EmbarkB2B->setEnabled(false);
			_tutorialLevel++;
			CharacterEYE(true);
			alayer->setVisible(true);
			EmbarkButton->setEnabled(true);
			spot->setTexture("MainMenu/Embark00.png");
			spot->setPosition(Vec2(1154, 66));
			_talklabel->setPosition(Vec2(579, 212));
			spot->setAnchorPoint(Vec2(0.5, 0.5));
			_talklabel->setString("항해 버튼을 누르시면 항해가 시작됩니다");
			SingleTon::getinstance()->setTutorial(1);
		}
		break;
	case 6:
		SelecMenu = EmbarkC1B;
		AreaNum = 6;
		break;
	case 7:
		SelecMenu = EmbarkC2B;
		AreaNum = 7;
		break;
	}
	SelecMenu->setScale(2.0);
	SelecMenu->runAction(rep);
}

void MenuScene::UI_push_pull(Ref* sender)              //UI버튼 펼치고 넣는 함수
{
	//insignia_Layer->setPosition(Vec2(-75, 0));

	if (Push == false)
	{
		auto moveto = MoveTo::create(0.1f, Vec2(0, 4));
		insignia_Layer->runAction(moveto);
		Push = true;
		if (UserDefault::getInstance()->getBoolForKey("TUTORIAL") == false)
		{
			_talklabel->setString("이 버튼은 ‘교역소’로 \n교역품을 사고 파는 곳입니다");
			CharacterEYE(true);
			Belltten->setEnabled(false);//리본
			_talklabel->setPosition(Vec2(580, 220));
			spot->setTexture("All/Circle.png");
			spot->setPosition(Vec2(260, 75));
			_tutorialLevel++;
		}
	}

	else if (Push == true)
	{
		
		auto moveto2 = MoveTo::create(0.1f, Vec2(-505, 4));

		insignia_Layer->runAction(moveto2);
		Push = false;
	}

}

bool MenuScene::onTouchBegan(Touch * touch, Event * unused_event)
{
	log("%f    %f", touch->getLocation().x, touch->getLocation().y);
	return true;
}
int MenuScene::Disaster()
{
	if (SingleTon::getinstance()->getTutorial()!=7&&UserDefault::getInstance()->getBoolForKey("TUTORIAL") == true && UserDefault::getInstance()->getBoolForKey("DISASTER") == false)
	{
		if (RandomHelper::random_int(0, 0) == 0)
		{
			int num = RandomHelper::random_int(1, 4);
			Disaterlayer = LayerColor::create(Color4B(0, 0, 0, 125));
			Disaterlayer->setPosition(Vec2::ZERO);
			this->addChild(Disaterlayer);
			auto BgDisaster = Sprite::create("Trade/BgTrade1.png");
			BgDisaster->setPosition(Vec2(640, 360));
			Disaterlayer->addChild(BgDisaster);
			auto DisClose = MenuItemImage::create("All/CloseButton00.png", "All/CloseButton01.png", CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
			DisClose->setPosition(Vec2(990, 640));
			DisClose->setTag(30);
			auto DisMenu = Menu::create(DisClose, NULL);
			DisMenu->setPosition(Vec2::ZERO);
			Disaterlayer->addChild(DisMenu);
			auto Photo = Sprite::create("Trade/Buy/ItemImage01.png");
			Photo->setPosition(Vec2(640, 460));
			Photo->setScale(1.5);
			Disaterlayer->addChild(Photo);
			auto DisOn = Label::create("자연현상이 발생했습니다!", "fonts/JejuGothic-Regular.ttf", 50);
			DisOn->setColor(Color3B(255, 255, 255));
			DisOn->setPosition(Vec2(640, 575));
			Disaterlayer->addChild(DisOn);
			auto DisMaterial = Sprite::create("CloseNormal.png");
			DisMaterial->setPosition(Vec2(640, 460));
			Disaterlayer->addChild(DisMaterial);
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					DisLabel[j + i * 3] = Label::create("농산물 : 10%", "fonts/JejuGothic-Regular.ttf", 45, Size(300, 80), TextHAlignment::LEFT);
					DisLabel[j + i * 3]->setPosition(Vec2(795 - i * 310, 300 - j * 80));
					Disaterlayer->addChild(DisLabel[j + i * 3]);
				}
			}

			UserDefault::getInstance()->setBoolForKey("DISASTER", true);
			switch (num)
			{
			case 1:
				UserDefault::getInstance()->setIntegerForKey("DISASTERNUM", 1);
				DisLabel[0]->setString("옷감 : +30%");
				DisLabel[1]->setString("해산물 : +20%");
				DisLabel[2]->setString("");
				DisLabel[3]->setString("보석 : +10%");
				DisLabel[4]->setString("농산물 : +40%");
				DisLabel[5]->setString("광물 : +10%");
				DisOn->setString("태풍이 발생하였습니다.");
				DisMaterial->setTexture("All/typhoon.png");
				break;
			case 2:
				UserDefault::getInstance()->setIntegerForKey("DISASTERNUM", 2);
				DisLabel[0]->setString("옷감 : +10%");
				DisLabel[1]->setString("해산물 : +20%");
				DisLabel[2]->setString("");
				DisLabel[3]->setString("보석 : -20%");
				DisLabel[4]->setString("농산물 : +50%");
				DisLabel[5]->setString("광물 : +10%");
				DisOn->setString("가뭄이 발생하였습니다.");
				DisMaterial->setTexture("All/drought.png");
				break;
			case 3:
				UserDefault::getInstance()->setIntegerForKey("DISASTERNUM", 3);
				DisLabel[0]->setString("옷감 : +20%");
				DisLabel[1]->setString("해산물 : +20%");
				DisLabel[2]->setString("");
				DisLabel[3]->setString("보석 : -30%");
				DisLabel[4]->setString("농산물 : +30%");
				DisLabel[5]->setString("광물 : +10%");
				DisOn->setString("역병이 발생하였습니다.");
				DisMaterial->setTexture("All/epidemic.png");
				break;
			case 4:
				UserDefault::getInstance()->setIntegerForKey("DISASTERNUM", 4);
				DisLabel[0]->setString("옷감 : +20%");
				DisLabel[1]->setString("해산물 : +20%");
				DisLabel[2]->setString("");
				DisLabel[3]->setString("보석 : +20%");
				DisLabel[4]->setString("농산물 : +20%");
				DisLabel[5]->setString("광물 : +20%");
				DisOn->setString("홍수가 발생하였습니다.");
				DisMaterial->setTexture("All/deluge.png");
				break;
			}
			return num;
		}
	}
	else if (UserDefault::getInstance()->getBoolForKey("DISASTER") == true)
		return UserDefault::getInstance()->getIntegerForKey("DISASTERNUM");
	return 0;
}

void MenuScene::TitleOn()
{
	Titlelayer = LayerColor::create(Color4B(0, 0, 0, 125));
	Titlelayer->setPosition(Vec2::ZERO);
	this->addChild(Titlelayer);
	auto BgTitle = Sprite::create("Trade/BgTrade1.png");
	BgTitle->setPosition(Vec2(640, 360));
	Titlelayer->addChild(BgTitle);
	auto Photo1 = Sprite::create("All/ItemImage.png");
	Photo1->setPosition(Vec2(640, 440));
	Titlelayer->addChild(Photo1);
	auto Photo = Sprite::create("All/medal.png");
	Photo->setPosition(Vec2(640, 440));
	Titlelayer->addChild(Photo);
	auto TitleOn = Label::create("새로운 칭호 획득!", "fonts/JejuGothic-Regular.ttf", 50);
	TitleOn->setColor(Color3B(255, 255, 255));
	TitleOn->setPosition(Vec2(640, 575));
	Titlelayer->addChild(TitleOn);
	auto TitleLabel = Label::create("짜라짜라라라짜짜", "fonts/JejuGothic-Regular.ttf",40,Size(520,500),TextHAlignment::CENTER);
	TitleLabel->setColor(Color3B(255, 255, 255));
	TitleLabel->setPosition(Vec2(640, 80));
	Titlelayer->addChild(TitleLabel);
	auto TitleClose = MenuItemImage::create("All/CloseButton00.png", "All/CloseButton01.png", CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
	TitleClose->setPosition(Vec2(990, 640));
	TitleClose->setTag(31);
	auto TitleMenu = Menu::create(TitleClose, NULL);
	TitleMenu->setPosition(Vec2::ZERO);
	Titlelayer->addChild(TitleMenu);
	switch (SingleTon::getinstance()->getTitle())
	{
	case 1:
		TitleLabel->setString("<중견  상인>\n\n해적 출현율이 10% 감소한다.");
		break;
	case 2:
		TitleLabel->setString("<대부호>\n\n시크릿 교역품 출현율 10% 증가 효과를 받는다.");
		break;
	case 3:
		TitleLabel->setString("<거상>\n\n지속적인 거래로 신뢰가 쌓여 교역품 구입가 10% 감소효과를 받는다.");
		break;
	case 4:
		TitleLabel->setString("<무역왕>\n\n빠른 루트를 발견하여 항해 거리가 10% 감소효과를 받는다.");
		break;
	}
}
void MenuScene::tutorial()
{
	EmbarkA1B->setEnabled(false);
	EmbarkA2B->setEnabled(false);
	EmbarkA3B->setEnabled(false);
	EmbarkB1B->setEnabled(false);
	EmbarkB2B->setEnabled(false);
	EmbarkC1B->setEnabled(false);
	EmbarkC2B->setEnabled(false);

	Belltten->setEnabled(false);//리본
	EmbarkBack->setEnabled(false);//항해뒤로가기
	OptionButton->setEnabled(false); // 옵션 버튼
	TradeButton->setEnabled(false); // 교역소 버튼 
	ShipyardButton->setEnabled(false); // 배 업그레이드 버튼 조선소
	EmbarkButton->setEnabled(false); // 항해 버튼
	InventoryButton->setEnabled(false); // 인벤토리 버튼 
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
	_tutorialtalk->setPosition(Vec2(600, 200));
	_tutorialtalk->setAnchorPoint(Vec2(0, 0));
	this->addChild(_tutorialtalk,200);
	NPC = Sprite::create("ALL/NPC1.png");
	NPC->setScale(0.7);
	NPC->setPosition(Vec2(1150, 360));
	this->addChild(NPC,200);
	_talklabel = Label::create("반갑습니다", "fonts/JejuGothic-Regular.ttf", 23 ,Size(450,150),TextHAlignment::CENTER);
	_talklabel->setPosition(Vec2(580, 220));
	_talklabel->setColor(Color3B::BLACK);
	_talklabel->setPosition(Vec2(580, 215));
	_talklabel->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(_talklabel,200);
	auto listener12 = EventListenerTouchOneByOne::create();
	if (SingleTon::getinstance()->getTutorial() == 7)
	{
		_talklabel->setString("항해를 무사히 마쳤군요.");
		_tutorialLevel = 20;
	}
	listener12->onTouchBegan = [=](Touch* touch, Event* event) {
		switch (_tutorialLevel)
		{
		case 0:
			_talklabel->setString("저는 당신에게 도움을 주기 위해 \n무역 협회에서 파견된 레이라고 합니다");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(578, 220));
			_tutorialLevel++;
			break;
		case 1:
			_talklabel->setString("당신은 무역왕을 목표로 정하셨군요..?");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(579, 215));
			_tutorialLevel++;
			break;
		case 2:
			_talklabel->setString("그러기 위해서는 각 나라의 교역품을 \n싸게 구입하고 비싸게 판매하여 이익을\n창출해야 합니다");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(578, 220));
			_tutorialLevel++;
			break;
		case 3:
			_talklabel->setString("최근 들어 해적이 매우 많이 출현하고 \n있으니 반드시 이를 유의하셔야 합니다");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(578, 220));
			_tutorialLevel++;
			break;
		case 4:
			_talklabel->setString("그런데 당신.. 해적이 범람한 시대에 \n무역상이 되시다니\n참 대단한 사람이군요(비아냥)");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(580, 220));
			_tutorialLevel++;
			break;
		case 5:
			_talklabel->setString("자 이제 무역을 위한 준비를 해봅시다");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(579, 210));
			_tutorialLevel++;
			break;
		case 6:
			_talklabel->setString("이 리본을 클릭해 보십시오");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(580, 210));
			alayer->setVisible(true);
			Belltten->setEnabled(true);
			spot->setTexture("MainMenu/insignia1.png");
			spot->setPosition(Vec2(58, 75));
			_tutorialLevel++;
			break;
		case 7:
			break;
		case 8:
			_talklabel->setString("이 버튼은 ‘조선소’로 배를 업그레이드 \n하고 수리하는 곳입니다");
			CharacterEYE(true);
			spot->setPosition(Vec2(450,73));
			_tutorialLevel++;
			break;
		case 9:
			_talklabel->setString("이 버튼은 ‘인벤토리’로 지니고 있는 교\n역품을 확인할 수 있는 곳입니다");
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(579, 220));
			spot->setPosition(Vec2(70, 75));
			_tutorialLevel++;
			break;
		case 10:
			alayer->setVisible(false);
			_talklabel->setPosition(Vec2(579, 215));
			_talklabel->setString("이제 배에 승선을 해봅시다.");
			CharacterEYE(true);
			_tutorialLevel++;
			break;
		case 11:
			alayer->setVisible(true);
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(579, 219));
			_talklabel->setString("이 버튼은 승선창으로 가는 버튼입니다\n 버튼을 누르세요");
			EmbarkButton->setEnabled(true);
			spot->setTexture("MainMenu/Embark00.png");
			spot->setPosition(Vec2(1154, 66));
			_tutorialLevel++;
			break;
		case 12:
			break;
		case 13:
			CharacterEYE(true);
			_talklabel->setPosition(Vec2(578, 215));
			_talklabel->setString("일단 가까운 알비온으로 가봅시다\n 알비온 항구를 선택하세요");
			alayer->setVisible(true);
			spot->setAnchorPoint(Vec2(0.5, 0));
			spot->setPosition(Vec2(430, 145));
			spot->setTexture("All/B_Anchor00.png");
			EmbarkB2B->setEnabled(true);
			_tutorialLevel++;
			break;
		case 14:
			break;
		case 20:
			CharacterEYE(true);
			_talklabel->setString("이곳은 알비온 입니다");
			alayer->setVisible(false);
			_tutorialLevel++;
			break;
		case 21:
			CharacterEYE(true);
			_talklabel->setString("첫 항해 치고는 아주 잘하셨습니다");
			_tutorialLevel++;
			break;
		case 22:
			CharacterEYE(true);
			_talklabel->setString("당신은 이제 어엿한 무역상 입니다");
			_tutorialLevel++;
			break;
		case 23:
			CharacterEYE(true);
			_talklabel->setString("당신, 무역에 소질이 있으신 것 같군요");
			_tutorialLevel++;
			break;
		case 24:
			CharacterEYE(true);
			_talklabel->setString("행운을 빕니다!");
			_tutorialLevel++;
			break;
		case 25:
			SingleTon::getinstance()->setTutorial(0);
			_talklabel->setVisible(false);
			_tutorialtalk->setVisible(false);
			NPC->setVisible(false);
			EmbarkA1B->setEnabled(true);
			EmbarkA2B->setEnabled(true);
			EmbarkA3B->setEnabled(true);
			EmbarkB1B->setEnabled(true);
			EmbarkB2B->setEnabled(true);
			EmbarkC1B->setEnabled(true);
			EmbarkC2B->setEnabled(true);

			Belltten->setEnabled(true);//리본
			EmbarkBack->setEnabled(true);//항해뒤로가기
			OptionButton->setEnabled(true); // 옵션 버튼
			TradeButton->setEnabled(true); // 교역소 버튼 
			ShipyardButton->setEnabled(true); // 배 업그레이드 버튼 조선소
			EmbarkButton->setEnabled(true); // 항해 버튼
			InventoryButton->setEnabled(true); // 인벤토리 버튼 
		}
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener12, _tutorialtalk);
}

void MenuScene::CharacterEYE(bool _eyemod)
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

void MenuScene::News()
{
	schedule(schedule_selector(MenuScene::secondsnews30), 34, 100, 10.0f);
}
void MenuScene::secondsnews30(float dt)
{
	newslabel();          // KGSH
}
void MenuScene::newslabel()
{
	NewsLabel->setVisible(true);     //KGSH
	BgMap2->setVisible(true);
	int k = num;
	num = RandomHelper::random_int(1, 13);
	while (k == num)
		num = RandomHelper::random_int(1, 13);


	NewsLabel->setPosition(Vec2(1550, 494));

	switch (num)
	{
	case 1:
		NewsLabel->setString("콜로니아 옷감 시세가 20% 낮습니다");
		break;
	case 2:
		NewsLabel->setString("히스파니아 농산물 시세가 20% 낮습니다");
		break;
	case 3:
		NewsLabel->setString("히스파니아 전체 교역품 시세가 10% 낮습니다");
		break;
	case 4:
		NewsLabel->setString("빌른 농산물 시세가 10% 낮습니다");
		break;
	case 5:
		NewsLabel->setString("메디올리움 해산물 시세가 15% 낮습니다");
		break;
	case 6:
		NewsLabel->setString("브리타니아 시세 변화율이 2배 높습니다");
		break;
	case 7:
		NewsLabel->setString("브리타니아 옷감 시세가 20% 낮습니다");
		break;
	case 8:
		NewsLabel->setString("브리타니아 보석 시세가 20% 높습니다");
		break;
	case 9:
		NewsLabel->setString("알비온 해산물 시세가 10% 낮습니다");
		break;
	case 10:
		NewsLabel->setString("하셀로 향신료 시세가 40% 낮습니다");
		break;
	case 11:
		NewsLabel->setString("하셀로 광물 시세가 20% 높습니다");
		break;
	case 12:
		NewsLabel->setString("시르 농산물 시세가 30% 낮습니다");
		break;
	case 13:
		NewsLabel->setString("아레카테 옷감 시세가 10% 낮습니다");
		break;

	}

	auto move = MoveBy::create(13, Vec2(-1300, 0));
	auto delay = DelayTime::create(13);
	NewsLabel->runAction(Sequence::create(move, CallFunc::create([&] {NewsLabel->setVisible(false); }), NULL));       //KG
	BgMap2->runAction(Sequence::create(delay, CallFunc::create([&] {BgMap2->setVisible(false); }), NULL));
}
void MenuScene::down()
{
	if (!opened)
	{
		opened = true;
		Pop->runAction(ScaleTo::create(0.3f, 1));
		TitleSpr[0]->setTexture("MainMenu/designation1.png");
		TitleSpr[1]->setTexture("MainMenu/designation.png");
	}
	else if (opened)
	{
		opened = false;
		Pop->runAction(ScaleTo::create(0.3f, 1, 0));
		TitleSpr[0]->setTexture("MainMenu/designation.png");
		TitleSpr[1]->setTexture("MainMenu/designation1.png");
	}
}
void MenuScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_Q:
		UserDefault::getInstance()->setIntegerForKey("MONEY", 0);
		break;
	case EventKeyboard::KeyCode::KEY_W:
		if(UserDefault::getInstance()->getIntegerForKey("MONEY")-10000>=0)
			UserDefault::getInstance()->setIntegerForKey("MONEY", UserDefault::getInstance()->getIntegerForKey("MONEY")-10000);
		break;
	case EventKeyboard::KeyCode::KEY_E:
		UserDefault::getInstance()->setIntegerForKey("MONEY", UserDefault::getInstance()->getIntegerForKey("MONEY") + 10000);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		UserDefault::getInstance()->setIntegerForKey("CASH", 0);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (UserDefault::getInstance()->getIntegerForKey("CASH")-100>=0)
			UserDefault::getInstance()->setIntegerForKey("CASH", UserDefault::getInstance()->getIntegerForKey("CASH") - 100);
		break;
	case EventKeyboard::KeyCode::KEY_D:
		UserDefault::getInstance()->setIntegerForKey("CASH", UserDefault::getInstance()->getIntegerForKey("CASH") + 100);
		break;
	}
}
void MenuScene::Bounce()
{
	auto jumping = JumpBy::create(5.0f, Point(0, 0), 30, 5);   // 시간, 위치, 높이, 횟수
	moveby = MoveBy::create(0.9f, Vec2(0, 50));
	moveby2 = MoveBy::create(0.9f, Vec2(0, -50));
	auto delaytime = DelayTime::create(1.1f);
	jump = EaseIn::create(moveby, 1.2f);
	jump2 = EaseOut::create(moveby2, 1.2f);
	Seq = Sequence::create(jumping, NULL);
	rep = RepeatForever::create(Seq);
}