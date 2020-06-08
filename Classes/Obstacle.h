#pragma once
#include "cocos2d.h"                  

USING_NS_CC;

class Obstacle
{
public:
	Obstacle(Layer *lay,int tag);
	int num;
	Sprite *obj;
	void decide(int tag);
	Vec2 getPos();
	void setPos(Vec2 pos);
	int getNum();
};
 