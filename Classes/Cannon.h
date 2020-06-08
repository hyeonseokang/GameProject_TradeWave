#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Cannon
{
public:
	Sprite *cannonsprite;
	Sprite *joypad;
	Sprite*wheel;
	Sprite*effect;
	Layer*cannon_lay;
	Cannon(Layer *layer,Layer * layer2);
	Vec2 began_pos;
	Vec2 moved_pos;
	Vec2 end_pos;
	void touched(Vec2 pos, Vec2 ship_pos);
	void moved(Vec2 pos);
	void ended(Vec2 pos, Vec2 ship_pos);
	void cannon_act(Sprite * c,Vec2 pos);
	void Destroy();
	void miss_ani();
	float temp;
	bool end;
	bool miss_enabled;
};