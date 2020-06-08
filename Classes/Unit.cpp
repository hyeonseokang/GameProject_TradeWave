#include "Unit.h"
#include"SimpleAudioEngine.h"
#include"Singleton.h"

void Unit::Create(int _x, int _y, Layer *layer)
{

	sprite->setVisible(true); //트루면 보여줌
	sprite->setPosition(_x, _y);
	sprite->setAnchorPoint(Vec2(0.5f, 0.5f));


	progressBar = new UIProgressBar(layer);
	progressBar->SetPosition(Vec2(_x - 20, _y + 50));
	progressBar->SetBackgroundSprite(Sprite::create("Unit/HPbar1.png"));
	progressBar->SetForegroundSprite(Sprite::create("Unit/HPbar2.png"));
	progressBar->SetPercentage((float)1.0f);
	progressBar->SetVisible(false);

}
void Unit::fight(int updown, int unitnum, int a)  //움직이는거
{

	Spawn* spawn;
	MoveTo *move;
	MoveBy *move2;
	MoveBy *dashmove;
	MoveTo *move3;
	MoveTo *hpmove;
	MoveTo *hpmove2;
	Sequence *DashSeq;
	Sequence *Seq;
	Sequence *HpSeq;
	if (updown == 1)
	{
		abc = 1;
		if (unitnum == 1 || unitnum == 3)
		{
			move = MoveTo::create(sqrt(pow(110, 2) + pow(530 - a, 2)) / 300, Vec2(1090, 560));
			hpmove = MoveTo::create(sqrt(pow(110, 2) + pow(530 - a, 2)) / 300, Vec2(1070, 610));
			move2 = MoveBy::create(4, Vec2(-920, 0));
			int b = RandomHelper::random_int(1, 720);
			move3 = MoveTo::create(sqrt(pow(20, 2) + pow(530 - b, 2)) / 300, Vec2(135, b));
			hpmove2 = MoveTo::create(sqrt(pow(20, 2) + pow(530 - b, 2)) / 300, Vec2(115, b + 50));
		}
		else if(unitnum == 4)
		{
			move = MoveTo::create(sqrt(pow(110, 2) + pow(530 - a, 2)) / 600, Vec2(1090, 540));
			hpmove = MoveTo::create(sqrt(pow(110, 2) + pow(530 - a, 2)) / 600, Vec2(1070, 590));
			move2 = MoveBy::create(2, Vec2(-920, 0));
			int b = RandomHelper::random_int(1, 720);
			move3 = MoveTo::create(sqrt(pow(20, 2) + pow(530 - b, 2)) / 600, Vec2(135, b));
			hpmove2 = MoveTo::create(sqrt(pow(20, 2) + pow(530 - b, 2)) / 600, Vec2(115, b + 50));
		}
		else if (unitnum == 2)
		{
			move = MoveTo::create(sqrt(pow(110, 2) + pow(530 - a, 2)) / 150, Vec2(990, 570));
			hpmove = MoveTo::create(sqrt(pow(110, 2) + pow(530 - a, 2)) / 150, Vec2(990, 630));

			animation = Animation::create();
			Dashanimation = Animation::create();
			for (int i = 1; i < 8; i++)
			{
				char szName[100] = { 0 };
				sprintf(szName, "Unit/BossAnimation/Dash/%d.png", i);
				animation->addSpriteFrameWithFile(szName);
			}
			for (int i = 8; i < 12; i++)
			{
				char szName[100] = { 0 };
				sprintf(szName, "Unit/BossAnimation/Dash/%d.png", i);
				Dashanimation->addSpriteFrameWithFile(szName);
			}
			animation->setDelayPerUnit(1.0 / 7.0);
			Dashanimation->setDelayPerUnit(1.0 / 4.0);

			dashanimate = Animate::create(animation);
			dashanimate2 = Animate::create(Dashanimation);

			move2 = MoveBy::create(1, Vec2(-850, 0));
			dashmove = MoveBy::create(1, Vec2(-800, 0));
			spawn = Spawn::create(dashanimate2, move2, NULL);

			DashSeq = Sequence::create(CallFunc::create([&] {dashtest = true;
			sprite->stopAction(Walk);
			}),
				dashanimate, spawn, CallFunc::create([&] {dashtest = false; walkani(); }), NULL);

			int b = RandomHelper::random_int(1, 720);
			move3 = MoveTo::create(sqrt(pow(20, 2) + pow(530 - b, 2)) / 150, Vec2(80, b));
			hpmove2 = MoveTo::create(sqrt(pow(20, 2) + pow(530 - b, 2)) / 150, Vec2(100, b + 50));
		}
		
	}
	/////////////////////////////////////////////////////////////////////////////////////
	else
	{
		abc = 2;
		if (unitnum == 1 || unitnum == 3)
		{

			move = MoveTo::create(sqrt(pow(110, 2) + pow(210 - a, 2)) / 300, Vec2(1090, 250));
			hpmove = MoveTo::create(sqrt(pow(110, 2) + pow(210 - a, 2)) / 300, Vec2(1070, 300));    //-20 , +50 된 값임
			move2 = MoveBy::create(4, Vec2(-920, 0));
			int b = RandomHelper::random_int(1, 720);
			move3 = MoveTo::create(sqrt(pow(20, 2) + pow(210 - b, 2)) / 300, Vec2(135, b));
			hpmove2 = MoveTo::create(sqrt(pow(20, 2) + pow(210 - b, 2)) / 300, Vec2(115, b + 50));

		}
		else if(unitnum ==4)
		{
			move = MoveTo::create(sqrt(pow(110, 2) + pow(210 - a, 2)) / 600, Vec2(1090, 220));
			hpmove = MoveTo::create(sqrt(pow(110, 2) + pow(210 - a, 2)) / 600, Vec2(1070, 270));
			move2 = MoveBy::create(2, Vec2(-920, 0));
			int b = RandomHelper::random_int(1, 720);
			move3 = MoveTo::create(sqrt(pow(20, 2) + pow(210 - b, 2)) / 600, Vec2(135, b));
			hpmove2 = MoveTo::create(sqrt(pow(20, 2) + pow(210 - b, 2)) / 600, Vec2(115, b + 50));
		}
		else if (unitnum == 2)
		{
			move = MoveTo::create(sqrt(pow(110, 2) + pow(210 - a, 2)) / 150, Vec2(990, 250));
			hpmove = MoveTo::create(sqrt(pow(110, 2) + pow(210 - a, 2)) / 150, Vec2(990, 310));

			animation = Animation::create();
			Dashanimation = Animation::create();
			for (int i = 1; i < 8; i++)
			{
				char szName[100] = { 0 };
				sprintf(szName, "Unit/BossAnimation/Dash/%d.png", i);
				animation->addSpriteFrameWithFile(szName);
			}
			for (int i = 8; i < 12; i++)
			{
				char szName[100] = { 0 };
				sprintf(szName, "Unit/BossAnimation/Dash/%d.png", i);
				Dashanimation->addSpriteFrameWithFile(szName);
			}
			animation->setDelayPerUnit(1.0 / 7.0);
			Dashanimation->setDelayPerUnit(1.0 / 4.0);

			dashanimate = Animate::create(animation);
			dashanimate2 = Animate::create(Dashanimation);

			move2 = MoveBy::create(1, Vec2(-850, 0));
			dashmove = MoveBy::create(1, Vec2(-800, 0));
			spawn = Spawn::create(dashanimate2, move2, NULL);

			DashSeq = Sequence::create(CallFunc::create([&] {dashtest = true;
				sprite->stopAction(Walk);
			}),
				dashanimate, spawn, CallFunc::create([&] {dashtest = false; walkani(); }), NULL);

			int b = RandomHelper::random_int(1, 720);
			move3 = MoveTo::create(sqrt(pow(20, 2) + pow(210 - b, 2)) / 150, Vec2(80, b));
			hpmove2 = MoveTo::create(sqrt(pow(20, 2) + pow(210 - b, 2)) / 150, Vec2(100, b + 50));
		}
	}

	if (unitnum != 2)
	{
		 Seq = Sequence::create(move, move2, move3, CallFunc::create([&] { end = true; }), NULL);
		 HpSeq = Sequence::create(hpmove, move2, hpmove2, NULL);
	}
	else
	{
		auto delay = DelayTime::create(1.1f);
		 Seq = Sequence::create(move, DashSeq, move3, CallFunc::create([&] { end = true; }), NULL);
		 HpSeq = Sequence::create(hpmove,delay, dashmove, hpmove2, NULL);
	}
	

	progressBar->RunAction(HpSeq->clone());  //MoveTo를 써버려서 체력바까지 같이 가버림!!

	sprite->runAction(Seq->clone());
}

