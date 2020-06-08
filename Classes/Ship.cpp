#include"Ship.h"
#include"Singleton.h"
Ship::Ship(Layer*layer)
{
	lay = layer;
	lay->setAnchorPoint(Vec2::ZERO);
	wave = Sprite::create();
	wave_ani(wave);
	wave->setAnchorPoint(Vec2(0.5, 0.7));
	lay->addChild(wave);
	ship_png = Sprite::create("ShipMove/body.png");
	speed = 4 - UserDefault::getInstance()->getIntegerForKey("HMAX") * 0.02 + UserDefault::getInstance()->getIntegerForKey("SHIPSPEED") * 0.1;
	lay->addChild(ship_png);
	int color = UserDefault::getInstance()->getIntegerForKey("SHIPSKIN");
	sail[0] = Sprite::create(StringUtils::format("ShipMove/b%d.png",color));
	sail[1] = Sprite::create(StringUtils::format("ShipMove/t%d.png", color));

	auto up = ScaleBy::create(0.2f, 1, 1.1f);
	auto seq = Sequence::create(up, up->reverse(), nullptr);
	for (int i = 0; i <= 1; i++)
	{
		sail[i]->runAction(RepeatForever::create(seq->clone()));
		lay->addChild(sail[i]);
	}
}

void Ship::wave_ani(Sprite * w)
{
	auto w_ani = Animation::create();
	for (int i = 1; i <= 3; i++)
	{
		w_ani->addSpriteFrameWithFileName(StringUtils::format("Animation/0%d.png", i));
	}
	w_ani->setDelayPerUnit(0.3f);
	auto w_animate = Animate::create(w_ani);
	wave->runAction(RepeatForever::create(w_animate));
}

void Ship::setPos(Vec2 pos)
{
	if (SingleTon::getinstance()->getTutorial() != 2 && SingleTon::getinstance()->getTutorial() != 4)
		lay->setPosition(pos);
}

Vec2 Ship::getPos()
{
	return lay->getPosition();
}

float Ship::getPosX()
{
	return lay->getPositionX();
}

float Ship::getPosY()
{
	return lay->getPositionY();
}

void Ship::setSpeed(float S)
{
	speed = S;
}

float Ship::getSpeed()
{
	return speed;
}

void Ship::setRotate(float a)
{
	lay->setRotation(a);
}

float Ship::getRotate()
{
	return lay->getRotation();
}
