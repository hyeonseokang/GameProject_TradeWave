#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(Layer *layer , int red)
{
	sprite = Sprite::create("Unit/Normal/Walk/1.png");
	sprite->setScale(0.7f);
	layer->addChild(sprite, 1);
	auto Tintto = TintTo::create(1, Color3B(255, 0, 0));

	if (red == 1)
	{
		atk = 3;
		hp = 3;
		kahp = 3;

		tower = false;
		end = false;
		timer = true;
		hpbuff = false;
		hpboss = false;
	}
	else if (red == 2)
	{
		atk = 4;
		hp = 4;
		kahp = 4;

		tower = false;

		end = false;
		timer = true;


		hpbuff = false;
		hpboss = false;
		sprite->runAction(Tintto);
	}
}

void EnemyUnit::hpbar(Layer *layer)
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


void EnemyUnit::walkani()
{
	
	walktest = true;
	if (walktest)
	{
		animation = Animation::create();

		for (int i = 1; i < 3; i++)
		{
			animation->addSpriteFrameWithFileName(StringUtils::format("Unit/Normal/Walk/%d.png", i));
		}
		// should last 2.8 seconds. And there are 14 frames.
		animation->setDelayPerUnit(2.0 / 4.0);
		walkanimate = Animate::create(animation);
		Walk = RepeatForever::create(walkanimate);
		sprite->runAction(Walk); //StopAllAction
	}
}

void EnemyUnit::hitani() // 맞았을때
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
			sprintf(szName, "Unit/Normal/Hit/%d.png", i);
			animation->addSpriteFrameWithFile(szName);
		}
		// should last 2.8 seconds. And there are 14 frames.
		animation->setDelayPerUnit(1.0 / 4.0);
		hitanimate = Animate::create(animation);
		sprite->runAction(hitanimate); //StopAllAction
	
}

void EnemyUnit::atkani()
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

	for (int i = 1; i < 6; i++)
	{
		animation->addSpriteFrameWithFileName(StringUtils::format("Unit/Normal/Atk/%d.png", i));
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 5.0);
	atkanimate = Animate::create(animation);
	sprite->runAction(atkanimate); //StopAllAction
}

void EnemyUnit::dieani()
{
	sprite->stopAllActions();


	animation = Animation::create();

	for (int i = 1; i < 4; i++)
	{
		animation->addSpriteFrameWithFileName(StringUtils::format("Unit/Normal/Die/%d.png", i));
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 4.0);
	dieanimate = Animate::create(animation);


	auto fade = FadeOut::create(0.5);
	auto seq = Sequence::create(dieanimate, fade, NULL);
	sprite->runAction(seq); //StopAllAction


}

void EnemyUnit::ex()
{
	auto delay = DelayTime::create(1.4f);
	auto Seq = Sequence::create(delay, CallFunc::create([&] { timer = true; }), NULL);
	sprite->runAction(Seq);
}