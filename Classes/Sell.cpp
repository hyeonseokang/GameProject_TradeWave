#include "Sell.h"
#include "ScrollMenu.h"
#include"SimpleAudioEngine.h"
#pragma execution_character_set("utf-8")
void Sell::TradeInit(LayerColor * layer, int * price, int * have, int * Money, Inventory *_in)
{
	inven = _in;
	money = Money; //돈 저장 
	bprice = price; // 시세 저장
	hprice = have;  //  가지고있는 갯수 저장

	TradeLayer = LayerColor::create();
	TradeLayer->initWithColor(Color4B(0, 0, 0, 125));
	layer->addChild(TradeLayer);
	auto Touch = MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(Sell::Final, this));
	Touch->setPosition(Vec2(640, 360));
	auto touchmenu = Menu::create(Touch, NULL);
	touchmenu->setPosition(Vec2::ZERO);
	TradeLayer->addChild(touchmenu);

	ScrollLayer = LayerColor::create(Color4B(35, 255, 23, 0), 600, 620);
	FarmingMaterial = LayerColor::create(Color4B(35, 36, 23, 0), 600, 500); // 농산물 재료 표시 레이어
	ScrollLayer->addChild(FarmingMaterial);
	FarmingMaterial->setVisible(false);
	SeafoodMaterial = LayerColor::create(Color4B(35, 36, 23, 0), 600, 500); // 해산물 재료 표시 레이어
	ScrollLayer->addChild(SeafoodMaterial);
	SeafoodMaterial->setVisible(false);
	JewelryMaterial = LayerColor::create(Color4B(35, 36, 23, 0), 600, 500); // 보석 재료 표시 레이어
	ScrollLayer->addChild(JewelryMaterial);
	JewelryMaterial->setVisible(false);
	MineralMaterial = LayerColor::create(Color4B(35, 36, 23, 0), 600, 500); // 광물 재료 표시 레이어
	ScrollLayer->addChild(MineralMaterial);
	MineralMaterial->setVisible(false);
	ClothMaterial = LayerColor::create(Color4B(35, 36, 23, 0), 600, 500); // 옷감 재료 표시 레이어
	ScrollLayer->addChild(ClothMaterial);
	ClothMaterial->setVisible(true);
	
	///시크릿 교역품////
	if (UserDefault::getInstance()->getIntegerForKey("HCEMETERY") > 0)
		secret = 1;
	if (UserDefault::getInstance()->getIntegerForKey("HCINTAMANI") > 0)
		secret = 2;
	if (UserDefault::getInstance()->getIntegerForKey("HWRISTBAND") > 0)
		secret = 3;
	if (secret == 1)
	{
		secretbool = true;
		secretmoney = 120000;
		havesecret = UserDefault::getInstance()->getIntegerForKey("HCEMETERY");
		SecretButton = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		SecretButton->setPosition(Vec2(300, 440 - 4 * 125 + 125));
		SecretButton->setTag(30);
		SecretMenu = ScrollMenu::create(SecretButton, NULL);
		SecretMenu->setPosition(Vec2::ZERO);
		SecretTruck = Sprite::create("Trade/ItemImage00.png");
		SecretTruck->setPosition(Vec2(100, -60 + 125));


		ScrollLayer->addChild(SecretMenu);
		ScrollLayer->addChild(SecretTruck);
		Material = Sprite::create("truck/secret/cemetery.png");
		Material->setScale(0.25);
		Material->setPosition(Vec2(100, -60 + 125));
		SecretName = Label::create("묘비", "fonts/JejuGothic-Regular.ttf", 30);
		SecretName->setPosition(Vec2(230, -40 + 125));
		SecretName->setColor(Color3B(0, 0, 0));
		SecretPrice = Label::create("$120000", "fonts/JejuGothic-Regular.ttf", 30);
		SecretPrice->setPosition(Vec2(340, 405 - 500 + 125));			
		SecretPrice->setColor(Color3B(0, 0, 0));
		ScrollLayer->addChild(Material);
		ScrollLayer->addChild(SecretName);
		ScrollLayer->addChild(SecretPrice);
	}
	else if (secret == 2)
	{
		secretbool = true;
		secretmoney = 90000;
		havesecret = UserDefault::getInstance()->getIntegerForKey("HCINTAMANI");
		SecretButton = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		SecretButton->setPosition(Vec2(300, 440 - 4 * 125 + 125));
		SecretButton->setTag(30);
		SecretMenu = ScrollMenu::create(SecretButton, NULL);
		SecretMenu->setPosition(Vec2::ZERO);
		SecretTruck = Sprite::create("Trade/ItemImage00.png");
		SecretTruck->setPosition(Vec2(100, -60 + 125));


		ScrollLayer->addChild(SecretMenu);
		ScrollLayer->addChild(SecretTruck);
		Material = Sprite::create("truck/secret/cintamani.png");
		Material->setScale(0.25);
		Material->setPosition(Vec2(100, -60 + 125));
		SecretName = Label::create("여의주", "fonts/JejuGothic-Regular.ttf", 30);
		SecretName->setPosition(Vec2(230, -40 + 125));
		SecretName->setColor(Color3B(0, 0, 0));
		SecretPrice = Label::create("$90000", "fonts/JejuGothic-Regular.ttf", 30);
		SecretPrice->setPosition(Vec2(340, 405 - 500 + 125));
		SecretPrice->setColor(Color3B(0, 0, 0));
		ScrollLayer->addChild(Material);
		ScrollLayer->addChild(SecretName);
		ScrollLayer->addChild(SecretPrice);
	}
	else if (secret == 3)
	{
		secretbool = true;
		secretmoney = 150000;
		havesecret = UserDefault::getInstance()->getIntegerForKey("HWRISTBAND");
		SecretButton = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		SecretButton->setPosition(Vec2(300, 440 - 4 * 125 + 125));
		SecretButton->setTag(30);
		SecretMenu = ScrollMenu::create(SecretButton, NULL);
		SecretMenu->setPosition(Vec2::ZERO);
		SecretTruck = Sprite::create("Trade/ItemImage00.png");
		SecretTruck->setPosition(Vec2(100, -60 + 125));


		ScrollLayer->addChild(SecretMenu);
		ScrollLayer->addChild(SecretTruck);
		Material = Sprite::create("truck/secret/wristband.png");
		Material->setScale(0.25);
		Material->setPosition(Vec2(100, -60 + 125));
		SecretName = Label::create("팔찌", "fonts/JejuGothic-Regular.ttf", 30);
		SecretName->setPosition(Vec2(230, -40 + 125));
		SecretName->setColor(Color3B(0, 0, 0));
		SecretPrice = Label::create("$150000", "fonts/JejuGothic-Regular.ttf", 30);
		SecretPrice->setPosition(Vec2(340, 405 - 500 + 125));
		SecretPrice->setColor(Color3B(0, 0, 0));
		ScrollLayer->addChild(Material);
		ScrollLayer->addChild(SecretName);
		ScrollLayer->addChild(SecretPrice);
	}
	else
	{
		ADDVec2 = 0;
		ScrollLayer->setContentSize(Size(600, 500));
	}
	for (int a = 4; a < 24; a++)
	{
		loadPriceUD[a] = Sprite::create("Trade/down.png");
		if (a < 8)
		{
			loadPriceUD[a]->setPosition(Vec2(330, 415 - (a - 4) * 125 + ADDVec2));
			FarmingMaterial->addChild(loadPriceUD[a], 200);
		}
		else if (a < 12)
		{
			loadPriceUD[a]->setPosition(Vec2(330, 415 - (a - 8) * 125 + ADDVec2));
			SeafoodMaterial->addChild(loadPriceUD[a], 200);
		}
		else if (a < 16)
		{
			loadPriceUD[a]->setPosition(Vec2(330, 415 - (a - 12) * 125 + ADDVec2));
			JewelryMaterial->addChild(loadPriceUD[a], 200);
		}
		else if (a < 20)
		{
			loadPriceUD[a]->setPosition(Vec2(330, 415 - (a - 16) * 125 + ADDVec2));
			MineralMaterial->addChild(loadPriceUD[a], 200);
		}
		else if (a < 24)
		{
			loadPriceUD[a]->setPosition(Vec2(330, 415 - (a - 20) * 125 + ADDVec2));
			ClothMaterial->addChild(loadPriceUD[a], 200);
		}
	}
	Setloadprice();
	////////////
	FarmingMenu(FarmingMaterial);
	SeafoodMenu(SeafoodMaterial);
	JewelryMenu(JewelryMaterial);
	MineralMenu(MineralMaterial);
	ClothMenu(ClothMaterial);

	Init(TradeLayer, FarmingMaterial, SeafoodMaterial,
		JewelryMaterial, MineralMaterial, ClothMaterial);

	scrollview = ScrollView::create(Size(600, 450), ScrollLayer);
	TradeLayer->addChild(scrollview);
	scrollview->setPosition(Vec2(640 - 300, 360 - 260));
	scrollview->setDirection(ScrollView::Direction::VERTICAL);
	scrollview->setBounceable(true);
	scrollview->setContentOffset(Vec2(0, -75));

	FinalLayer = LayerColor::create(Color4B(0,0,0,125));//최종 구매 레이어 
	FinalLayer->setPosition(Vec2::ZERO);
	TradeLayer->addChild(FinalLayer);
	auto Touch2 = MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(Sell::Final, this));
	Touch2->setPosition(Vec2(640, 360));
	auto touchmenu2 = Menu::create(Touch2, NULL);
	touchmenu2->setPosition(Vec2::ZERO);
	FinalLayer->addChild(touchmenu2);


	BgFinal = Sprite::create("Trade/BgTrade1.png");//구매 큰 팝업
	BgFinal->setPosition(Vec2(640, 360));
	FinalLayer->addChild(BgFinal);
	FinalClose = MenuItemImage::create("All/CloseButton00.png", "All/CloseButton01.png", CC_CALLBACK_1(Sell::Final, this));
	FinalClose->setPosition(Vec2(990, 640));
	FinalClose->setTag(1);

	CountSprite = Sprite::create("Trade/Sell/Count.png");
	CountSprite->setScale(1.5);
	CountSprite->setPosition(Vec2(640, 313));
	FinalLayer->addChild(CountSprite);
	Photo = Sprite::create("Trade/Buy/ItemImage01.png");
	Photo->setPosition(Vec2(640, 460));
	Photo->setScale(1.5);
	FinalLayer->addChild(Photo);
	FinalMaterial = Sprite::create("CloseNormal.png");
	FinalMaterial->setPosition(Vec2(640, 460));
	FinalMaterial->setScale(0.3);
	FinalLayer->addChild(FinalMaterial);
	MAXbar = Sprite::create("ShipMove/Hpbar01.png");
	MAXbar->setAnchorPoint(Vec2(0, 0.5));
	MAXbar->setPosition(Vec2(342, 130));
	MAXbar->setScaleX(((float)UserDefault::getInstance()->getIntegerForKey("HMAX") / UserDefault::getInstance()->getIntegerForKey("MAX")));
	FinalLayer->addChild(MAXbar);
	Next = MenuItemImage::create("Trade/Buy/arrow00.png", "Trade/Buy/arrow01.png", CC_CALLBACK_1(Sell::Final, this));
	Next->setPosition(Vec2(850, 313));
	Next->setScale(1.5);
	Next->setTag(2);
	Back = MenuItemImage::create("Trade/Buy/arrow00.png", "Trade/Buy/arrow01.png", CC_CALLBACK_1(Sell::Final, this));
	Back->setPosition(Vec2(430, 313));
	Back->setRotationY(180);
	Back->setScale(1.5);
	Back->setTag(3);
	BSbutton = MenuItemImage::create("Trade/Sell/SellButton00.png", "Trade/Sell/BuyButton01.png", CC_CALLBACK_1(Sell::Final, this));
	BSbutton->setPosition(Vec2(720, 205));
	BSbutton->setScale(1.5);
	BSbutton->setTag(4);
	FinalMenu = Menu::create(FinalClose, Next, Back, BSbutton, NULL);
	FinalMenu->setPosition(Vec2::ZERO);
	FinalLayer->addChild(FinalMenu);
	MaterialLabel = Label::create("현서를 구매하시겠습니까?", "fonts/JejuGothic-Regular.ttf", 45);
	MaterialLabel->setColor(Color3B(255, 255, 255));
	MaterialLabel->setPosition(Vec2(640, 575));
	FinalLayer->addChild(MaterialLabel);
	CountLabel = Label::create(StringUtils::format // 갯수 표현
	("판매수량 / 최대수량", Count), "fonts/JejuGothic-Regular.ttf", 45);
	CountLabel->setColor(Color3B(255, 255, 255));
	CountLabel->setPosition(Vec2(640, 295));
	FinalLayer->addChild(CountLabel);
	MoneyCountLabel = Label::create(StringUtils::format //돈 표현 
	("%d $", 1000), "fonts/JejuGothic-Regular.ttf", 45);
	MoneyCountLabel->setColor(Color3B(255, 255, 255));
	MoneyCountLabel->setPosition(Vec2(550, 205));
	FinalLayer->addChild(MoneyCountLabel);
	FinalLayer->setVisible(false);
}

