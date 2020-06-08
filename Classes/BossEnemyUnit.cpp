#include "BossEnemyUnit.h"

BossEnemyUnit::BossEnemyUnit(Layer *layer , int red)  //공격력 버프
{
	//sprite = Sprite::create("Unit/BossEnemy_00.png");
	sprite = Sprite::create("Unit/BossAnimation/Walk/1.png");
	sprite->setAnchorPoint(Vec2(1, 0.5f));
	layer->addChild(sprite, 1);
	// 2 3 3 ->4 3 3
	if (red == 1)
	{
		atk = 4;
		hp = 3;
		kahp = 3;

		tower = false;
		end = false;
		timer = true;
		hpbuff = false;
		hpboss = false;
	}

}

void BossEnemyUnit::hpbar(Layer *layer)
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


void BossEnemyUnit::walkani()
{
	if (!dashtest)
	{
		walktest = true;
		if (walktest)
		{
			animation = Animation::create();

			for (int i = 1; i < 5; i++)
			{
				animation->addSpriteFrameWithFileName(StringUtils::format("Unit/BossAnimation/Walk/%d.png", i));
			}
			// should last 2.8 seconds. And there are 14 frames.
			animation->setDelayPerUnit(1.0 / 4.0);
			walkanimate = Animate::create(animation);
			Walk = RepeatForever::create(walkanimate);
			sprite->runAction(Walk); //StopAllAction
		}
	}
}

void BossEnemyUnit::hitani() // 맞았을때
{
	if (!dashtest)
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
			sprintf(szName, "Unit/BossAnimation/Hit/%d.png", i);
			animation->addSpriteFrameWithFile(szName);
		}

		animation->setDelayPerUnit(1.0 / 4.0);
		hitanimate = Animate::create(animation);
		sprite->runAction(hitanimate); //StopAllAction
	}
}

void BossEnemyUnit::atkani()
{
	if (!atktest)
	{
		atktest = true;
	}
	if (walktest)
	{
		sprite->stopAction(Walk);
		walktest = false;
	}

	animation = Animation::create();

	for (int i = 1; i < 6; i++)
	{
		animation->addSpriteFrameWithFileName(StringUtils::format("Unit/BossAnimation/Atk/%d.png", i));
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 4.0);
	atkanimate = Animate::create(animation);
	sprite->runAction(atkanimate); //StopAllAction
}

void BossEnemyUnit::dieani()
{
	sprite->stopAllActions();

	animation = Animation::create();

	for (int i = 1; i < 8; i++)
	{
		animation->addSpriteFrameWithFileName(StringUtils::format("Unit/BossAnimation/Die/%d.png", i));
	}
	// should last 2.8 seconds. And there are 14 frames.
	animation->setDelayPerUnit(1.0 / 8.0);
	dieanimate = Animate::create(animation);

	auto fade = FadeOut::create(0.5);
	auto seq = Sequence::create(dieanimate, fade, NULL);
	sprite->runAction(seq); //StopAllAction

}



void BossEnemyUnit::ex()
{
	auto delay = DelayTime::create(1.0f);
	auto Seq = Sequence::create(delay, CallFunc::create([&] { timer = true; }), NULL);
	sprite->runAction(Seq);
}