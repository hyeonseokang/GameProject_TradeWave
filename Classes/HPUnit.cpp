#include "HPUnit.h"

HPUnit::HPUnit(Layer *layer,int red)   // 체력 유닛
{
	sprite = Sprite::create("Unit/Tanker/Walk/1.png");
	sprite->setScale(0.7f);
	layer->addChild(sprite, 1);
	auto Tintto = TintTo::create(1, Color3B(255, 0, 0));

	
	// 3 6 6 -> 2 4 4 
	if (red == 1)
	{
		atk = 2;
		hp = 4;
		kahp = 4;

		tower = false;
		end = false;
		timer = true;

		hpbuff = false;
		hpboss = false;
	}
	// 4 7 7 -> 3 5 5
	else if (red == 2)
	{
		atk = 3;
		hp = 5;
		kahp = 5;

		tower = false;

		end = false;
		timer = true;

		hpbuff = true;
		hpboss = false;

		sprite->runAction(Tintto);
	}
}

void HPUnit::hpbar(Layer *layer)
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

void HPUnit::walkani()
{

	walktest = true;
	if (walktest)
	{
		animation = Animation::create();

		for (int i = 1; i < 3; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "Unit/Tanker/Walk/%d.png", i);
			animation->addSpriteFrameWithFile(szName);
		}
		// should last 2.8 seconds. And there are 14 frames.
		animation->setDelayPerUnit(1.0 / 2.0);
		walkanimate = Animate::create(animation);
		Walk = RepeatForever::create(walkanimate);
		sprite->runAction(Walk); //StopAllAction
	}
}


void HPUnit::hitani() // 맞았을때
{

		if (atktest)
		{
			sprite->stopAction(atkanimate); //여기에 그거
		}
		animation = Animation::create();

		for (int i = 1; i < 3; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "Unit/Tanker/Hit/%d.png", i);
			animation->addSpriteFrameWithFile(szName);
		}
		// should last 2.8 seconds. And there are 14 frames.
		animation->setDelayPerUnit(1.0 / 4.0);
		hitanimate = Animate::create(animation);
		sprite->runAction(hitanimate); //StopAllAction
	
}

void HPUnit::atkani()
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
		char szName[100] = { 0 };
		sprintf(szName, "Unit/Tanker/Atk/%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 3.0);
	atkanimate = Animate::create(animation);
	sprite->runAction(atkanimate); //StopAllAction
}

void HPUnit::dieani()
{
	sprite->stopAllActions();

	animation = Animation::create();

	for (int i = 1; i < 4; i++)
	{
		char szName[100] = { 0 };

		sprintf(szName, "Unit/Tanker/Die/%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 10.0);
	dieanimate = Animate::create(animation);

	auto fade = FadeOut::create(0.5);
	auto seq = Sequence::create(dieanimate, fade, NULL);
	sprite->runAction(seq); //StopAllAction
}



void HPUnit::ex()
{
	auto delay = DelayTime::create(1.5f);
	auto Seq = Sequence::create(delay, CallFunc::create([&] { timer = true; }), NULL);
	sprite->runAction(Seq);
}