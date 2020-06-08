#include "Cannon.h"

Cannon::Cannon(Layer *layer, Layer * layer2)
{
	end = true;
	cannon_lay = Layer::create();
	cannon_lay->setVisible(false);
	layer->addChild(cannon_lay);
	cannonsprite = Sprite::create("Cannon/Cannon.png");
	cannonsprite->setVisible(false);
	cannonsprite->setPosition(Vec2(-20000,-20000));
	layer2->addChild(cannonsprite);
	effect = Sprite::create();
	layer2->addChild(effect);
	joypad = Sprite::create("joypad.png");
	wheel = Sprite::create("wheel.png");
	cannon_lay->addChild(joypad);
	cannon_lay->addChild(wheel);
}

void Cannon::touched(Vec2 pos, Vec2 ship_pos)
{
	end = false;
	began_pos = pos;
	cannon_lay->setVisible(true);
	joypad->setPosition(began_pos);
	wheel->setPosition(began_pos);
}

void Cannon::moved(Vec2 pos)
{
	moved_pos = pos;
	temp = sqrt(pow(began_pos.x-moved_pos.x,2)+pow(began_pos.y-moved_pos.y,2));
	float angle = atan2f(began_pos.y - moved_pos.y,began_pos.x - moved_pos.x);
	cannonsprite->setRotation(angle*-180/M_PI+180);
	float x = cos(angle) * -100+ began_pos.x;
	float y = sin(angle) * -100+ began_pos.y;
	if (temp < 100)
	{
		wheel->setPosition(moved_pos);
	}
	else
	{
		wheel->setPosition(Vec2(x,y));
	}
}

void Cannon::ended(Vec2 pos, Vec2 ship_pos)
{
	end = true;
	cannon_lay->setVisible(false);
	wheel->setPosition(began_pos);
	cannonsprite->setPosition(ship_pos);
	if(end)
		cannon_act(cannonsprite,pos-began_pos);
}

void Cannon::cannon_act(Sprite * c, Vec2 pos)
{
	miss_enabled = true;
	cannonsprite->cleanup();
	cannonsprite->setVisible(true);
	auto moveby = MoveBy::create(temp / 1500, pos);
	auto Scale1 = ScaleTo::create(temp / 3000, 2.0);
	auto Scale2 = ScaleTo::create(temp / 3000, 1.0);
	auto Seq2 = Sequence::create(Scale1, Scale2, NULL);
	auto Spawn = Spawn::create(moveby, Seq2, NULL);
	c->runAction(Sequence::create(Spawn, CallFunc::create([&] {miss_ani(); })
		, CallFunc::create([&] { cannonsprite->setPosition(Vec2(0, -200)); }),Hide::create(),nullptr));
}

void Cannon::Destroy()
{
	cannon_lay->removeAllChildren();
	cannonsprite->setVisible(false);
}

void Cannon::miss_ani()
{
	auto m_ani = Animation::create();
	for (int i = 1; i <= 5; i++)
	{
		m_ani->addSpriteFrameWithFileName(StringUtils::format("Animation/effect/miss0%d.png", i));
	}
	m_ani->setDelayPerUnit(0.1f);
	auto m_animate = Animate::create(m_ani);
	if (miss_enabled)
	{
		effect->setPosition(cannonsprite->getPosition());
		effect->runAction(Sequence::create(Show::create(), m_animate, Hide::create(), nullptr));
	}
}