void Unit::hpapply(int judge)
{
	auto tintby = TintBy::create(1, -255, 0, -255);
	auto tintby2 = TintBy::create(1, 255,0, 255);
	switch (judge)
	{
	case 1:
		sprite->runAction(tintby);
		break;

	case 2:
		sprite->runAction(tintby2);
		break;
	}
}

void Unit::Destroy()
{
	if(SingleTon::getinstance()->getEFFECT())
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/PriateDead.mp3");
	progressBar->SetVisible(false);
}



int Unit::Gethp()
{
	return hp;
}

void Unit::Sethp(int _hp)
{
	
	hp = _hp;
}

int Unit::Getkahp()
{
	return kahp;
}

void Unit::Setkahp(int _kahp)
{
	kahp = _kahp;
}

bool Unit::Getend()
{
	return end;
}

void Unit::Setend(bool _end)
{

	end = _end;
}

int Unit::Getatk()
{
	return atk;
}

void Unit::Setatk(int _atk)
{
	
	atk = _atk;
}

bool Unit::Gettimer()
{
	return timer;
}

void Unit::Settimer(bool _timer)
{
	timer = _timer;
}



bool Unit::Gethpbuff()
{
	return hpbuff;
}




bool Unit::Gethpboss()
{
	return hpboss;
}

void Unit::Sethpboss(bool _hpboss)
{
	hpboss = _hpboss;
}

int Unit::Getabc()
{
	return abc;
}

