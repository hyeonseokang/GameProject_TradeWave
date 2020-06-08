#include "Obstacle.h"

Obstacle::Obstacle(Layer * lay, int tag)
{
	obj = Sprite::create();
	if (tag <= 5)
	{
		num = 1;
	}
	else if (tag>5&&tag<=8)
	{
		num = 2;
	}
	else if (tag>8&&tag<=10)
	{
		num = 3;
	}
	decide(num);
	lay->addChild(obj);
}

void Obstacle::decide(int tag)
{
	if (tag == 1)//바위
	{
		obj->setTexture("ShipMove/Rock00.png");
	}
	if (tag == 2)//잔해물
	{
		obj->setTexture("ShipMove/Wreck00.png");
	}
	if (tag == 3)//소용돌이
	{
		//소용도리 애니
		auto t_ani = Animation::create();
		for (int i = 1; i <= 5; i++)
		{
			t_ani->addSpriteFrameWithFileName(StringUtils::format("Animation/Tornado0%d.png",i));
		}	
		t_ani->setDelayPerUnit(0.1f);
		auto t_animate = Animate::create(t_ani);
		obj->runAction(RepeatForever::create(t_animate));
	}
}

Vec2 Obstacle::getPos()
{
	return obj->getPosition();
}

void Obstacle::setPos(Vec2 pos)
{
	obj->setPosition(pos);
}

int Obstacle::getNum()
{
	return  num;
}