void Sell::FinalBS(int _Material, int _Count)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("BGM/trade_upgrade.mp3");
	if (secretChoice == 0)
	{
		UserDefault::getInstance()->setIntegerForKey("HMAX", UserDefault::getInstance()->getIntegerForKey("HMAX") - _Count);
		UserDefault::getInstance()->setIntegerForKey("MONEY", *money + bprice[_Material] * _Count);
		*money = *money + bprice[_Material] * _Count;
		hprice[_Material] -= _Count;
		LabelHMaterial[_Material]->setString(StringUtils::format("%d개 보유", hprice[_Material]));
		switch (_Material)
		{
		case 0:
			UserDefault::getInstance()->setIntegerForKey("HPEPPER", hprice[_Material]);
			break;
		case 1:
			UserDefault::getInstance()->setIntegerForKey("HGARLIC", hprice[_Material]);
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("HSUGAR", hprice[_Material]);
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("HCINNAMON", hprice[_Material]);
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("HRICE", hprice[_Material]);
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("HONION", hprice[_Material]);
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("HWHEAT", hprice[_Material]);
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("HWONION", hprice[_Material]);
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("HSHELLFISH", hprice[_Material]);
			break;
		case 9:
			UserDefault::getInstance()->setIntegerForKey("HFISH", hprice[_Material]);
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("HLOBSTER", hprice[_Material]);
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("HSQUID", hprice[_Material]);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("HDIAMOND", hprice[_Material]);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("HRUBY", hprice[_Material]);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("HPERIDOT", hprice[_Material]);
			break;
		case 15:
			UserDefault::getInstance()->setIntegerForKey("HPEARL", hprice[_Material]);
			break;
		case 16:
			UserDefault::getInstance()->setIntegerForKey("HIRON", hprice[_Material]);
			break;
		case 17:
			UserDefault::getInstance()->setIntegerForKey("HGOLD", hprice[_Material]);
			break;
		case 18:
			UserDefault::getInstance()->setIntegerForKey("HSILVER", hprice[_Material]);
			break;
		case 19:
			UserDefault::getInstance()->setIntegerForKey("HCOPPER", hprice[_Material]);
			break;
		case 20:
			UserDefault::getInstance()->setIntegerForKey("HLEATHER", hprice[_Material]);
			break;
		case 21:
			UserDefault::getInstance()->setIntegerForKey("HSILK", hprice[_Material]);
			break;
		case 22:
			UserDefault::getInstance()->setIntegerForKey("HNOODLE", hprice[_Material]);
			break;
		case 23:
			UserDefault::getInstance()->setIntegerForKey("HLINEN", hprice[_Material]);
			break;
		}
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("MONEY", *money + secretmoney * _Count);
		*money = *money + secretmoney * _Count;
		havesecret -= _Count;
		LabelHMaterial[_Material]->setString(StringUtils::format("%d개 보유", havesecret));
		if (_Material == 29)
		{
			if (secret == 1)
				UserDefault::getInstance()->setIntegerForKey("HCEMETERY", havesecret);
			if (secret == 2)
				UserDefault::getInstance()->setIntegerForKey("HCINTAMANI", havesecret);
			if (secret == 3)
				UserDefault::getInstance()->setIntegerForKey("HWRISTBAND", havesecret);
		}
	}
	FinalLayer->setVisible(false);
	inven->ChangeLabel(_Material);
}

