#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

class Handle
{
public:
	Handle(Layer*layer);
	Layer*lay;
	Sprite*handle_png;
	void setPos(float x, float y);
	void setRotate(float a);
	float getRotate();
};