#pragma once

#include "cocos2d.h"
USING_NS_CC;
class LogoScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	Sprite*Logofont;
	Sprite*Logo;
	virtual bool init();
	void action();
	CREATE_FUNC(LogoScene);
	
};