void Sell::Final(Ref * pSender)
{
	switch (((Node*)pSender)->getTag())
	{
	case 1:
		FinalLayer->setVisible(false);
		break;
	case 2:
		if (secretChoice == 0)
		{if (hprice[Materialcount] >= Count + 1)
			{
				Count++;
				MAXbar->setScaleX(((float)(UserDefault::getInstance()->getIntegerForKey("HMAX") - Count) / UserDefault::getInstance()->getIntegerForKey("MAX")));//적재량표시
			}
		}
		else
		{
			if (havesecret >= Count + 1)
			{
				Count++;
			}
		}
		break;
	case 3:
		if (Count != 0)
		{
			Count--;
			if (secretChoice == 0)
				MAXbar->setScaleX(((float)(UserDefault::getInstance()->getIntegerForKey("HMAX") - Count) / 50));//적재량표시
		}

		break;
	case 4:
		FinalBS(Materialcount, Count);
	}
	if (secretChoice == 0)
	{
		CountLabel->setString(StringUtils::format("%d/%d", Count, hprice[Materialcount]));
		MoneyCountLabel->setString(StringUtils::format("$ %d", Count*bprice[Materialcount]));
	}
	else
	{
		CountLabel->setString(StringUtils::format("%d/%d", Count, havesecret));
		MoneyCountLabel->setString(StringUtils::format("$ %d", Count*secretmoney));
	}
}

