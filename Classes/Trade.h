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
	void Tradecreate();// ������ ���� �Լ�
	void Tradedelete();// ������ ���� �Լ�


	void Tradeinit(Layer *layer, int Disasternum); //Ʈ���̵� �޴�����
	void MenuTrade(Ref*pSender);

	Inventory *inventory;
	void moveSprite(Vec2 touch);

	LayerColor *Tradelayer;
private:
	// ó�� ������ �޴�
	Sprite *TradeBG;
	MenuItemImage *CloseButton;
	MenuItemImage *BuyButton;
	MenuItemImage *SellButton;
	Menu * menu;
	// ����,�Ǹ� ������ �޴�
	TradeUI *TU;
	Buy *buy;
	Sell *sell;
};
