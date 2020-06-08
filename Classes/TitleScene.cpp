#include"TitleScene.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include"Singleton.h"
SingleTon*SingleTon::instant = NULL;
USING_NS_CC;
Scene* TitleScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TitleScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	this->setTouchEnabled(true); //터치 활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	SingleTon::getinstance()->setTitle(0);
	if (!(UserDefault::getInstance()->getBoolForKey("STARTLOAD")))
	{
		UserDefault::getInstance()->setBoolForKey("TUTORIAL", false);
		UserDefault::getInstance()->setBoolForKey("STARTLOAD", true); // 처음시작 확인
		UserDefault::getInstance()->setIntegerForKey("NOW", 4); // 지금 어디지역인지
		UserDefault::getInstance()->setIntegerForKey("COUNT", 0); // 항해일자
																  //////////////////////// 가지고 있는 갯수 ///////////////////////
		UserDefault::getInstance()->setIntegerForKey("HMAX", 0);//최대 적재량 
		UserDefault::getInstance()->setIntegerForKey("MAX", 50);//최대 적재량 

		UserDefault::getInstance()->setIntegerForKey("CEMETERY", 0);//시크릿교역품
		UserDefault::getInstance()->setIntegerForKey("CINTAMANI", 0);
		UserDefault::getInstance()->setIntegerForKey("WRISTBAND", 0);

		UserDefault::getInstance()->setIntegerForKey("HPEPPER", 0);
		UserDefault::getInstance()->setIntegerForKey("HGARLIC", 0);
		UserDefault::getInstance()->setIntegerForKey("HSUGAR", 0);
		UserDefault::getInstance()->setIntegerForKey("HCINNAMON", 0);

		UserDefault::getInstance()->setIntegerForKey("HRICE", 0);
		UserDefault::getInstance()->setIntegerForKey("HONION", 0);
		UserDefault::getInstance()->setIntegerForKey("HWHEAT", 0);
		UserDefault::getInstance()->setIntegerForKey("HWONION", 0);

		UserDefault::getInstance()->setIntegerForKey("HSHELLFISH", 0);
		UserDefault::getInstance()->setIntegerForKey("HFISH", 0);
		UserDefault::getInstance()->setIntegerForKey("HLOBSTER", 0);
		UserDefault::getInstance()->setIntegerForKey("HSQUID", 0);

		UserDefault::getInstance()->setIntegerForKey("HDIAMOND", 0);
		UserDefault::getInstance()->setIntegerForKey("HRUBY", 0);
		UserDefault::getInstance()->setIntegerForKey("HPERIDOT", 0);
		UserDefault::getInstance()->setIntegerForKey("HPEARL", 0);

		UserDefault::getInstance()->setIntegerForKey("HIRON", 0);
		UserDefault::getInstance()->setIntegerForKey("HGOLD", 0);
		UserDefault::getInstance()->setIntegerForKey("HSILVER", 0);
		UserDefault::getInstance()->setIntegerForKey("HCOPPER", 0);

		UserDefault::getInstance()->setIntegerForKey("HLEATHER", 0);
		UserDefault::getInstance()->setIntegerForKey("HSILK", 0);
		UserDefault::getInstance()->setIntegerForKey("HNOODLE", 0);
		UserDefault::getInstance()->setIntegerForKey("HLINEN", 0);
		///////////////////////////////////////////////////////////////////
		UserDefault::getInstance()->setIntegerForKey("EXP", 290);
		UserDefault::getInstance()->setIntegerForKey("MONEY", 100000);
		UserDefault::getInstance()->setIntegerForKey("CASH", 100);
		UserDefault::getInstance()->setIntegerForKey("NSHIPHP", 100); //가지고있는 배체력 
		UserDefault::getInstance()->setIntegerForKey("SHIPHP", 1);// 배체력 레벨
		UserDefault::getInstance()->setIntegerForKey("SHIPATTACK", 1); // 베 공격력
		UserDefault::getInstance()->setIntegerForKey("SHIPSPEED", 1); // 배 스피드 

		UserDefault::getInstance()->setIntegerForKey("A1PEPPER", 450);
		UserDefault::getInstance()->setIntegerForKey("A1GARLIC", 270);
		UserDefault::getInstance()->setIntegerForKey("A1SUGAR", 630);
		UserDefault::getInstance()->setIntegerForKey("A1CINNAMON", 405);
		UserDefault::getInstance()->setIntegerForKey("A1RICE", 160);
		UserDefault::getInstance()->setIntegerForKey("A1ONION", 200);
		UserDefault::getInstance()->setIntegerForKey("A1WHEAT", 144);
		UserDefault::getInstance()->setIntegerForKey("A1WONION", 184);

		UserDefault::getInstance()->setIntegerForKey("A1SHELLFISH", 360);
		UserDefault::getInstance()->setIntegerForKey("A1FISH", 315);
		UserDefault::getInstance()->setIntegerForKey("A1LOBSTER", 720);
		UserDefault::getInstance()->setIntegerForKey("A1SQUID", 360);

		UserDefault::getInstance()->setIntegerForKey("A1DIAMOND", 7200);
		UserDefault::getInstance()->setIntegerForKey("A1RUBY", 4500);
		UserDefault::getInstance()->setIntegerForKey("A1PERIDOT", 1350);
		UserDefault::getInstance()->setIntegerForKey("A1PEARL", 2700);

		UserDefault::getInstance()->setIntegerForKey("A1IRON", 270);
		UserDefault::getInstance()->setIntegerForKey("A1GOLD", 1800);
		UserDefault::getInstance()->setIntegerForKey("A1SILVER", 720);
		UserDefault::getInstance()->setIntegerForKey("A1COPPER", 360);

		UserDefault::getInstance()->setIntegerForKey("A1LEATHER", 350);
		UserDefault::getInstance()->setIntegerForKey("A1SILK", 700);
		UserDefault::getInstance()->setIntegerForKey("A1NOODLE", 315);
		UserDefault::getInstance()->setIntegerForKey("A1LINEN", 420);



		UserDefault::getInstance()->setIntegerForKey("A2PEPPER", 450);
		UserDefault::getInstance()->setIntegerForKey("A2GARLIC", 270);
		UserDefault::getInstance()->setIntegerForKey("A2SUGAR", 630);
		UserDefault::getInstance()->setIntegerForKey("A2CINNAMON", 405);

		UserDefault::getInstance()->setIntegerForKey("A2RICE", 120);
		UserDefault::getInstance()->setIntegerForKey("A2ONION", 150);
		UserDefault::getInstance()->setIntegerForKey("A2WHEAT", 108);
		UserDefault::getInstance()->setIntegerForKey("A2WONION", 138);

		UserDefault::getInstance()->setIntegerForKey("A2SHELLFISH", 360);
		UserDefault::getInstance()->setIntegerForKey("A2FISH", 315);
		UserDefault::getInstance()->setIntegerForKey("A2LOBSTER", 720);
		UserDefault::getInstance()->setIntegerForKey("A2SQUID", 360);

		UserDefault::getInstance()->setIntegerForKey("A2DIAMOND", 7200);
		UserDefault::getInstance()->setIntegerForKey("A2RUBY", 4500);
		UserDefault::getInstance()->setIntegerForKey("A2PERIDOT", 1350);
		UserDefault::getInstance()->setIntegerForKey("A2PEARL", 2700);

		UserDefault::getInstance()->setIntegerForKey("A2IRON", 270);
		UserDefault::getInstance()->setIntegerForKey("A2GOLD", 1800);
		UserDefault::getInstance()->setIntegerForKey("A2SILVER", 720);
		UserDefault::getInstance()->setIntegerForKey("A2COPPER", 360);

		UserDefault::getInstance()->setIntegerForKey("A2LEATHER", 450);
		UserDefault::getInstance()->setIntegerForKey("A2SILK", 900);
		UserDefault::getInstance()->setIntegerForKey("A2NOODLE", 405);
		UserDefault::getInstance()->setIntegerForKey("A2LINEN", 540);



		UserDefault::getInstance()->setIntegerForKey("A3PEPPER", 450);
		UserDefault::getInstance()->setIntegerForKey("A3GARLIC", 270);
		UserDefault::getInstance()->setIntegerForKey("A3SUGAR", 630);
		UserDefault::getInstance()->setIntegerForKey("A3CINNAMON", 405);

		UserDefault::getInstance()->setIntegerForKey("A3RICE", 160);
		UserDefault::getInstance()->setIntegerForKey("A3ONION", 200);
		UserDefault::getInstance()->setIntegerForKey("A3WHEAT", 144);
		UserDefault::getInstance()->setIntegerForKey("A3WONION", 184);

		UserDefault::getInstance()->setIntegerForKey("A3SHELLFISH", 300);
		UserDefault::getInstance()->setIntegerForKey("A3FISH", 187);
		UserDefault::getInstance()->setIntegerForKey("A3LOBSTER", 600);
		UserDefault::getInstance()->setIntegerForKey("A3SQUID", 337);

		UserDefault::getInstance()->setIntegerForKey("A3DIAMOND", 7200);
		UserDefault::getInstance()->setIntegerForKey("A3RUBY", 4500);
		UserDefault::getInstance()->setIntegerForKey("A3PERIDOT", 1350);
		UserDefault::getInstance()->setIntegerForKey("A3PEARL", 2700);

		UserDefault::getInstance()->setIntegerForKey("A3IRON", 270);
		UserDefault::getInstance()->setIntegerForKey("A3GOLD", 1800);
		UserDefault::getInstance()->setIntegerForKey("A3SILVER", 720);
		UserDefault::getInstance()->setIntegerForKey("A3COPPER", 360);

		UserDefault::getInstance()->setIntegerForKey("A3LEATHER", 450);
		UserDefault::getInstance()->setIntegerForKey("A3SILK", 900);
		UserDefault::getInstance()->setIntegerForKey("A3NOODLE", 405);
		UserDefault::getInstance()->setIntegerForKey("A3LINEN", 540);



		UserDefault::getInstance()->setIntegerForKey("B1PEPPER", 500);
		UserDefault::getInstance()->setIntegerForKey("B1GARLIC", 300);
		UserDefault::getInstance()->setIntegerForKey("B1SUGAR", 700);
		UserDefault::getInstance()->setIntegerForKey("B1CINNAMON", 450);

		UserDefault::getInstance()->setIntegerForKey("B1RICE", 200);
		UserDefault::getInstance()->setIntegerForKey("B1ONION", 250);
		UserDefault::getInstance()->setIntegerForKey("B1WHEAT", 180);
		UserDefault::getInstance()->setIntegerForKey("B1WONION", 230);

		UserDefault::getInstance()->setIntegerForKey("B1SHELLFISH", 400);
		UserDefault::getInstance()->setIntegerForKey("B1FISH", 350);
		UserDefault::getInstance()->setIntegerForKey("B1LOBSTER", 800);
		UserDefault::getInstance()->setIntegerForKey("B1SQUID", 450);

		UserDefault::getInstance()->setIntegerForKey("B1DIAMOND", 9600);
		UserDefault::getInstance()->setIntegerForKey("B1RUBY", 6000);
		UserDefault::getInstance()->setIntegerForKey("B1PERIDOT", 1800);
		UserDefault::getInstance()->setIntegerForKey("B1PEARL", 3600);

		UserDefault::getInstance()->setIntegerForKey("B1IRON", 300);
		UserDefault::getInstance()->setIntegerForKey("B1GOLD", 2000);
		UserDefault::getInstance()->setIntegerForKey("B1SILVER", 800);
		UserDefault::getInstance()->setIntegerForKey("B1COPPER", 400);

		UserDefault::getInstance()->setIntegerForKey("B1LEATHER", 400);
		UserDefault::getInstance()->setIntegerForKey("B1SILK", 800);
		UserDefault::getInstance()->setIntegerForKey("B1NOODLE", 360);
		UserDefault::getInstance()->setIntegerForKey("B1LINEN", 480);



		UserDefault::getInstance()->setIntegerForKey("B2PEPPER", 500);
		UserDefault::getInstance()->setIntegerForKey("B2GARLIC", 300);
		UserDefault::getInstance()->setIntegerForKey("B2SUGAR", 700);
		UserDefault::getInstance()->setIntegerForKey("B2CINNAMON", 450);

		UserDefault::getInstance()->setIntegerForKey("B2RICE", 200);
		UserDefault::getInstance()->setIntegerForKey("B2ONION", 250);
		UserDefault::getInstance()->setIntegerForKey("B2WHEAT", 180);
		UserDefault::getInstance()->setIntegerForKey("B2WONION", 230);

		UserDefault::getInstance()->setIntegerForKey("B2SHELLFISH", 360);
		UserDefault::getInstance()->setIntegerForKey("B2FISH", 315);
		UserDefault::getInstance()->setIntegerForKey("B2LOBSTER", 720);
		UserDefault::getInstance()->setIntegerForKey("B2SQUID", 360);

		UserDefault::getInstance()->setIntegerForKey("B2DIAMOND", 8000);
		UserDefault::getInstance()->setIntegerForKey("B2RUBY", 4500);
		UserDefault::getInstance()->setIntegerForKey("B2PERIDOT", 1350);
		UserDefault::getInstance()->setIntegerForKey("B2PEARL", 2700);

		UserDefault::getInstance()->setIntegerForKey("B2IRON", 300);
		UserDefault::getInstance()->setIntegerForKey("B2GOLD", 2000);
		UserDefault::getInstance()->setIntegerForKey("B2SILVER", 800);
		UserDefault::getInstance()->setIntegerForKey("B2COPPER", 400);

		UserDefault::getInstance()->setIntegerForKey("B2LEATHER", 400);
		UserDefault::getInstance()->setIntegerForKey("B2SILK", 800);
		UserDefault::getInstance()->setIntegerForKey("B2NOODLE", 300);
		UserDefault::getInstance()->setIntegerForKey("B2LINEN", 480);



		UserDefault::getInstance()->setIntegerForKey("C1PEPPER", 300);
		UserDefault::getInstance()->setIntegerForKey("C1GARLIC", 180);
		UserDefault::getInstance()->setIntegerForKey("C1SUGAR", 420);
		UserDefault::getInstance()->setIntegerForKey("C1CINNAMON", 270);

		UserDefault::getInstance()->setIntegerForKey("C1RICE", 140);
		UserDefault::getInstance()->setIntegerForKey("C1ONION", 175);
		UserDefault::getInstance()->setIntegerForKey("C1WHEAT", 126);
		UserDefault::getInstance()->setIntegerForKey("C1WONION", 161);

		UserDefault::getInstance()->setIntegerForKey("C1SHELLFISH", 400);
		UserDefault::getInstance()->setIntegerForKey("C1FISH", 350);
		UserDefault::getInstance()->setIntegerForKey("C1LOBSTER", 800);
		UserDefault::getInstance()->setIntegerForKey("C1SQUID", 450);

		UserDefault::getInstance()->setIntegerForKey("C1DIAMOND", 8000);
		UserDefault::getInstance()->setIntegerForKey("C1RUBY", 5000);
		UserDefault::getInstance()->setIntegerForKey("C1PERIDOT", 1500);
		UserDefault::getInstance()->setIntegerForKey("C1PEARL", 3000);

		UserDefault::getInstance()->setIntegerForKey("C1IRON", 360);
		UserDefault::getInstance()->setIntegerForKey("C1GOLD", 2400);
		UserDefault::getInstance()->setIntegerForKey("C1SILVER", 960);
		UserDefault::getInstance()->setIntegerForKey("C1COPPER", 480);

		UserDefault::getInstance()->setIntegerForKey("C1LEATHER", 500);
		UserDefault::getInstance()->setIntegerForKey("C1SILK", 1000);
		UserDefault::getInstance()->setIntegerForKey("C1NOODLE", 450);
		UserDefault::getInstance()->setIntegerForKey("C1LINEN", 600);



		UserDefault::getInstance()->setIntegerForKey("C2PEPPER", 300);
		UserDefault::getInstance()->setIntegerForKey("C2GARLIC", 180);
		UserDefault::getInstance()->setIntegerForKey("C2SUGAR", 420);
		UserDefault::getInstance()->setIntegerForKey("C2CINNAMON", 270);

		UserDefault::getInstance()->setIntegerForKey("C2RICE", 200);
		UserDefault::getInstance()->setIntegerForKey("C2ONION", 250);
		UserDefault::getInstance()->setIntegerForKey("C2WHEAT", 180);
		UserDefault::getInstance()->setIntegerForKey("C2WONION", 230);

		UserDefault::getInstance()->setIntegerForKey("C2SHELLFISH", 400);
		UserDefault::getInstance()->setIntegerForKey("C2FISH", 350);
		UserDefault::getInstance()->setIntegerForKey("C2LOBSTER", 800);
		UserDefault::getInstance()->setIntegerForKey("C2SQUID", 450);

		UserDefault::getInstance()->setIntegerForKey("C2DIAMOND", 8000);
		UserDefault::getInstance()->setIntegerForKey("C2RUBY", 5000);
		UserDefault::getInstance()->setIntegerForKey("C2PERIDOT", 1500);
		UserDefault::getInstance()->setIntegerForKey("C2PEARL", 3000);

		UserDefault::getInstance()->setIntegerForKey("C2IRON", 360);
		UserDefault::getInstance()->setIntegerForKey("C2GOLD", 2400);
		UserDefault::getInstance()->setIntegerForKey("C2SILVER", 960);
		UserDefault::getInstance()->setIntegerForKey("C2COPPER", 480);

		UserDefault::getInstance()->setIntegerForKey("C2LEATHER", 450);
		UserDefault::getInstance()->setIntegerForKey("C2SILK", 900);
		UserDefault::getInstance()->setIntegerForKey("C2NOODLE", 405);
		UserDefault::getInstance()->setIntegerForKey("C2LINEN", 540);




		/////////////////// 전시세 저장 ////////////////////////////////
		UserDefault::getInstance()->setIntegerForKey("LPEPPER", 0);
		UserDefault::getInstance()->setIntegerForKey("LGARLIC", 0);
		UserDefault::getInstance()->setIntegerForKey("LSUGAR", 0);
		UserDefault::getInstance()->setIntegerForKey("LCINNAMON", 0);

		UserDefault::getInstance()->setIntegerForKey("LRICE", 0);
		UserDefault::getInstance()->setIntegerForKey("LONION", 0);
		UserDefault::getInstance()->setIntegerForKey("LWHEAT", 0);
		UserDefault::getInstance()->setIntegerForKey("LWONION", 0);

		UserDefault::getInstance()->setIntegerForKey("LSHELLFISH", 0);
		UserDefault::getInstance()->setIntegerForKey("LFISH", 0);
		UserDefault::getInstance()->setIntegerForKey("LLOBSTER", 0);
		UserDefault::getInstance()->setIntegerForKey("LSQUID", 0);

		UserDefault::getInstance()->setIntegerForKey("LDIAMOND", 0);
		UserDefault::getInstance()->setIntegerForKey("LRUBY", 0);
		UserDefault::getInstance()->setIntegerForKey("LPERIDOT", 0);
		UserDefault::getInstance()->setIntegerForKey("LPEARL", 0);

		UserDefault::getInstance()->setIntegerForKey("LIRON", 0);
		UserDefault::getInstance()->setIntegerForKey("LGOLD", 0);
		UserDefault::getInstance()->setIntegerForKey("LSILVER", 0);
		UserDefault::getInstance()->setIntegerForKey("LCOPPER", 0);

		UserDefault::getInstance()->setIntegerForKey("LLEATHER", 0);
		UserDefault::getInstance()->setIntegerForKey("LSILK", 0);
		UserDefault::getInstance()->setIntegerForKey("LNOODLE", 0);
		UserDefault::getInstance()->setIntegerForKey("LLINEN", 0);
		UserDefault::getInstance()->setIntegerForKey("SHIPSKIN", 1);
		/////////////////////////////////////////////////////////////////////
		UserDefault::getInstance()->setIntegerForKey("SHIPSKIN", 1);   //현재 장착중인 스킨 , 빨,파,초,노(1,2,3,4)
		UserDefault::getInstance()->setIntegerForKey("REDSKIN", 1);     // 0 미보유 , 1 보유중 
		UserDefault::getInstance()->setIntegerForKey("BLUESKIN", 0);
		UserDefault::getInstance()->setIntegerForKey("GREENSKIN", 0);
		UserDefault::getInstance()->setIntegerForKey("YELLOWSKIN", 0);


		UserDefault::getInstance()->setBoolForKey("DISASTER", false);
		UserDefault::getInstance()->setIntegerForKey("DISATERNUM", 0);
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	enabled = false;
	auto background = Sprite::create("Title/Title.png");
	background->setAnchorPoint(Vec2::ZERO);
	this->addChild(background);
	auto black_layer = LayerColor::create();
	black_layer->setOpacity(0);
	black_layer->runAction(Sequence::create(DelayTime::create(1),FadeTo::create(1,100),nullptr));
	this->addChild(black_layer);
	auto TradeWave = Sprite::create("Title/TradeWave.png");
	TradeWave->setPosition(Vec2(640,450));
	TradeWave->setOpacity(0);
	TradeWave->runAction(FadeIn::create(1));
	this->addChild(TradeWave);
	auto TouchTheScreen = Sprite::create("Title/TouchTheScreen.png");
	TouchTheScreen->setPosition(Vec2(640,200));
	TouchTheScreen->setVisible(false);
	auto blink = Blink::create(50,80);
	TouchTheScreen->runAction(Sequence::create(DelayTime::create(1), Show::create()
		, CallFunc::create([&] {enabled = true; }),blink, nullptr));
	this->addChild(TouchTheScreen);
	//auto seq = Sequence::create(CallFunc::create([&] {}),,,nullptr);

	//LoadingPercent = Label::create("0%", "fonts/JejuGothic-Regular.ttf", 60);
	//LoadingPercent->setPosition(Vec2(640, 200));
	//this->addChild(LoadingPercent);
	//LoadingTexture();
	return true;
}


