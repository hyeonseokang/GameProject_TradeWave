#include "BombUnit.h"

BombUnit::BombUnit(Layer *layer , int red)  //스피드
{
	sprite = Sprite::create("Unit/Speed/Walk/1.png");
	sprite->setScale(0.7f);
	layer->addChild(sprite, 1);

	auto Tintto = TintTo::create(1, Color3B(255, 0, 0));
	//2 2 2 -> 3 1 1
	if (red == 1)
	{
		atk = 3;
		hp = 1;
		kahp = 1;

		tower = false;
		end = false;
		
		timer = true;
		hpbuff = false;
		hpboss = false;
	}

	//3 3 3 -> 4 2 2
	else if (red == 2)
	{
		atk = 4;
		hp = 2;
		kahp = 2;

		tower = false;

		end = false;
		timer = true;

		hpbuff = false;
		hpboss = false;

		sprite->runAction(Tintto);
	}
}



void BombUnit::hpbar(Layer *layer)
{

	auto delay = DelayTime::create(0.6f);
	auto Seq = Sequence::create(CallFunc::create([&] {progressBar->SetVisible(true); hptest++; }),
		delay, CallFunc::create([&]
	{
		hptest--;
		if (hptest == 0)
		{
			progressBar->SetVisible(false);
		}

	}), NULL); //체력바 나타났다가 사라짐

	progressBar->SetPercentage((float)hp / kahp);

	layer->runAction(Seq);
}

void BombUnit::walkani()
{
	walktest = true;
	if (walktest)
	{
		animation = Animation::create();

		for (int i = 1; i < 4; i++)
		{
			animation->addSpriteFrameWithFileName(StringUtils::format("Unit/Speed/Walk/%d.png", i));
		}
		// should last 2.8 seconds. And there are 14 frames.
		animation->setDelayPerUnit(1.0 / 10.0);
		walkanimate = Animate::create(animation);
		Walk = RepeatForever::create(walkanimate);
		sprite->runAction(Walk); //StopAllAction
	}
}

void BombUnit::hitani() // 맞았을때
{
	if (walktest)
	{
		sprite->stopAction(walkanimate);
	}
		if (atktest)
		{
			sprite->stopAction(atkanimate); //여기에 그거
		}
		animation = Animation::create();

		for (int i = 1; i < 3; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "Unit/Speed/Hit/%d.png", i);
			animation->addSpriteFrameWithFile(szName);
		}
		// should last 2.8 seconds. And there are 14 frames.
		animation->setDelayPerUnit(1.0 / 4.0);
		hitanimate = Animate::create(animation);
		sprite->runAction(hitanimate); //StopAllAction
	
}

void BombUnit::atkani()
{
	if (walktest)
	{
		sprite->stopAction(Walk);
		walktest = false;
	}
	if (!atktest)
	{
		atktest = true;
	}

	animation = Animation::create();

	for (int i = 1; i < 4; i++)
	{
		animation->addSpriteFrameWithFileName(StringUtils::format("Unit/Speed/Atk/%d.png",i));
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 9.0);
	atkanimate = Animate::create(animation);
	sprite->runAction(atkanimate); //StopAllAction
}

void BombUnit::dieani()
{
	sprite->stopAllActions();

	animation = Animation::create();

	for (int i = 1; i < 4; i++)
	{
		char szName[100] = { 0 };

		animation->addSpriteFrameWithFileName(StringUtils::format("Unit/Speed/Die/%d.png", i));
	
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 8.0);
	dieanimate = Animate::create(animation);

	auto fade = FadeOut::create(0.5);
	auto seq = Sequence::create(dieanimate, fade, NULL);
	sprite->runAction(seq); //StopAllAction
}

void BombUnit::ex()
{
	auto delay = DelayTime::create(0.5f);
	auto Seq = Sequence::create(delay, CallFunc::create([&] { timer = true; }), NULL);
	sprite->runAction(Seq);
}