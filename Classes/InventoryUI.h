#pragma once
#include "TradeUI.h"
class InventoryUI :public TradeUI
{
public:
	void Init(Layer *layer, Layer *two, Layer *three, Layer *four, Layer *five, Layer *six,Label *_label[3],Sprite *sprite);
	void ChoiceCategory(Ref *pSender);
	Sprite * ChoiceSpr;
	Label *label[3];
};
