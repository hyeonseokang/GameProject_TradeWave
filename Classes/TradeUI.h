#pragma once
#include"cocos2d.h"
USING_NS_CC;
class TradeUI
{
public:
	virtual void Init(Layer *layer,Layer *two,Layer *three,Layer *four,Layer *five, Layer *six);
	Layer *CloseLayer;
	MenuItemImage  *CloseButton;
	Menu *BasicButton;
	void Button(Ref *pSender);

	Sprite *BgChoice; // 카테고리 생성
	Sprite *Category01; // 농산물  
	Sprite *Category02; // 해산물 
	Sprite *Category03; // 보석 
	Sprite *Category04; // 광물 
	Sprite *Category05; // 옷감 

	Menu *CategoryMenu;

	Layer *SelectLayer;
	Layer *FarmingLayer;
	Layer *SeafoodLayer;
	Layer *JewelryLayer;
	Layer *MineralLayer;
	Layer *ClothLayer;
	Sprite *SelectCategory;
	Label *L_Farming; // 라벨 농산물 
	Label *L_Seafood; // 라벨 해산물 
	Label *L_Jewelry; // 라벨 보석 
	Label *L_Mineral; // 라벨 광물 
	Label *L_Cloth; // 라벨 옷감 
	Label *SelectLabel;
	MenuItemSprite *Farming; // 농산물
	MenuItemSprite *Seafood; // 해산물
	MenuItemSprite *Jewelry; // 보석
	MenuItemSprite *Mineral; // 광물
	MenuItemSprite *Cloth; // 옷감
	virtual void ChoiceCategory(Ref *pSender);
};