void Sell::MaterialMenu(Ref * pSender)
{
	secretChoice = 0;
	char *name;
	switch (((Node*)pSender)->getTag())
	{
	case 1:
		name = "'후추'를";
		break;
	case 2:
		name = "'마늘'을";
		break;
	case 3:
		name = "'설탕'을";
		break;
	case 4:
		name = "'시나몬'을";
		break;
	case 5:
		FinalMaterial->setTexture("truck/agricultural/rice.png");
		name = "'쌀'을";
		break;
	case 6:
		FinalMaterial->setTexture("truck/agricultural/Potato.png");
		name = "'감자'를";
		break;
	case 7:
		FinalMaterial->setTexture("truck/agricultural/wheat.png");
		name = "'밀'을";
		break;
	case 8:
		FinalMaterial->setTexture("truck/agricultural/S_onion.png");
		name = "'파'를";
		break;
	case 9:
		FinalMaterial->setTexture("truck/seafood/clam.png");
		name = "'조개'를";
		break;
	case 10:
		FinalMaterial->setTexture("truck/seafood/fish.png");
		name = "'생선'을";
		break;
	case 11:
		FinalMaterial->setTexture("truck/seafood/lobster.png");
		name = "'바닷가재'을";
		break;
	case 12:
		FinalMaterial->setTexture("truck/seafood/squid.png");
		name = "'오징어'를";
		break;
	case 13:
		FinalMaterial->setTexture("truck/jewel/diamond.png");
		name = "'다이아몬드'를";
		break;
	case 14:
		FinalMaterial->setTexture("truck/jewel/ruby.png");
		name = "'루비'를";
		break;
	case 15:
		FinalMaterial->setTexture("truck/jewel/emerald.png");
		name = "'에메랄드'를";
		break;
	case 16:
		FinalMaterial->setTexture("truck/jewel/pearl.png");
		name = "'진주'를";
		break;
	case 17:
		FinalMaterial->setTexture("truck/mineral/iron.png");
		name = "'철'을";
		break;
	case 18:
		FinalMaterial->setTexture("truck/mineral/gold.png");
		name = "'금'을";
		break;
	case 19:
		FinalMaterial->setTexture("truck/mineral/silver.png");
		name = "'은'을";
		break;
	case 20:
		FinalMaterial->setTexture("truck/mineral/copper.png");
		name = "'구리'를";
		break;
	case 21:
		FinalMaterial->setTexture("truck/cloth/skin.png");
		name = "'가죽'을";
		break;
	case 22:
		FinalMaterial->setTexture("truck/cloth/silk.png");
		name = "'비단'을";
		break;
	case 23:
		FinalMaterial->setTexture("truck/cloth/cloth.png");
		name = "'면'을";
		break;
	case 24:
		FinalMaterial->setTexture("truck/cloth/linen.png");
		name = "'라넨'을";
		break;
	case 30:
		if (secret == 1)
		{
			FinalMaterial->setTexture("truck/secret/cemetery.png");
			secretChoice = 1;
			name = "'묘비'를";
		}
		if (secret == 2)
		{
			FinalMaterial->setTexture("truck/secret/cintamani.png");
			secretChoice = 1;
			name = "'여의주'를";
		}
		if (secret == 3)
		{
			FinalMaterial->setTexture("truck/secret/wristband.png");
			secretChoice = 1;
			name = "'팔찌'를";
		}
		break;
	}
	MAXbar->setScaleX(((float)UserDefault::getInstance()->getIntegerForKey("HMAX") / UserDefault::getInstance()->getIntegerForKey("MAX")));
	Count = 0;
	Materialcount = (((Node*)pSender)->getTag() - 1);
	MaterialLabel->setString(StringUtils::format("%s 판매하시겠습니까?", name));
	if(secretChoice == 0)
		CountLabel->setString(StringUtils::format("0/%d",hprice[Materialcount]));
	else
	{
		CountLabel->setString(StringUtils::format("0/%d", 
			havesecret));
	}
	MoneyCountLabel->setString("$ 0");
	FinalLayer->setVisible(true);
}

