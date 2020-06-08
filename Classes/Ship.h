#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

class Ship
{
public:
	Ship(Layer*layer);
	Layer*lay;
	Sprite*ship_png;
	Sprite*wave;
	Sprite*sail[2];
	float speed;
	void wave_ani(Sprite * w);
	void setPos(Vec2 pos);
	Vec2 getPos();
	float getPosX();
	float getPosY();
	void setSpeed(float S);
	float getSpeed();
	void setRotate(float a);
	float getRotate();
};