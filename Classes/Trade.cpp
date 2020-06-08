#include "Trade.h"
#pragma execution_character_set("utf-8")
void Trade::Tradecreate()
{
	Tradelayer->setVisible(true);
}

void Trade::Tradedelete()
{
	Tradelayer->setVisible(false);
}

void Trade::Tradeinit(Layer *layer,int Disasternum)
{
	// 트레이드 기본메뉴 
	Tradelayer = LayerColor::create();
	Tradelayer->initWithColor(Color4B(0, 0, 0, 125));
	Tradelayer->setPosition(Vec2::ZERO);
	auto Touch=MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(Trade::MenuTrade, this));
	Touch->setPosition(Vec2(640, 360));
	auto touchmenu = Menu::create(Touch, NULL);
	touchmenu->setPosition(Vec2::ZERO);
	Tradelayer->addChild(touchmenu);
	TradeBG = Sprite::create("Trade/BgTrade.png");
	TradeBG->setPosition(Vec2(640, 360));
	CloseButton = MenuItemImage::create("All/CloseButton00.png",
		"All/CloseButton01.png", CC_CALLBACK_1(Trade::MenuTrade, this));
	CloseButton->setPosition(Vec2(960, 630));
	CloseButton->setTag(1);
	BuyButton = MenuItemImage::create("Trade/BuyTrade00.png",
		"Trade/BuyTrade01.png", CC_CALLBACK_1(Trade::MenuTrade, this));
	BuyButton->setPosition(Vec2(640, 320));
	BuyButton->setTag(2);
	SellButton = MenuItemImage::create("Trade/SellTrade00.png",
		"Trade/SellTrade01.png", CC_CALLBACK_1(Trade::MenuTrade, this));
	SellButton->setPosition(Vec2(640, 190));
	SellButton->setTag(3);
	menu = Menu::create(CloseButton, BuyButton, SellButton, NULL);
	menu->setPosition(Vec2::ZERO); 


	Tradelayer->addChild(TradeBG);
	Tradelayer->addChild(menu);
	layer->addChild(Tradelayer,5);

	PriceInit();
	setDisaster(Disasternum);

	inventory = new Inventory;
	inventory->InventoryInit(layer, HaveMaterial);
	//트레이드 구매판매 메뉴
	buy = new Buy;
	buy->TradeInit(Tradelayer, BasePrice,HaveMaterial,&money,inventory);
	buy->TradeLayer->setVisible(false);
	sell = new Sell;
	sell->TradeInit(Tradelayer, BasePrice, HaveMaterial, &money, inventory);
	sell->TradeLayer->setVisible(false);
	//sell = new Sell;
	//sell->SellInit(Tradelayer, BasePrice, HaveMaterial, &money);

}

void Trade::MenuTrade(Ref * pSender)
{
	switch (((Node*)pSender)->getTag())
	{
	case 1:
		Tradelayer->setVisible(false);
		break;
	case 2:
		buy->TradeLayer->setVisible(true);
		break;
	case 3:
		for (int a = 0; a < 24; a++)
		{
			if (a >= 4)
				sell->LabelHMaterial[a]->setString(StringUtils::format("%d개 보유", sell->hprice[a]));
		}
		sell->TradeLayer->setVisible(true);
		break;
	}
}

void Trade::moveSprite(Vec2 touch)
{
	log("%f     %f", touch.x, touch.y);
}
