#include"Shipyard.h"

Shipyard::Shipyard(Layer *layer)
{
	ShipAtkUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPATTACK") * 1000;    // 배 공격력;
	ShipHpUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 1000;         // 배체력 레벨;
	ShipSpeedUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPSPEED") * 1000;   // 배 스피드 ;
	ShipSupplyUpgradeCost = UserDefault::getInstance()->getIntegerForKey("MAX") / 50 * 1000;
	RepairCost = ((90 + UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 10) - UserDefault::getInstance()->getIntegerForKey("NSHIPHP")) * 10;
	////////////////////////////////////////////
	CHLayer = LayerColor::create(Color4B(0, 0, 0, 125));
	CHLayer->setAnchorPoint(Vec2(0, 0));
	CHLayer->setPosition(Vec2(0, 0));
	CHLayer->setVisible(false);
	layer->addChild(CHLayer, 10);
	auto Touch = MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(Shipyard::ShipUpgrade, this));
	Touch->setPosition(Vec2(640, 360));
	auto touchmenu = Menu::create(Touch, NULL);
	touchmenu->setPosition(Vec2::ZERO);
	CHLayer->addChild(touchmenu);

	UPLayer = Layer::create();
	UPLayer->setAnchorPoint(Vec2(0, 0));
	UPLayer->setPosition(Vec2(0, 0));
	UPLayer->setVisible(false);
	layer->addChild(UPLayer, 15);
	auto Touch2 = MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(Shipyard::ShipUpgrade, this));
	Touch2->setPosition(Vec2(640, 360));
	auto touchmenu2 = Menu::create(Touch2, NULL);
	touchmenu2->setPosition(Vec2::ZERO);
	UPLayer->addChild(touchmenu2);

	SKLayer = Layer::create();
	SKLayer->setAnchorPoint(Vec2(0, 0));
	SKLayer->setPosition(Vec2(0, 0));
	SKLayer->setVisible(false);
	layer->addChild(SKLayer, 15);
	auto Touch3 = MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(Shipyard::ShipUpgrade, this));
	Touch3->setPosition(Vec2(640, 360));
	auto touchmenu3 = Menu::create(Touch3, NULL);
	touchmenu3->setPosition(Vec2::ZERO);
	SKLayer->addChild(touchmenu3);

	Layer *SuperLayer = LayerColor::create(Color4B(255, 3, 2, 0), 570, 455);
	SuperLayer->setPosition(Vec2(360, 20));
	SuperLayer->setAnchorPoint(Vec2(0.5f, 0.5f));

	scrollview = ScrollView::create(Size(590, 310), SuperLayer);
	UPLayer->addChild(scrollview, 55);
	scrollview->setPosition(Vec2(640 - 300, 290 - 150));
	scrollview->setDirection(ScrollView::Direction::VERTICAL);
	scrollview->setBounceable(true);
	scrollview->setContentOffset(Vec2(0, -150));

	Layer *SuperLayer2 = LayerColor::create(Color4B(255, 3, 2, 0), 570, 455);
	SuperLayer2->setPosition(Vec2(360, 20));
	SuperLayer2->setAnchorPoint(Vec2(0.5f, 0.5f));

	scrollview = ScrollView::create(Size(590, 290), SuperLayer2);
	SKLayer->addChild(scrollview, 55);
	scrollview->setPosition(Vec2(640 - 300, 290 - 190));
	scrollview->setDirection(ScrollView::Direction::VERTICAL);
	scrollview->setBounceable(true);
	scrollview->setContentOffset(Vec2(0, -150));





	//////////////////////////////////////////////////////// 배 업그레이드 / 스킨 상점 팝업

	Choice = Sprite::create("Shipyard1/BgShipyard.png");
	Choice->setPosition(Vec2(640, 360));
	Choice->setAnchorPoint(Vec2(0.5f, 0.5f));

	CHLayer->addChild(Choice, 1);

	Close = MenuItemImage::create("All/CloseButton00.png", "All/CloseButton01.png", CC_CALLBACK_0(Shipyard::Destroy, this));
	Close->setPosition(Vec2(970, 630));
	Close->setAnchorPoint(Vec2(0.5f, 0.5f));
	Close->setVisible(false);

	CloseMenu = Menu::create(Close, nullptr);
	CloseMenu->setPosition(Vec2(0, 0));
	CloseMenu->setAnchorPoint(Vec2(0.5f, 0.5f));
	CloseMenu->setVisible(true);
	layer->addChild(CloseMenu, 20);

	UpgradeChoice = MenuItemImage::create("Shipyard1/Upgrade00.png", "Shipyard1/Upgrade01.png", CC_CALLBACK_0(Shipyard::Upgrade_PopUp, this));
	UpgradeChoice->setPosition(Vec2(640, 310));
	UpgradeChoice->setAnchorPoint(Vec2(0.5f, 0.5f));

	SkinChoice = MenuItemImage::create("Shipyard1/SkinButton00.png", "Shipyard1/SkinButton01.png", CC_CALLBACK_0(Shipyard::Skin_PopUp, this));
	SkinChoice->setPosition(Vec2(640, 170));
	SkinChoice->setAnchorPoint(Vec2(0.5f, 0.5f));

	ChoiceMenu = Menu::create(UpgradeChoice, SkinChoice, nullptr);
	ChoiceMenu->setPosition(Vec2(0, 0));
	ChoiceMenu->setAnchorPoint(Vec2(0.5f, 0.5f));
	ChoiceMenu->setVisible(true);
	CHLayer->addChild(ChoiceMenu, 2);

	//////////////////////////////////////////////////////////////////// 업그레이드 / 수리 부분 팝업

	UpgradeBg = Sprite::create("Shipyard/BgUpgrade.png");
	UpgradeBg->setPosition(Vec2(640, 360));
	UpgradeBg->setAnchorPoint(Vec2(0.5f, 0.5f));
	UPLayer->addChild(UpgradeBg, 1);

	Repair = Sprite::create("Shipyard/category00.png");
	Repair->setPosition(Vec2(640 - 340, 420 - 20));
	Repair->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer->addChild(Repair, 2);



	RepairImage = MenuItemImage::create("Shipyard/Repair00.png", "Shipyard/Repair01.png", CC_CALLBACK_0(Shipyard::ShipRepair, this));
	RepairImage->setPosition(Vec2(830 - 340, 420 - 20));
	RepairImage->setAnchorPoint(Vec2(0.5f, 0.5f));

	auto menu = Menu::create(RepairImage, NULL);
	menu->setPosition(Vec2(0, 0));
	menu->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer->addChild(menu, 3);

	UpgradeSprite[4] = Sprite::create("Shipyard/upgrade4.png");
	UpgradeSprite[4]->setPosition(Vec2(425 - 340, 425 - 360 - 20));
	UpgradeSprite[4]->setScale(0.9f);
	UpgradeSprite[4]->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer->addChild(UpgradeSprite[4], 3);

	for (int i = 0; i < 4; i++)
	{
		Max[i] = Sprite::create("Shipyard/Max.png");
		Max[i]->setPosition(Vec2(830 - 340, 330 - i * 90 - 20));
		Max[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
		Max[i]->setVisible(false);
		SuperLayer->addChild(Max[i], 6);

		Upgrade[i] = Sprite::create("Shipyard/category01.png");
		Upgrade[i]->setPosition(Vec2(640 - 340, 330 - i * 90 - 20));
		Upgrade[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
		SuperLayer->addChild(Upgrade[i], 2);

		UpgradeSprite[i] = Sprite::create(StringUtils::format("Shipyard/upgrade%d.png", i));
		UpgradeSprite[i]->setPosition(Vec2(425 - 340, 425 - i * 90 - 20));
		UpgradeSprite[i]->setScale(0.9f);
		UpgradeSprite[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
		SuperLayer->addChild(UpgradeSprite[i], 3);

		UpgradeImage[i] = MenuItemImage::create("Shipyard/Upgrade00.png", "Shipyard/Upgrade01.png", CC_CALLBACK_1(Shipyard::ShipUpgrade, this));
		UpgradeImage[i]->setPosition(Vec2(830 - 340, 330 - i * 90 - 20));
		UpgradeImage[i]->setTag(i);           // 0 공격력 1 HP 2 속도
		UpgradeImage[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
	}
	ChoiceMenu = Menu::create(UpgradeImage[0], UpgradeImage[1], UpgradeImage[2], UpgradeImage[3], nullptr);
	ChoiceMenu->setPosition(Vec2(0, 0));
	ChoiceMenu->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer->addChild(ChoiceMenu, 3);

	///////////////////////////////////////////////////////////// 배 스킨 상점 팝업
	SkinBg = Sprite::create("ShipSkin/BgSkin.png");
	SkinBg->setPosition(Vec2(640, 360));
	SkinBg->setAnchorPoint(Vec2(0.5f, 0.5f));
	SKLayer->addChild(SkinBg, 1);

	for (int i = 0; i < 4; i++)
	{
		Skin[i] = Sprite::create("ShipSkin/Category.png");
		Skin[i]->setPosition(Vec2(640 - 340, 360 - i * 100 + 30));
		Skin[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
		SuperLayer2->addChild(Skin[i], 2);

		ShipSkin[i] = Sprite::create(StringUtils::format("ShipSkin/sh_%d.png", i + 1));
		ShipSkin[i]->setPosition(Vec2(398 - 340, 365 - i * 100 + 30));
		ShipSkin[i]->setAnchorPoint(Vec2(0.5f, 0.5f));

		SuperLayer2->addChild(ShipSkin[i], 3);

		SkinImage[i] = MenuItemImage::create("ShipSkin/BuyButton0.png", "ShipSkin/BuyButton1.png", CC_CALLBACK_1(Shipyard::BuySkin, this));
		SkinImage[i]->setPosition(Vec2(830 - 340, 360 - i * 100 + 30));

		SkinImage[i]->setTag(i);           // 배 종류 
		SkinImage[i]->setAnchorPoint(Vec2(0.5f, 0.5f));

		HaveSkin[i] = MenuItemImage::create("ShipSkin/hold_0.png", "ShipSkin/hold_1.png", CC_CALLBACK_1(Shipyard::InstallSkin, this));
		HaveSkin[i]->setPosition(Vec2(830 - 340, 360 - i * 100 + 30));
		HaveSkin[i]->setVisible(false);
		HaveSkin[i]->setTag(i);           // 배 종류 
		HaveSkin[i]->setAnchorPoint(Vec2(0.5f, 0.5f));

		Install[i] = Sprite::create("ShipSkin/Install.png");
		Install[i]->setPosition(Vec2(830 - 340, 360 - i * 100 + 30));

		Install[i]->setVisible(false);
		Install[i]->setTag(i);           // 배 종류 
		Install[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
		SuperLayer2->addChild(Install[i], 5);

	}
	SkinMenu = Menu::create(SkinImage[0], SkinImage[1], SkinImage[2], SkinImage[3], nullptr);
	SkinMenu->setPosition(Vec2(0, 0));
	SkinMenu->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer2->addChild(SkinMenu, 3);

	HaveMenu = Menu::create(HaveSkin[0], HaveSkin[1], HaveSkin[2], HaveSkin[3], nullptr);
	HaveMenu->setPosition(Vec2(0, 0));
	HaveMenu->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer2->addChild(HaveMenu, 4);



	///////////////////////////////////////////////////////////// 라벨



	NowHp = Label::createWithTTF(StringUtils::format("배 체력 %.0f%%", (UserDefault::getInstance()->getIntegerForKey
	("NSHIPHP") / (90 + UserDefault::getInstance()->getIntegerForKey
	("SHIPHP") * 10)) * 100), "fonts/JejuGothic-Regular.ttf", 35);
	NowHp->setPosition(Vec2(600 - 340, 415 - 20));

	SuperLayer->addChild(NowHp, 4);





	AtkLabel = Label::createWithTTF(StringUtils::format("LV. %d 원거리 함포",
		UserDefault::getInstance()->getIntegerForKey("SHIPATTACK")), "fonts/JejuGothic-Regular.ttf", 30);
	AtkLabel->setPosition(Vec2(490 - 340, 340 - 20));
	AtkLabel->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(AtkLabel, 4);

	AtkLabel2 = Label::createWithTTF(StringUtils::format("공격력 +%d%%",
		UserDefault::getInstance()->getIntegerForKey("SHIPATTACK")), "fonts/JejuGothic-Regular.ttf", 20);
	AtkLabel2->setPosition(Vec2(490 - 340, 315 - 20));
	AtkLabel2->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(AtkLabel2, 4);

	CostLabel[0] = Label::createWithTTF(StringUtils::format("%d",
		ShipAtkUpgradeCost), "fonts/JejuGothic-Regular.ttf", 30);
	CostLabel[0]->setPosition(Vec2(790 - 340, 320 - 20));
	CostLabel[0]->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(CostLabel[0], 4);
	////////////////////////////////////////////////////////////////////////////////////////////////
	HpLabel = Label::createWithTTF(StringUtils::format("LV. %d 선체",
		UserDefault::getInstance()->getIntegerForKey("SHIPHP")), "fonts/JejuGothic-Regular.ttf", 30);
	HpLabel->setPosition(Vec2(490 - 340, 250 - 20));
	HpLabel->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(HpLabel, 4);

	HpLabel2 = Label::createWithTTF(("HP +10"), "fonts/JejuGothic-Regular.ttf", 20);
	HpLabel2->setPosition(Vec2(490 - 340, 225 - 20));
	HpLabel2->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(HpLabel2, 4);

	CostLabel[1] = Label::createWithTTF(StringUtils::format("%d",
		ShipHpUpgradeCost), "fonts/JejuGothic-Regular.ttf", 30);
	CostLabel[1]->setPosition(Vec2(790 - 340, 230 - 20));
	CostLabel[1]->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(CostLabel[1], 4);
	//////////////////////////////////////////////////////////////////////////////
	SpeedLabel = Label::createWithTTF(StringUtils::format("LV. %d 돛",
		UserDefault::getInstance()->getIntegerForKey("SHIPSPEED")), "fonts/JejuGothic-Regular.ttf", 30);
	SpeedLabel->setPosition(Vec2(490 - 340, 160 - 20));
	SpeedLabel->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(SpeedLabel, 4);

	SpeedLabel2 = Label::createWithTTF(StringUtils::format("이동속도 +%d%%",
		UserDefault::getInstance()->getIntegerForKey("SHIPSPEED")), "fonts/JejuGothic-Regular.ttf", 20);
	SpeedLabel2->setPosition(Vec2(490 - 340, 135 - 20));
	SpeedLabel2->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(SpeedLabel2, 4);

	CostLabel[2] = Label::createWithTTF(StringUtils::format("%d",
		ShipSpeedUpgradeCost), "fonts/JejuGothic-Regular.ttf", 30);
	CostLabel[2]->setPosition(Vec2(790 - 340, 140 - 20));
	CostLabel[2]->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(CostLabel[2], 4);

	////////////////////////////////////////////////////////////////////////////////////////////////
	Supply = Label::createWithTTF(StringUtils::format("LV. %d 화물량",
		(UserDefault::getInstance()->getIntegerForKey("MAX") - 45) / 5), "fonts/JejuGothic-Regular.ttf", 30);
	Supply->setPosition(Vec2(490 - 340, 70 - 20));
	Supply->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(Supply, 4);

	Supply2 = Label::createWithTTF(("화물량 +5"), "fonts/JejuGothic-Regular.ttf", 20);
	Supply2->setPosition(Vec2(490 - 340, 45 - 20));
	Supply2->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(Supply2, 4);

	CostLabel[4] = Label::createWithTTF(StringUtils::format("%d",
		ShipSupplyUpgradeCost), "fonts/JejuGothic-Regular.ttf", 30);
	CostLabel[4]->setPosition(Vec2(790 - 340, 50 - 20));
	CostLabel[4]->setAnchorPoint(Vec2(0, 0.5f));

	SuperLayer->addChild(CostLabel[4], 4);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	CostLabel[3] = Label::createWithTTF(StringUtils::format("%d",
		RepairCost), "fonts/JejuGothic-Regular.ttf", 30);
	CostLabel[3]->setPosition(Vec2(825 - 340, 405 - 20));
	CostLabel[3]->setAnchorPoint(Vec2(0.5f, 0.5f));

	SuperLayer->addChild(CostLabel[3], 4);


	///////////////////////////////////////////////////////////////////////////////////////////////// 스킨상점 라벨
	ShipLabel[0] = Label::createWithTTF(("궁극의킹갓엠페러빨강배"), "fonts/JejuGothic-Regular.ttf", 30);
	ShipLabel[0]->setPosition(Vec2(600 - 340, 415 - 20));
	ShipLabel[0]->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer2->addChild(ShipLabel[0], 6);

	ShipLabel[1] = Label::createWithTTF(("렘"), "fonts/JejuGothic-Regular.ttf", 30);
	ShipLabel[1]->setPosition(Vec2(600 - 340, 415 - 20 - 100));
	ShipLabel[1]->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer2->addChild(ShipLabel[1], 6);

	ShipLabel[2] = Label::createWithTTF(("니가그린기린그린쉽"), "fonts/JejuGothic-Regular.ttf", 30);
	ShipLabel[2]->setPosition(Vec2(600 - 340, 415 - 20 - 200));
	ShipLabel[2]->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer2->addChild(ShipLabel[2], 6);

	ShipLabel[3] = Label::createWithTTF(("러버덕"), "fonts/JejuGothic-Regular.ttf", 30);
	ShipLabel[3]->setPosition(Vec2(600 - 340, 415 - 20 - 300));
	ShipLabel[3]->setAnchorPoint(Vec2(0.5f, 0.5f));
	SuperLayer2->addChild(ShipLabel[3], 6);

	buyskin();
	installskin();
	MaxCheck();
}

void Shipyard::init()
{
	CHLayer->setVisible(true);
	Close->setVisible(true);
	HowPopup = 0;
}



void Shipyard::Skin_PopUp()
{
	SKLayer->setVisible(true);
	HowPopup = 2;
}

void Shipyard::Upgrade_PopUp()
{
	NowHp->setString(StringUtils::format("배 체력 %.0f%%", ((float)UserDefault::getInstance()->getIntegerForKey
	("NSHIPHP") / (90 + UserDefault::getInstance()->getIntegerForKey
	("SHIPHP") * 10)) * 100));

	UPLayer->setVisible(true);
	HowPopup = 1;
}

void Shipyard::ShipRepair()
{


	RepairCost = ((90 + UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 10) - UserDefault::getInstance()->getIntegerForKey("NSHIPHP")) * 10;
	if (UserDefault::getInstance()->getIntegerForKey("MONEY") >= RepairCost)
	{
		UserDefault::getInstance()->setIntegerForKey("MONEY", UserDefault::getInstance()->getIntegerForKey("MONEY") - RepairCost);
		UserDefault::getInstance()->setIntegerForKey("NSHIPHP", 90 + UserDefault::getInstance()->getIntegerForKey
		("SHIPHP") * 10); //가지고있는 배체력 

		NowHp->setString(StringUtils::format("배 체력 %.0f%%", ((float)UserDefault::getInstance()->getIntegerForKey
		("NSHIPHP") / (90 + UserDefault::getInstance()->getIntegerForKey
		("SHIPHP") * 10)) * 100));
	}
	RepairCost = ((90 + UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 10) - UserDefault::getInstance()->getIntegerForKey("NSHIPHP")) * 10;
	CostLabel[3]->setString(StringUtils::format("%d", RepairCost));


}

void Shipyard::ShipUpgrade(Ref* pSender)
{

	ShipAtkUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPATTACK") * 1000;    // 배 공격력;
	ShipHpUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 1000;         // 배체력 레벨;
	ShipSpeedUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPSPEED") * 1000;   // 배 스피드 ;
	ShipSupplyUpgradeCost = (UserDefault::getInstance()->getIntegerForKey("MAX") - 45) / 5 * 1000;

	switch (((Node*)pSender)->getTag())
	{
	case 0:
		if (UserDefault::getInstance()->getIntegerForKey("MONEY") >= ShipAtkUpgradeCost && UserDefault::getInstance()->getIntegerForKey("SHIPATTACK") < 50)
		{
			UserDefault::getInstance()->setIntegerForKey("SHIPATTACK", UserDefault::getInstance()->getIntegerForKey("SHIPATTACK") + 1);
			UserDefault::getInstance()->setIntegerForKey("MONEY", UserDefault::getInstance()->getIntegerForKey("MONEY") - ShipAtkUpgradeCost);

			ShipAtkUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPATTACK") * 1000;

			AtkLabel->setString(StringUtils::format("LV. %d 원거리 함포", UserDefault::getInstance()->getIntegerForKey("SHIPATTACK")));
			AtkLabel2->setString(StringUtils::format("공격력 +%d%%", UserDefault::getInstance()->getIntegerForKey("SHIPATTACK")));
			CostLabel[0]->setString(StringUtils::format("%d", ShipAtkUpgradeCost));

			MaxCheck();

		}

		break;
	case 1:

		if (UserDefault::getInstance()->getIntegerForKey("MONEY") >= ShipHpUpgradeCost && UserDefault::getInstance()->getIntegerForKey("SHIPHP") < 50)
		{
			UserDefault::getInstance()->setIntegerForKey("SHIPHP", UserDefault::getInstance()->getIntegerForKey("SHIPHP") + 1);
			UserDefault::getInstance()->setIntegerForKey("MONEY", UserDefault::getInstance()->getIntegerForKey("MONEY") - ShipHpUpgradeCost);
			UserDefault::getInstance()->setIntegerForKey("NSHIPHP", UserDefault::getInstance()->getIntegerForKey("NSHIPHP") + 10);

			ShipHpUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPHP") * 1000;

			HpLabel->setString(StringUtils::format("LV. %d 선체", UserDefault::getInstance()->getIntegerForKey("SHIPHP")));
			CostLabel[1]->setString(StringUtils::format("%d", ShipHpUpgradeCost));

			NowHp->setString(StringUtils::format("배 체력 %.0f%%", ((float)UserDefault::getInstance()->getIntegerForKey
			("NSHIPHP") / (90 + UserDefault::getInstance()->getIntegerForKey
			("SHIPHP") * 10)) * 100));

			MaxCheck();

		}
		break;

	case 2:

		if (UserDefault::getInstance()->getIntegerForKey("MONEY") >= ShipSpeedUpgradeCost && UserDefault::getInstance()->getIntegerForKey("SHIPSPEED") < 50)
		{
			UserDefault::getInstance()->setIntegerForKey("SHIPSPEED", UserDefault::getInstance()->getIntegerForKey("SHIPSPEED") + 1);
			UserDefault::getInstance()->setIntegerForKey("MONEY", UserDefault::getInstance()->getIntegerForKey("MONEY") - ShipSpeedUpgradeCost);

			ShipSpeedUpgradeCost = UserDefault::getInstance()->getIntegerForKey("SHIPSPEED") * 1000;

			SpeedLabel->setString(StringUtils::format("LV. %d 돛", UserDefault::getInstance()->getIntegerForKey("SHIPSPEED")));
			SpeedLabel2->setString(StringUtils::format("이동속도 +%d%%", UserDefault::getInstance()->getIntegerForKey("SHIPSPEED")));
			CostLabel[2]->setString(StringUtils::format("%d", ShipSpeedUpgradeCost));

			MaxCheck();

		}

		break;
	case 3:
		if (UserDefault::getInstance()->getIntegerForKey("MONEY") >= ShipSupplyUpgradeCost && (UserDefault::getInstance()->getIntegerForKey("MAX") - 45) / 5 < 50)
		{
			UserDefault::getInstance()->setIntegerForKey("MAX", UserDefault::getInstance()->getIntegerForKey("MAX") + 5);
			UserDefault::getInstance()->setIntegerForKey("MONEY", UserDefault::getInstance()->getIntegerForKey("MONEY") - ShipSupplyUpgradeCost);

			ShipSupplyUpgradeCost = (UserDefault::getInstance()->getIntegerForKey("MAX") - 45) / 5 * 1000;

			Supply->setString(StringUtils::format("LV. %d 화물량", (UserDefault::getInstance()->getIntegerForKey("MAX") - 45) / 5));
			CostLabel[4]->setString(StringUtils::format("%d", ShipSupplyUpgradeCost));

			MaxCheck();

		}

		break;

	}
}

void Shipyard::Destroy()
{
	switch (HowPopup)
	{
	case 0:
		CHLayer->setVisible(false);
		Close->setVisible(false);
		break;
	case 1:
		UPLayer->setVisible(false);
		HowPopup = 0;
		break;
	case 2:
		SKLayer->setVisible(false);
		HowPopup = 0;
		break;

	}
}

void Shipyard::BuySkin(Ref* pSender)
{
	if (UserDefault::getInstance()->getIntegerForKey("CASH") >= 30)
	{
		switch (((Node*)pSender)->getTag())
		{
		case 1:
			if (UserDefault::getInstance()->getIntegerForKey("BLUESKIN") == 0)
			{
				UserDefault::getInstance()->setIntegerForKey("CASH", UserDefault::getInstance()->getIntegerForKey("CASH") - 30);
				UserDefault::getInstance()->setIntegerForKey("BLUESKIN", 1);
			}
			break;
		case 2:
			if (UserDefault::getInstance()->getIntegerForKey("GREENSKIN") == 0)
			{
				UserDefault::getInstance()->setIntegerForKey("CASH", UserDefault::getInstance()->getIntegerForKey("CASH") - 30);
				UserDefault::getInstance()->setIntegerForKey("GREENSKIN", 1);
			}
			break;
		case 3:
			if (UserDefault::getInstance()->getIntegerForKey("YELLOWSKIN") == 0)
			{
				UserDefault::getInstance()->setIntegerForKey("CASH", UserDefault::getInstance()->getIntegerForKey("CASH") - 30);
				UserDefault::getInstance()->setIntegerForKey("YELLOWSKIN", 1);
			}
			break;
		}
	}
	buyskin();
}

void Shipyard::InstallSkin(Ref* pSender)
{
	switch (((Node*)pSender)->getTag())
	{
	case 0:
		UserDefault::getInstance()->setIntegerForKey("SHIPSKIN", 1);
		break;
	case 1:
		if (UserDefault::getInstance()->getIntegerForKey("BLUESKIN") == 1)
			UserDefault::getInstance()->setIntegerForKey("SHIPSKIN", 2);

		break;
	case 2:
		if (UserDefault::getInstance()->getIntegerForKey("GREENSKIN") == 1)
			UserDefault::getInstance()->setIntegerForKey("SHIPSKIN", 3);
		break;
	case 3:
		if (UserDefault::getInstance()->getIntegerForKey("YELLOWSKIN") == 1)
			UserDefault::getInstance()->setIntegerForKey("SHIPSKIN", 4);
		break;
	}
	installskin();

}

void Shipyard::installskin()
{
	switch (UserDefault::getInstance()->getIntegerForKey("SHIPSKIN"))
	{
	case 1:
		Install[0]->setVisible(true);
		Install[1]->setVisible(false);
		Install[2]->setVisible(false);
		Install[3]->setVisible(false);
		break;
	case 2:
		Install[0]->setVisible(false);
		Install[1]->setVisible(true);
		Install[2]->setVisible(false);
		Install[3]->setVisible(false);
		break;
	case 3:
		Install[0]->setVisible(false);
		Install[1]->setVisible(false);
		Install[2]->setVisible(true);
		Install[3]->setVisible(false);
		break;
	case 4:
		Install[0]->setVisible(false);
		Install[1]->setVisible(false);
		Install[2]->setVisible(false);
		Install[3]->setVisible(true);
		break;
	}

}

void Shipyard::buyskin()
{
	if (UserDefault::getInstance()->getIntegerForKey("REDSKIN") == 1)
	{
		HaveSkin[0]->setVisible(true);
	}
	if (UserDefault::getInstance()->getIntegerForKey("BLUESKIN") == 1)
	{
		HaveSkin[1]->setVisible(true);
	}
	if (UserDefault::getInstance()->getIntegerForKey("GREENSKIN") == 1)
	{
		HaveSkin[2]->setVisible(true);
	}
	if (UserDefault::getInstance()->getIntegerForKey("YELLOWSKIN") == 1)
	{
		HaveSkin[3]->setVisible(true);
	}
}

void Shipyard::MaxCheck()
{
	if (UserDefault::getInstance()->getIntegerForKey("SHIPATTACK") == 50)
		Max[0]->setVisible(true);
	if (UserDefault::getInstance()->getIntegerForKey("SHIPHP") == 50)
		Max[1]->setVisible(true);
	if (UserDefault::getInstance()->getIntegerForKey("SHIPSPEED") == 50)
		Max[2]->setVisible(true);
	if ((UserDefault::getInstance()->getIntegerForKey("MAX") - 45) / 5 == 50)
		Max[3]->setVisible(true);
}