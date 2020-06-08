#include "LogoScene.h"
#include"TitleScene.h"
USING_NS_CC;
Scene* LogoScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LogoScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LogoScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Logo = Sprite::create("All/logo.png");
	Logo->setPosition(Vec2(640, 360));
	this->addChild(Logo);
	Logo->setOpacity(0);
	
	Logofont = Sprite::create("All/logo_font.png");
	Logofont->setPosition(Vec2(640, 200));
	Logofont->setOpacity(0);
	this->addChild(Logofont);

	auto action_0 = FadeIn::create(2.0);
	Logo->runAction(Sequence::create(action_0, CallFunc::create(CC_CALLBACK_0(LogoScene::action, this))
	,NULL));
	
	return true;
}

void LogoScene::action()
{
	auto FadeOutLogo = FadeIn::create(2.0);
	Logofont->runAction(Sequence::create(FadeOutLogo, CallFunc::create([] {
		TransitionFade* ChangeScene_Impact = TransitionFade::create(0.5, TitleScene::createScene());
		Director::getInstance()->replaceScene(ChangeScene_Impact);

	}),NULL));
}
