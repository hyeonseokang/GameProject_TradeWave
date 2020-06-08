#pragma once
#include "cocos2d.h"

USING_NS_CC;

class UIProgressBar
{
	Sprite* foregroundSprite;
	Sprite* backgroundSprite;
	Layer* ProgressLayer;

public:

	UIProgressBar(Layer* layer);
	void SetPercentage(float fPercent);
	void SetPosition(Vec2 vPos);
	void SetForegroundSprite(Sprite* foreSprite);
	void SetBackgroundSprite(Sprite* backSprite);
	void SetVisible(bool bVisible = true);
	void RunAction(Sequence *seq);
};