void TitleScene::Start_changeScene(Ref *sender)
{
	TransitionFade* ChangeScene_Impact = TransitionFade::create(0.5, MenuScene::createScene());//화면 전환 효과
	Director::getInstance()->replaceScene(ChangeScene_Impact);           //화면 전환 함수
}

//void TitleScene::LoadingCallback(Texture2D * texture)
//{
//	++LoadingTexturenum;
//	LoadingPercent->setString(StringUtils::format("%d%", (int)(((float)LoadingTexturenum / LoadingAllTexture) * 100)));
//	if (LoadingTexturenum == LoadingAllTexture)
//		this->setTouchEnabled(true);
//}
//
//void TitleScene::LoadingTexture()
//{
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/2.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/4.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/5.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/BgOption.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/CheckBox.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Coin.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/designation.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Embark00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Embark01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/GoldBox.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/insignia.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/insignia1.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Inventory00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Inventory01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Jewelry00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/map00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/NameBox.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/News.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Option00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Option01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Title2.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Trading00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Trading01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Upgrade00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("MainMenu/Upgrade01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	//////////////////////////
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/baseBgTrade1.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/BgTrade.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/BgTrade1.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/BgTrade2.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/BuyTrade00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/BuyTrade01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/Category00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/Category01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/down.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/ItemButton.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/ItemImage.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/ItemImage00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/SellButton.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/SellButton01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/SellTrade00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/SellTrade01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/up.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/arrow00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/arrow01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/BuyButton00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/BuyButton01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/Count00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/ItemImage.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/ItemImage.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/buy/ItemImage01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/Sell/Count.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/Sell/SellButton00.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//	Director::getInstance()->getTextureCache()->addImageAsync("Trade/Sell/SellButton01.png", CC_CALLBACK_1(TitleScene::LoadingCallback, this));
//
//}

bool TitleScene::onTouchBegan(Touch* touch, Event* unsed_event)                //터치 함수
{
	if (enabled)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/TitleTouch.mp3");
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();  //다음씬에서 터치 안되게 끊어주는것.
		TransitionFade* ChangeScene_Impact = TransitionFade::create(3.0, MenuScene::createScene());  //화면전환효과
		Director::getInstance()->replaceScene(ChangeScene_Impact);
	}
	return true;
}

void TitleScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
