#include "Tower.h"

Tower::Tower(Layer *layer)
{
	hp = UserDefault::getInstance()->getIntegerForKey("NSHIPHP");
	kahp = 90 + UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 10;
	sprite = Sprite::create("Combat/Tower.png");
	sprite->setPosition(50, 360);
	layer->addChild(sprite, 1);

	progressBar = new UIProgressBar(layer);
	progressBar->SetPosition(Vec2(20, 220));
	progressBar->SetBackgroundSprite(Sprite::create("Unit/HPbar1.png"));
	progressBar->SetForegroundSprite(Sprite::create("Unit/HPbar2.png"));
	progressBar->SetPercentage((float)hp / kahp);
	progressBar->SetVisible(true);

	tower = true;
}

void Tower::Brr()
{
	auto move = MoveBy::create(0.1f, Vec2(-10, 0));
	auto move2 = MoveBy::create(0.1f, Vec2(10, 0));
	auto Seq = Sequence::create(move, move2, NULL);
	sprite->runAction(Seq);
}