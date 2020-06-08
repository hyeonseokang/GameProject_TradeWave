#include "Slider.h"

UIProgressBar::UIProgressBar(Layer* layer)
{
	ProgressLayer = Layer::create();
	ProgressLayer->setAnchorPoint(Vec2(0.0f, 0.5f));
	ProgressLayer->setPosition(Vec2(1000, 360));
	//ProgressLayer->setScaleY(2.0f);
	ProgressLayer->setScaleX(1.0f);
	SetVisible(true);
	layer->addChild(ProgressLayer, 9);
}

//!< 0.0f~1.0f
void UIProgressBar::SetPercentage(float fPercent)
{
	foregroundSprite->setScaleX(fPercent);
}

void UIProgressBar::SetPosition(Vec2 vPos)
{
	ProgressLayer->setPosition(vPos);
}

void UIProgressBar::SetForegroundSprite(Sprite* foreSprite)
{
	foregroundSprite = foreSprite;
	foregroundSprite->setAnchorPoint(Vec2(0.0f, 0.5f));
	ProgressLayer->addChild(foregroundSprite);
	SetPercentage(1.0f);
}

void UIProgressBar::SetBackgroundSprite(Sprite* backSprite)
{
	backgroundSprite = backSprite;
	backgroundSprite->setAnchorPoint(Vec2(0.0f, 0.5f));
	ProgressLayer->addChild(backgroundSprite);
}

void UIProgressBar::SetVisible(bool bVisible)
{
	ProgressLayer->setVisible(bVisible);
}

void UIProgressBar::RunAction(Sequence *seq)
{
	ProgressLayer->runAction(seq);
}