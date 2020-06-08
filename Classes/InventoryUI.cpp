#include "InventoryUI.h"
#pragma execution_character_set("utf-8")

void InventoryUI::Init(Layer * layer, Layer * two, Layer * three, Layer * four, Layer * five, Layer * six, Label *_label[3], Sprite *sprite)
{
	ChoiceSpr = sprite;
	label[0] = _label[0];
	label[1] = _label[1];
	label[2] = _label[2];
	TradeUI::Init(layer, two, three, four, five, six);

	
}

void InventoryUI::ChoiceCategory(Ref * pSender)
{
	SelectLabel->setColor(Color3B(127, 127, 127));
	SelectCategory->setTexture("Trade/Category00.png");
	Farming->setAnchorPoint(Vec2(0.5, 1));
	SelectLayer->setVisible(false);
	switch (((Node*)pSender)->getTag())
	{
	case 2:
		label[0]->setString("쌀");
		label[1]->setString("아시아, 인도 지역에서 집중적으로 생산되는 농산물이다.\n비 유럽 지역들의 주식이다. ");
		label[2]->setString("한 섬당 가격: 200$");
		SelectLabel = L_Farming;
		SelectCategory = Category01;
		SelectLayer = FarmingLayer;
		break;
	case 3:
		label[0]->setString("조개");
		label[1]->setString("해양지역에서 생산되는 해산물이다.\n각종 요리에 메인 재료, 고명 등으로 활용된다.");
		label[2]->setString("한 상자당 가격: 400$");
		SelectLabel = L_Seafood;
		SelectCategory = Category02;
		SelectLayer = SeafoodLayer;
		break;
	case 4:
		label[0]->setString("다이아몬드");
		label[1]->setString("아프리카 지역에서 주로 생산되는 보석이다.\n가장 대표적인 보석으로 부의 상징이 되기도 한다.");
		label[2]->setString("1개당 가격: 8000$");
		SelectLabel = L_Jewelry;
		SelectCategory = Category03;
		SelectLayer = JewelryLayer;
		break;
	case 5:
		label[0]->setString("철");
		label[1]->setString("아메리카, 유럽 지역에서 많이 생산되는 금속이다.\n가공이 쉬워 여러 물건을 만드는데 사용된다.");
		label[2]->setString("1kg당 가격: 300$");
		SelectLabel = L_Mineral;
		SelectCategory = Category04;
		SelectLayer = MineralLayer;
		break;
	case 6:
		label[0]->setString("가죽");
		label[1]->setString("다양한 지역에서 생산하는 옷감이다.\n동물의 껍질이며 가공 기술이 부족해동 사용할 수 있다.");
		label[2]->setString("1필당 가격: 500$");
		SelectLabel = L_Cloth;
		SelectCategory = Category05;
		SelectLayer = ClothLayer;
		break;
	}
	SelectLabel->setColor(Color3B::WHITE);
	ChoiceSpr->setPosition(Vec2(420, 475));
	SelectCategory->setTexture("Trade/Category01.png");
	SelectLayer->setVisible(true);
}
