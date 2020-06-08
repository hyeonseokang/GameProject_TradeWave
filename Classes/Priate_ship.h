#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

class Priate_ship
{
public:
	Priate_ship(Layer*layer);
	Layer*lay;
	Sprite*P_ship;
	Sprite*wave;
	Sprite*sail[2];
	Sprite*effect;
	void wave_ani(Sprite * w);
	void destroy();
	void setVis(bool b);
	void setPos(Vec2 pos);
	Vec2 getPos();
	void setRotate(float a);
	float getRotate();
	float getPosX();
	float getPosY();
	void explosion_ani();
};