#include "TradeUI.h"
#pragma execution_character_set("utf-8")
void TradeUI::Init(Layer *layer, Layer * two, Layer * three, Layer * four, Layer * five, Layer *six)
{
	CloseLayer = layer;
	BgChoice = Sprite::create("Trade/BgTrade1.png"); // 뒷배경
	BgChoice->setPosition(Vec2(640, 360));
	layer->addChild(BgChoice);
	Category01 = Sprite::create("Trade/Category00.png");
	Category02 = Sprite::create("Trade/Category00.png");
	Category03 = Sprite::create("Trade/Category00.png");
	Category04 = Sprite::create("Trade/Category00.png");
	Category05 = Sprite::create("Trade/Category01.png");

	Farming = MenuItemSprite::create(Category01, Category01, CC_CALLBACK_1(
		TradeUI::ChoiceCategory, this)); // 농산물 
	Farming->setPosition(Vec2(440, 660));
	Farming->setTag(2);
	Seafood = MenuItemSprite::create(Category02, Category02, CC_CALLBACK_1(
		TradeUI::ChoiceCategory, this)); // 해산물 
	Seafood->setPosition(Vec2(540, 660));
	Seafood->setTag(3);
	Jewelry = MenuItemSprite::create(Category03, Category03, CC_CALLBACK_1(
		TradeUI::ChoiceCategory, this)); // 보석 
	Jewelry->setPosition(Vec2(840, 660));
	Jewelry->setTag(4);
	Mineral = MenuItemSprite::create(Category04, Category04, CC_CALLBACK_1(
		TradeUI::ChoiceCategory, this)); // 광물 
	Mineral->setPosition(Vec2(740, 660));
	Mineral->setTag(5);
	Cloth = MenuItemSprite::create(Category05, Category05, CC_CALLBACK_1(
		TradeUI::ChoiceCategory, this)); // 옷감 
	Cloth->setPosition(Vec2(640, 660));
	Cloth->setTag(6);

	Farming->setAnchorPoint(Vec2(0.5, 1));
	Seafood->setAnchorPoint(Vec2(0.5, 1));
	Jewelry->setAnchorPoint(Vec2(0.5, 1));
	Mineral->setAnchorPoint(Vec2(0.5, 1));
	Cloth->setAnchorPoint(Vec2(0.5, 1));

	CategoryMenu = Menu::create(Farming, Seafood, Jewelry, Mineral, Cloth,NULL);
	CategoryMenu->setPosition(Vec2::ZERO);
	layer->addChild(CategoryMenu);

	L_Farming = Label::create("농산물", "fonts/JejuGothic-Regular.ttf", 30);
	L_Farming->setPosition(Vec2(440, 630));
	L_Farming->setColor(Color3B::GRAY);
	layer->addChild(L_Farming);
	L_Seafood = Label::create("해산물", "fonts/JejuGothic-Regular.ttf", 30);
	L_Seafood->setPosition(Vec2(540, 630));
	L_Seafood->setColor(Color3B::GRAY);
	layer->addChild(L_Seafood);
	L_Jewelry = Label::create("보석", "fonts/JejuGothic-Regular.ttf", 30);
	L_Jewelry->setPosition(Vec2(840, 630));
	L_Jewelry->setColor(Color3B::GRAY);
	layer->addChild(L_Jewelry);
	L_Mineral = Label::create("광물", "fonts/JejuGothic-Regular.ttf", 30);
	L_Mineral->setPosition(Vec2(740, 630));
	L_Mineral->setColor(Color3B::GRAY);
	layer->addChild(L_Mineral);
	L_Cloth = Label::create("옷감", "fonts/JejuGothic-Regular.ttf", 30);
	L_Cloth->setPosition(Vec2(640, 630));
	L_Cloth->setColor(Color3B::WHITE);
	layer->addChild(L_Cloth);


	CloseButton = MenuItemImage::create("All/CloseButton00.png",
		"All/CloseButton01.png", CC_CALLBACK_1(TradeUI::Button, this));
	CloseButton->setPosition(Vec2(960, 630));
	CloseButton->setTag(1);
	BasicButton = Menu::create(CloseButton, NULL);
	BasicButton->setPosition(Vec2::ZERO);
	layer->addChild(BasicButton);

	FarmingLayer = two;
	SeafoodLayer = three;
	JewelryLayer = four;
	MineralLayer = five;
	ClothLayer = six;
	SelectLayer = ClothLayer;
	SelectCategory = Category05;
	SelectLabel = L_Cloth;
}

void TradeUI::Button(Ref * pSender)
{
	switch (((Node*)pSender)->getTag())
	{
	case 1:
		SelectCategory->setTexture("Trade/Category00.png");
		SelectLayer->setVisible(false);
		SelectCategory = Category05;
		SelectLayer = ClothLayer;
		SelectCategory->setTexture("Trade/Category01.png");
		SelectLayer->setVisible(true);
		CloseLayer->setVisible(false);
		SelectLabel->setColor(Color3B(127, 127, 127));
		SelectLabel = L_Cloth;
		SelectLabel->setColor(Color3B::WHITE);
		break;
	case 2:

		break;
	}
}

void TradeUI::ChoiceCategory(Ref * pSender)
{
	SelectLabel->setColor(Color3B(127, 127, 127));
	SelectCategory->setTexture("Trade/Category00.png");
	SelectLayer->setVisible(false);
	switch (((Node*)pSender)->getTag())
	{
	case 2:
		SelectLabel = L_Farming;
		SelectCategory = Category01;
		SelectLayer = FarmingLayer;
		break;
	case 3:
		SelectLabel = L_Seafood;
		SelectCategory = Category02;
		SelectLayer = SeafoodLayer;
		break;
	case 4:
		SelectLabel = L_Jewelry;
		SelectCategory = Category03;
		SelectLayer = JewelryLayer;
		break;
	case 5:
		SelectLabel = L_Mineral;
		SelectCategory = Category04;
		SelectLayer = MineralLayer;
		break;
	case 6:
		SelectLabel = L_Cloth;
		SelectCategory = Category05;
		SelectLayer = ClothLayer;
		break;
	}
	SelectCategory->setTexture("Trade/Category01.png");
	SelectLayer->setVisible(true);
	SelectLabel->setColor(Color3B::WHITE);
}
