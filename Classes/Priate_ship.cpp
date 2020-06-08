#include "Priate_ship.h"
#include"Singleton.h"
Priate_ship::Priate_ship(Layer * layer)
{
	lay = layer;
	lay->setAnchorPoint(Vec2::ZERO);
	wave = Sprite::create();
	wave_ani(wave);
	wave->setAnchorPoint(Vec2(0.5, 0.7));
	lay->addChild(wave);
	P_ship = Sprite::create("ShipMove/s_body.png");
	lay->addChild(P_ship);
	sail[0] = Sprite::create("ShipMove/s_b.png");
	sail[1] = Sprite::create("ShipMove/s_t.png");

	auto up = ScaleBy::create(0.2f, 1, 1.1f);
	auto seq = Sequence::create(up, up->reverse(), nullptr);
	for (int i = 0; i <= 1; i++)
	{
		sail[i]->runAction(RepeatForever::create(seq->clone()));
		lay->addChild(sail[i]);
	}
	effect = Sprite::create();
	lay->addChild(effect);
}
void Priate_ship::wave_ani(Sprite * w)
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
void Priate_ship::destroy()
{
	lay->removeAllChildren();
}
void Priate_ship::setVis(bool b)
{
	lay->setVisible(b);
}
void Priate_ship::setPos(Vec2 pos)
{
	if (SingleTon::getinstance()->getTutorial() != 2&& SingleTon::getinstance()->getTutorial() != 4)
		lay->setPosition(pos);
}

Vec2 Priate_ship::getPos()
{
	return lay->getPosition();
}

void Priate_ship::setRotate(float a)
{
	lay->setRotation(a);
}

float Priate_ship::getRotate()
{
	return lay->getRotation();
}

float Priate_ship::getPosX()
{
	return lay->getPositionX();
}

float Priate_ship::getPosY()
{
	return lay->getPositionY();
}

void Priate_ship::explosion_ani()
{
	auto e_ani = Animation::create();
	for (int i = 1; i <= 5; i++)
	{
		e_ani->addSpriteFrameWithFileName(StringUtils::format("Animation/effect/explosion0%d.png", i));
	}
	e_ani->setDelayPerUnit(0.1f);
	auto e_animate = Animate::create(e_ani);
	effect->runAction(Sequence::create(Show::create(),e_animate, Hide::create(), nullptr));
}
