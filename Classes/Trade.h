#pragma once
#include  "cocos2d.h"
#include "Item.h"
#include "Sell.h"
#include "TradeUI.h"
#include"Inventory.h"
#include"Buy.h"
USING_NS_CC;

class Trade: public Item
{
public:
	void Tradecreate();// 교역소 생성 함수
	void Tradedelete();// 교역소 삭제 함수


	void Tradeinit(Layer *layer, int Disasternum); //트레이드 메뉴생성
	void MenuTrade(Ref*pSender);

	Inventory *inventory;
	void moveSprite(Vec2 touch);

	LayerColor *Tradelayer;
private:
	// 처음 교역소 메뉴
	Sprite *TradeBG;
	MenuItemImage *CloseButton;
	MenuItemImage *BuyButton;
	MenuItemImage *SellButton;
	Menu * menu;
	// 구매,판매 교역소 메뉴
	TradeUI *TU;
	Buy *buy;
	Sell *sell;
};