void Sell::FarmingMenu(LayerColor *layer)
{
	for (int a = 0; a < 4; a++)
	{
		MaterialButton[a + 4] = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		MaterialButton[a + 4]->setPosition(Vec2(300, 440 - a * 125 + ADDVec2));
		MaterialButton[a + 4]->setTag(a + 5);
	}
	FarmingBmenu = ScrollMenu::create(MaterialButton[4], MaterialButton[5], MaterialButton[6], MaterialButton[7], NULL);
	FarmingBmenu->setPosition(Vec2::ZERO);
	layer->addChild(FarmingBmenu);
	PhotoTruck[4] = Sprite::create("truck/agricultural/rice.png");
	PhotoTruck[4]->setPosition(Vec2(100, 440 + ADDVec2));
	PhotoTruck[4]->setScale(0.25);
	layer->addChild(PhotoTruck[4], 2);
	PhotoTruck[5] = Sprite::create("truck/agricultural/Potato.png");
	PhotoTruck[5]->setPosition(Vec2(100, 315 + ADDVec2));
	PhotoTruck[5]->setScale(0.25);
	layer->addChild(PhotoTruck[5], 2);
	PhotoTruck[6] = Sprite::create("truck/agricultural/wheat.png");
	PhotoTruck[6]->setPosition(Vec2(100, 190 + ADDVec2));
	PhotoTruck[6]->setScale(0.25);
	layer->addChild(PhotoTruck[6], 2);
	PhotoTruck[7] = Sprite::create("truck/agricultural/S_onion.png");
	PhotoTruck[7]->setPosition(Vec2(100, 65 + ADDVec2));
	PhotoTruck[7]->setScale(0.25);
	layer->addChild(PhotoTruck[7], 2);
	for (int a = 0; a < 4; a++)
	{
		PhotoMaterial[a + 4] = Sprite::create("Trade/ItemImage00.png");
		PhotoMaterial[a + 4]->setPosition(Vec2(100, 440 - a * 125 + ADDVec2));
		layer->addChild(PhotoMaterial[a + 4], 1);
	}
	for (int a = 0+4; a < 4; a++)
	{
		PriceMaterial[a+4] = Label::create(StringUtils::format("$ %d", bprice[a+4]), "fonts/JejuGothic-Regular.ttf", 30);
		//PriceMaterial[a]->setPosition(Vec2(340, 405-a*125 + ADDVec2));
		PriceMaterial[a+4]->setPosition(Vec2(390, 470 - a * 125 + ADDVec2));
		PriceMaterial[a+4]->setColor(Color3B(0, 0, 0));
		layer->addChild(PriceMaterial[a+4], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LloadPrice[a+4] = Label::create(StringUtils::format("%.1f％", loadPrice[a+4]), "fonts/JejuGothic-Regular.ttf", 30);
		LloadPrice[a+4]->setPosition(Vec2(400, 410 - a * 125 + ADDVec2));
		LloadPrice[a+4]->setColor(Color3B(0, 0, 0));
		layer->addChild(LloadPrice[a+4], 1);
	}
	LabelMaterial[4] = Label::create("쌀", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[4]->setPosition(Vec2(230, 470 + ADDVec2));
	LabelMaterial[4]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[4], 1);
	LabelMaterial[5] = Label::create("감자", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[5]->setPosition(Vec2(230, 345 + ADDVec2));
	LabelMaterial[5]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[5], 1);
	LabelMaterial[6] = Label::create("밀", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[6]->setPosition(Vec2(230, 220 + ADDVec2));
	LabelMaterial[6]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[6], 1);
	LabelMaterial[7] = Label::create("파", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[7]->setPosition(Vec2(230, 95 + ADDVec2));
	LabelMaterial[7]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[7], 1);

	for (int a = 0; a < 4; a++)
	{
		LabelHMaterial[a + 4] = Label::create(StringUtils::format("%d개 보유", hprice[a+4]), "fonts/JejuGothic-Regular.ttf", 30);
		LabelHMaterial[a + 4]->setPosition(Vec2(230, 410 - a * 125 + ADDVec2));
		LabelHMaterial[a + 4]->setColor(Color3B(0, 0, 0));
		layer->addChild(LabelHMaterial[a + 4], 1);
	}
}

void Sell::SeafoodMenu(LayerColor *layer)
{
	for (int a = 0; a < 4; a++)
	{
		MaterialButton[a + 8] = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		MaterialButton[a + 8]->setPosition(Vec2(300, 440 - a * 125 + ADDVec2));
		MaterialButton[a + 8]->setTag(a + 9);
	}
	SeafoodBmenu = ScrollMenu::create(MaterialButton[8], MaterialButton[9], MaterialButton[10], MaterialButton[11], NULL);
	SeafoodBmenu->setPosition(Vec2::ZERO);
	layer->addChild(SeafoodBmenu);
	///////// 사진 들/////////////
	PhotoTruck[8] = Sprite::create("truck/seafood/clam.png");
	PhotoTruck[8]->setPosition(Vec2(100, 440 + ADDVec2));
	PhotoTruck[8]->setScale(0.25);
	layer->addChild(PhotoTruck[8], 2);
	PhotoTruck[9] = Sprite::create("truck/seafood/fish.png");
	PhotoTruck[9]->setPosition(Vec2(100, 315 + ADDVec2));
	PhotoTruck[9]->setScale(0.25);
	layer->addChild(PhotoTruck[9], 2);
	PhotoTruck[10] = Sprite::create("truck/seafood/lobster.png");
	PhotoTruck[10]->setPosition(Vec2(100, 190 + ADDVec2));
	PhotoTruck[10]->setScale(0.25);
	layer->addChild(PhotoTruck[10], 2);
	PhotoTruck[11] = Sprite::create("truck/seafood/squid.png");
	PhotoTruck[11]->setPosition(Vec2(100, 65 + ADDVec2));
	PhotoTruck[11]->setScale(0.25);
	layer->addChild(PhotoTruck[11], 2);
	//////////////////////////////
	for (int a = 0; a < 4; a++)
	{
		PhotoMaterial[a + 8] = Sprite::create("Trade/ItemImage00.png");
		PhotoMaterial[a + 8]->setPosition(Vec2(100, 440 - a * 125 + ADDVec2));
		layer->addChild(PhotoMaterial[a + 8], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		PriceMaterial[a+8] = Label::create(StringUtils::format("$ %d", bprice[a+8]), "fonts/JejuGothic-Regular.ttf", 30);
		//PriceMaterial[a]->setPosition(Vec2(340, 405-a*125 + ADDVec2));
		PriceMaterial[a+8]->setPosition(Vec2(390, 470 - a * 125 + ADDVec2));
		PriceMaterial[a+8]->setColor(Color3B(0, 0, 0));
		layer->addChild(PriceMaterial[a+8], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LloadPrice[a + 8] = Label::create(StringUtils::format("%.1f％", loadPrice[a + 8]), "fonts/JejuGothic-Regular.ttf", 30);
		LloadPrice[a + 8]->setPosition(Vec2(400, 410 - a * 125 + ADDVec2));
		LloadPrice[a + 8]->setColor(Color3B(0, 0, 0));
		layer->addChild(LloadPrice[a + 8], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LabelHMaterial[a + 8] = Label::create(StringUtils::format("%d개 보유", hprice[a+8]), "fonts/JejuGothic-Regular.ttf", 30);
		LabelHMaterial[a + 8]->setPosition(Vec2(230, 410 - a * 125 + ADDVec2));
		LabelHMaterial[a + 8]->setColor(Color3B(0, 0, 0));
		layer->addChild(LabelHMaterial[a + 8], 1);
	}

	LabelMaterial[8] = Label::create("조개", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[8]->setPosition(Vec2(230, 470 + ADDVec2));
	LabelMaterial[8]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[8], 1);
	LabelMaterial[9] = Label::create("생선", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[9]->setPosition(Vec2(230, 345 + ADDVec2));
	LabelMaterial[9]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[9], 1);
	LabelMaterial[10] = Label::create("바닷가재", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[10]->setPosition(Vec2(230, 220 + ADDVec2));
	LabelMaterial[10]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[10], 1);
	LabelMaterial[11] = Label::create("오징어", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[11]->setPosition(Vec2(230, 95 + ADDVec2));
	LabelMaterial[11]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[11], 1);
}

void Sell::JewelryMenu(LayerColor *layer)
{
	for (int a = 0; a < 4; a++)
	{
		MaterialButton[a + 12] = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		MaterialButton[a + 12]->setPosition(Vec2(300, 440 - a * 125 + ADDVec2));
		MaterialButton[a + 12]->setTag(a + 13);
	}
	JewelryBmenu = ScrollMenu::create(MaterialButton[12], MaterialButton[13], MaterialButton[14], MaterialButton[15], NULL);
	JewelryBmenu->setPosition(Vec2::ZERO);
	layer->addChild(JewelryBmenu);
	PhotoTruck[12] = Sprite::create("truck/jewel/diamond.png");
	PhotoTruck[12]->setPosition(Vec2(100, 440 + ADDVec2));
	PhotoTruck[12]->setScale(0.25);
	layer->addChild(PhotoTruck[12], 2);
	PhotoTruck[13] = Sprite::create("truck/jewel/ruby.png");
	PhotoTruck[13]->setPosition(Vec2(100, 315 + ADDVec2));
	PhotoTruck[13]->setScale(0.25);
	layer->addChild(PhotoTruck[13], 2);
	PhotoTruck[14] = Sprite::create("truck/jewel/emerald.png");
	PhotoTruck[14]->setPosition(Vec2(100, 190 + ADDVec2));
	PhotoTruck[14]->setScale(0.25);
	layer->addChild(PhotoTruck[14], 2);
	PhotoTruck[15] = Sprite::create("truck/jewel/pearl.png");
	PhotoTruck[15]->setPosition(Vec2(100, 65 + ADDVec2));
	PhotoTruck[15]->setScale(0.25);
	layer->addChild(PhotoTruck[15], 2);
	for (int a = 0; a < 4; a++)
	{
		PhotoMaterial[a + 12] = Sprite::create("Trade/ItemImage00.png");
		PhotoMaterial[a + 12]->setPosition(Vec2(100, 440 - a * 125 + ADDVec2));
		layer->addChild(PhotoMaterial[a + 12], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		PriceMaterial[a + 12] = Label::create(StringUtils::format("$ %d", bprice[a + 12]), "fonts/JejuGothic-Regular.ttf", 30);
		//PriceMaterial[a]->setPosition(Vec2(340, 405-a*125 + ADDVec2));
		PriceMaterial[a + 12]->setPosition(Vec2(390, 470 - a * 125 + ADDVec2));
		PriceMaterial[a + 12]->setColor(Color3B(0, 0, 0));
		layer->addChild(PriceMaterial[a + 12], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LloadPrice[a + 12] = Label::create(StringUtils::format("%.1f％", loadPrice[a + 12]), "fonts/JejuGothic-Regular.ttf", 30);
		LloadPrice[a + 12]->setPosition(Vec2(400, 410 - a * 125 + ADDVec2));
		LloadPrice[a + 12]->setColor(Color3B(0, 0, 0));
		layer->addChild(LloadPrice[a + 12], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LabelHMaterial[a + 12] = Label::create(StringUtils::format("%d개 보유", hprice[a+12]), "fonts/JejuGothic-Regular.ttf", 30);
		LabelHMaterial[a + 12]->setPosition(Vec2(230, 410 - a * 125 + ADDVec2));
		LabelHMaterial[a + 12]->setColor(Color3B(0, 0, 0));
		layer->addChild(LabelHMaterial[a + 12], 1);
	}
	LabelMaterial[12] = Label::create("다이아몬드", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[12]->setPosition(Vec2(230, 470 + ADDVec2));
	LabelMaterial[12]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[12], 1);
	LabelMaterial[13] = Label::create("루비", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[13]->setPosition(Vec2(230, 345 + ADDVec2));
	LabelMaterial[13]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[13], 1);
	LabelMaterial[14] = Label::create("에메랄드", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[14]->setPosition(Vec2(230, 220 + ADDVec2));
	LabelMaterial[14]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[14], 1);
	LabelMaterial[15] = Label::create("진주", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[15]->setPosition(Vec2(230, 95 + ADDVec2));
	LabelMaterial[15]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[15], 1);
}

void Sell::MineralMenu(LayerColor *layer)
{
	for (int a = 0; a < 4; a++)
	{
		MaterialButton[a + 16] = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		MaterialButton[a + 16]->setPosition(Vec2(300, 440 - a * 125 + ADDVec2));
		MaterialButton[a + 16]->setTag(a + 17);
	}
	MineralBmenu = ScrollMenu::create(MaterialButton[16], MaterialButton[17], MaterialButton[18], MaterialButton[19], NULL);
	MineralBmenu->setPosition(Vec2::ZERO);
	layer->addChild(MineralBmenu);
	///////// 사진 들/////////////
	PhotoTruck[16] = Sprite::create("truck/mineral/iron.png");
	PhotoTruck[16]->setPosition(Vec2(100, 440 + ADDVec2));
	PhotoTruck[16]->setScale(0.25);
	layer->addChild(PhotoTruck[16], 2);
	PhotoTruck[17] = Sprite::create("truck/mineral/gold.png");
	PhotoTruck[17]->setPosition(Vec2(100, 315 + ADDVec2));
	PhotoTruck[17]->setScale(0.25);
	layer->addChild(PhotoTruck[17], 2);
	PhotoTruck[18] = Sprite::create("truck/mineral/silver.png");
	PhotoTruck[18]->setPosition(Vec2(100, 190 + ADDVec2));
	PhotoTruck[18]->setScale(0.25);
	layer->addChild(PhotoTruck[18], 2);
	PhotoTruck[19] = Sprite::create("truck/mineral/copper.png");
	PhotoTruck[19]->setPosition(Vec2(100, 65 + ADDVec2));
	PhotoTruck[19]->setScale(0.25);
	layer->addChild(PhotoTruck[19], 2);
	//////////////////////////////
	for (int a = 0; a < 4; a++)
	{
		PhotoMaterial[a + 16] = Sprite::create("Trade/ItemImage00.png");
		PhotoMaterial[a + 16]->setPosition(Vec2(100, 440 - a * 125 + ADDVec2));
		layer->addChild(PhotoMaterial[a + 16], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		PriceMaterial[a + 16] = Label::create(StringUtils::format("$ %d", bprice[a + 16]), "fonts/JejuGothic-Regular.ttf", 30);
		//PriceMaterial[a]->setPosition(Vec2(340, 405-a*125 + ADDVec2));
		PriceMaterial[a + 16]->setPosition(Vec2(390, 470 - a * 125 + ADDVec2));
		PriceMaterial[a + 16]->setColor(Color3B(0, 0, 0));
		layer->addChild(PriceMaterial[a + 16], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LloadPrice[a + 16] = Label::create(StringUtils::format("%.1f％", loadPrice[a + 16]), "fonts/JejuGothic-Regular.ttf", 30);
		LloadPrice[a + 16]->setPosition(Vec2(400, 410 - a * 125 + ADDVec2));
		LloadPrice[a + 16]->setColor(Color3B(0, 0, 0));
		layer->addChild(LloadPrice[a + 16], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LabelHMaterial[a + 16] = Label::create(StringUtils::format("%d개 보유", hprice[a+16]), "fonts/JejuGothic-Regular.ttf", 30);
		LabelHMaterial[a + 16]->setPosition(Vec2(230, 410 - a * 125 + ADDVec2));
		LabelHMaterial[a + 16]->setColor(Color3B(0, 0, 0));
		layer->addChild(LabelHMaterial[a + 16], 1);
	}
	LabelMaterial[16] = Label::create("철", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[16]->setPosition(Vec2(230, 470 + ADDVec2));
	LabelMaterial[16]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[16], 1);
	LabelMaterial[17] = Label::create("금", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[17]->setPosition(Vec2(230, 345 + ADDVec2));
	LabelMaterial[17]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[17], 1);
	LabelMaterial[18] = Label::create("은", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[18]->setPosition(Vec2(230, 220 + ADDVec2));
	LabelMaterial[18]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[18], 1);
	LabelMaterial[19] = Label::create("구리", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[19]->setPosition(Vec2(230, 95 + ADDVec2));
	LabelMaterial[19]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[19], 1);
}

void Sell::ClothMenu(LayerColor *layer)
{
	for (int a = 0; a < 4; a++)
	{
		MaterialButton[a + 20] = MenuItemImage::create("Trade/ItemButton.png", "Trade/ItemButton.png", CC_CALLBACK_1(Sell::MaterialMenu, this));
		MaterialButton[a + 20]->setPosition(Vec2(300, 440 - a * 125 + ADDVec2));
		MaterialButton[a + 20]->setTag(a + 21);
	}
	ClothBmenu = ScrollMenu::create(MaterialButton[20], MaterialButton[21], MaterialButton[22], MaterialButton[23], NULL);
	ClothBmenu->setPosition(Vec2::ZERO);
	layer->addChild(ClothBmenu);

	///////// 사진 들/////////////
	PhotoTruck[20] = Sprite::create("truck/cloth/skin.png");
	PhotoTruck[20]->setPosition(Vec2(100, 440 + ADDVec2));
	PhotoTruck[20]->setScale(0.25);
	layer->addChild(PhotoTruck[20], 2);
	PhotoTruck[21] = Sprite::create("truck/cloth/silk.png");
	PhotoTruck[21]->setPosition(Vec2(100, 315 + ADDVec2));
	PhotoTruck[21]->setScale(0.25);
	layer->addChild(PhotoTruck[21], 2);
	PhotoTruck[22] = Sprite::create("truck/cloth/cloth.png");
	PhotoTruck[22]->setPosition(Vec2(100, 190 + ADDVec2));
	PhotoTruck[22]->setScale(0.25);
	layer->addChild(PhotoTruck[22], 2);
	PhotoTruck[23] = Sprite::create("truck/cloth/linen.png");
	PhotoTruck[23]->setPosition(Vec2(100, 65 + ADDVec2));
	PhotoTruck[23]->setScale(0.25);
	layer->addChild(PhotoTruck[23], 2);
	//////////////////////////////
	for (int a = 0; a < 4; a++)
	{
		PhotoMaterial[a + 20] = Sprite::create("Trade/ItemImage00.png");
		PhotoMaterial[a + 20]->setPosition(Vec2(100, 440 - a * 125 + ADDVec2));
		layer->addChild(PhotoMaterial[a + 20], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		PriceMaterial[a + 20] = Label::create(StringUtils::format("$ %d", bprice[a + 20]), "fonts/JejuGothic-Regular.ttf", 30);
		//PriceMaterial[a]->setPosition(Vec2(340, 405-a*125 + ADDVec2));
		PriceMaterial[a + 20]->setPosition(Vec2(390, 470 - a * 125 + ADDVec2));
		PriceMaterial[a + 20]->setColor(Color3B(0, 0, 0));
		layer->addChild(PriceMaterial[a + 20], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LloadPrice[a + 20] = Label::create(StringUtils::format("%.1f％", loadPrice[a + 20]), "fonts/JejuGothic-Regular.ttf", 30);
		LloadPrice[a + 20]->setPosition(Vec2(400, 410 - a * 125 + ADDVec2));
		LloadPrice[a + 20]->setColor(Color3B(0, 0, 0));
		layer->addChild(LloadPrice[a + 20], 1);
	}
	for (int a = 0; a < 4; a++)
	{
		LabelHMaterial[a + 20] = Label::create(StringUtils::format("%d개 보유", hprice[a+20]), "fonts/JejuGothic-Regular.ttf", 30);
		LabelHMaterial[a + 20]->setPosition(Vec2(230, 410 - a * 125 + ADDVec2));
		LabelHMaterial[a + 20]->setColor(Color3B(0, 0, 0));
		layer->addChild(LabelHMaterial[a + 20], 1);
	}
	LabelMaterial[20] = Label::create("가죽", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[20]->setPosition(Vec2(230, 470 + ADDVec2));
	LabelMaterial[20]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[20], 1);
	LabelMaterial[21] = Label::create("비단", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[21]->setPosition(Vec2(230, 345 + ADDVec2));
	LabelMaterial[21]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[21], 1);
	LabelMaterial[22] = Label::create("면", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[22]->setPosition(Vec2(230, 220 + ADDVec2));
	LabelMaterial[22]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[22], 1);
	LabelMaterial[23] = Label::create("리넨", "fonts/JejuGothic-Regular.ttf", 30);
	LabelMaterial[23]->setPosition(Vec2(230, 95 + ADDVec2));
	LabelMaterial[23]->setColor(Color3B(0, 0, 0));
	layer->addChild(LabelMaterial[23], 1);
}

void Sell::Setloadprice()
{
	loadPrice[0] = UserDefault::getInstance()->getIntegerForKey("LPEPPER");
	loadPrice[1] = UserDefault::getInstance()->getIntegerForKey("LGARLIC");
	loadPrice[2] = UserDefault::getInstance()->getIntegerForKey("LSUGAR");
	loadPrice[3] = UserDefault::getInstance()->getIntegerForKey("LCINNAMON");
	loadPrice[4] = UserDefault::getInstance()->getIntegerForKey("LRICE");
	loadPrice[5] = UserDefault::getInstance()->getIntegerForKey("LONION");
	loadPrice[6] = UserDefault::getInstance()->getIntegerForKey("LWHEAT");
	loadPrice[7] = UserDefault::getInstance()->getIntegerForKey("LWONION");
	loadPrice[8] = UserDefault::getInstance()->getIntegerForKey("LSHELLFISH");
	loadPrice[9] = UserDefault::getInstance()->getIntegerForKey("LFISH");
	loadPrice[10] = UserDefault::getInstance()->getIntegerForKey("LLOBSTER");
	loadPrice[11] = UserDefault::getInstance()->getIntegerForKey("LSQUID");
	loadPrice[12] = UserDefault::getInstance()->getIntegerForKey("LDIAMOND");
	loadPrice[13] = UserDefault::getInstance()->getIntegerForKey("LRUBY");
	loadPrice[14] = UserDefault::getInstance()->getIntegerForKey("LPERIDOT");
	loadPrice[15] = UserDefault::getInstance()->getIntegerForKey("LPEARL");
	loadPrice[16] = UserDefault::getInstance()->getIntegerForKey("LIRON");
	loadPrice[17] = UserDefault::getInstance()->getIntegerForKey("LGOLD");
	loadPrice[18] = UserDefault::getInstance()->getIntegerForKey("LSILVER");
	loadPrice[19] = UserDefault::getInstance()->getIntegerForKey("LCOPPER");
	loadPrice[20] = UserDefault::getInstance()->getIntegerForKey("LLEATHER");
	loadPrice[21] = UserDefault::getInstance()->getIntegerForKey("LSILK");
	loadPrice[22] = UserDefault::getInstance()->getIntegerForKey("LNOODLE");
	loadPrice[23] = UserDefault::getInstance()->getIntegerForKey("LLINEN");

	for (int a = 4; a < 24; a++)
	{
		if (loadPrice[a] != (float)0.0)
			loadPrice[a] = bprice[a] / loadPrice[a];
	
		if (loadPrice[a]<1.0)
		{
			loadPriceUD[a]->setTexture("Trade/down.png");
		}
		else
		{
			loadPriceUD[a]->setTexture("Trade/up.png");
		}
		if (loadPrice[a] != 0.0f)
		{
			loadPrice[a] -= 1.0;
			if (loadPrice[a] < 0)
				loadPrice[a] *= -1;
			loadPrice[a] *= 100;
		}
		else
			loadPrice[a] = 0;
	}

}
