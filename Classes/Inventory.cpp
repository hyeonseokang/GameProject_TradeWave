#include "Inventory.h"
#pragma execution_character_set("utf-8")
#define SCALE 1.0
#define ADD 35
void Inventory::ChangeLabel(int index)
{
	MAXbar->setScaleX(((float)UserDefault::getInstance()->getIntegerForKey("HMAX") / UserDefault::getInstance()->getIntegerForKey("MAX")));
	CountLabel[index]->setString(StringUtils::format("X%d",hprice[index]));
}
void Inventory::InventoryInit(Layer * layer,int *have)
{
	hprice = have;
	InventoryLayer = LayerColor::create(Color4B(0, 0, 0, 125));
	InventoryLayer->setPosition(Vec2::ZERO);
	layer->addChild(InventoryLayer,5);
	InventoryLayer->setVisible(false);
	auto Touch = MenuItemImage::create("transparency.png",
		"transparency.png", CC_CALLBACK_1(Inventory::Explan, this));
	Touch->setPosition(Vec2(640, 360));
	auto touchmenu = Menu::create(Touch, NULL);
	touchmenu->setPosition(Vec2::ZERO);
	InventoryLayer->addChild(touchmenu);
	for (int a = 0; a < 6; a++)
	{
		invenmaterial[a] = LayerColor::create(Color4B(35, 36, 23, 0)); 
		invenmaterial[a]->setPosition(Vec2::ZERO);
		InventoryLayer->addChild(invenmaterial[a],1);
		invenmaterial[a]->setVisible(false);
	}
	/*for (int a = 0; a < 3; a++)
	{
		ExplanLabel[a] = Label::create("a", "fonts/JejuGothic-Regular.ttf", 25,Size(600,200),TextHAlignment::LEFT);
		ExplanLabel[a]->setColor(Color3B(255, 255, 255));
		ExplanLabel[a]->setPosition(Vec2(640, 305 - a * 40 + ADD));
	}*/
	ExplanLabel[0] = Label::create("가죽", "fonts/JejuGothic-Regular.ttf", 35, Size(600, 200), TextHAlignment::LEFT);
	ExplanLabel[0]->setColor(Color3B(255, 255, 255));
	ExplanLabel[0]->setAnchorPoint(Vec2(0, 0.5));
	ExplanLabel[0]->setPosition(Vec2(360, 295-85 + ADD));
	ExplanLabel[1] = Label::create("다양한 지역에서 생산하는 옷감이다.\n동물의 껍질이며 가공 기술이 부족해동 사용할 수 있다."
		, "fonts/JejuGothic-Regular.ttf", 20, Size(600, 200), TextHAlignment::LEFT);
	ExplanLabel[1]->setColor(Color3B(255, 255, 255));
	ExplanLabel[1]->setAnchorPoint(Vec2(0, 0.5));
	ExplanLabel[1]->setPosition(Vec2(360, 295 - 135 + ADD));
	ExplanLabel[2] = Label::create("1필당 가격: 500$", "fonts/JejuGothic-Regular.ttf", 35, Size(600, 200), TextHAlignment::LEFT);
	ExplanLabel[2]->setColor(Color3B(255, 255, 255));
	ExplanLabel[2]->setAnchorPoint(Vec2(0, 0.5));
	ExplanLabel[2]->setPosition(Vec2(360, 295 - 205 + ADD));

	Choicespr = Sprite::create("Chest/icon1.png");
	Init(InventoryLayer, invenmaterial[1], invenmaterial[2],
		invenmaterial[3], invenmaterial[4], invenmaterial[5], ExplanLabel, Choicespr);
	SelectCategory->setTexture("Trade/Category00.png");
	SelectLayer->setVisible(false);
	SelectCategory = Category05;
	SelectLayer = ClothLayer;
	SelectCategory->setTexture("Trade/Category01.png");
	SelectLayer->setVisible(true);
	for (int a = 0; a < 6; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			IconButton[a * 4 + i] = MenuItemImage::create("Chest/icon.png", "Chest/icon.png"
				, CC_CALLBACK_1(Inventory::Explan, this));
			IconButton[a * 4 + i]->setPosition(Vec2(420+i*147,440+ ADD));
			IconButton[a * 4 + i]->setTag(a * 4 + i);
			IconButton[a * 4 + i]->setScale(SCALE);
		}
	}
	for (int a = 0; a < 6; a++)
	{
		IconMenu[a] = Menu::create(IconButton[a * 4], IconButton[a * 4 + 1], IconButton[a * 4 + 2]
			, IconButton[a * 4 + 3], NULL);
		IconMenu[a]->setPosition(Vec2::ZERO);
		invenmaterial[a]->addChild(IconMenu[a]);
		invenmaterial[a]->setVisible(false);
	}
	IconCreate(InventoryLayer);
	invenmaterial[5]->setVisible(true);

	
	Choicespr->setPosition(Vec2(420, 440 + ADD));
	InventoryLayer->addChild(Choicespr);
	


	Bgexplan->setVisible(false);
	for (int a = 0; a < 3; a++)
	{
		ExplanLabel[a]->setVisible(false);
	}
	Bgexplan->setVisible(true);
	for (int a = 0; a < 3; a++)
	{
		ExplanLabel[a]->setVisible(true);
	}

	
}

void Inventory::Explan(Ref * pSender)
{
	
	Bgexplan->setVisible(true);
	for (int a = 0; a < 3; a++)
	{
		ExplanLabel[a]->setVisible(true);
	}
	switch (((Node*)pSender)->getTag())
	{
	case 0:
		ExplanLabel[0]->setString("");
		ExplanLabel[1]->setString("");
		ExplanLabel[2]->setString("");
		ExplanLabel[3]->setString("");
		break;
	case 1:
		ExplanLabel[0]->setString("");
		ExplanLabel[1]->setString("");
		ExplanLabel[2]->setString("");
		ExplanLabel[3]->setString("");
		break;
	case 2:
		ExplanLabel[0]->setString("");
		ExplanLabel[1]->setString("");
		ExplanLabel[2]->setString("");
		ExplanLabel[3]->setString("");
		break;
	case 3:
		ExplanLabel[0]->setString("");
		ExplanLabel[1]->setString("");
		ExplanLabel[2]->setString("");
		ExplanLabel[3]->setString("");
		break;
	case 4:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("쌀");
		ExplanLabel[1]->setString("아시아, 인도 지역에서 집중적으로 생산되는 농산물이다.\n비 유럽 지역들의 주식이다. ");
		ExplanLabel[2]->setString("한 섬당 가격: 200$");
		break;
	case 5:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("감자");
		ExplanLabel[1]->setString("다양한 지역에서 고르게 생산되는 농산물이다.\n대표적인 구황작물로 식량 부족 현상을 해소시키는데 큰 기여를 하고 있다.");
		ExplanLabel[2]->setString("한 가마니당 가격: 150$");
		break;
	case 6:
		Choicespr->setPosition(Vec2(420 + 147*2, 440 + ADD));
		ExplanLabel[0]->setString("밀");
		ExplanLabel[1]->setString("아메리카에서 주로 생산되며 타 지역에서도 생산이 활발하다.\n아메리카, 유럽 지역의 주식으로 사용된다.");
		ExplanLabel[2]->setString("한 가마니당 가격: 180$");
		break;
	case 7:
		Choicespr->setPosition(Vec2(420 + 147*3, 440 + ADD));
		ExplanLabel[0]->setString("파");
		ExplanLabel[1]->setString("중국에서 재배되며 서양권에서는 잘 소비하지 않는 생산물이다.\n조리법에 따라 다양한 맛과 강한 향을 가지고 있기에 여러가지 요리에 폭넓게 쓰인다.");
		ExplanLabel[2]->setString("한 줌당 가격: 250$");
		break;
	case 8:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("조개");
		ExplanLabel[1]->setString("해양지역에서 생산되는 해산물이다.\n각종 요리에 메인 재료, 고명 등으로 활용된다.");
		ExplanLabel[2]->setString("한 상자당 가격: 400$");
		break;
	case 9:
		Choicespr->setPosition(Vec2(420+147, 440 + ADD));
		ExplanLabel[0]->setString("생선");
		ExplanLabel[1]->setString("다양한 지역에서 고르게 생산하는 해산물이다.\n아시아, 유럽 등 지역마다 조리법이 존재한다.");
		ExplanLabel[2]->setString("한 상자당 가격: 350$");
		break;
	case 10:
		Choicespr->setPosition(Vec2(420+147*2, 440 + ADD));
		ExplanLabel[0]->setString("바닷가재");
		ExplanLabel[1]->setString("미국 연안에서 많이 생산되는 해산물이다.\n유럽지역에서 특히 고급요리로 취급된다.");
		ExplanLabel[2]->setString("한 상자당 가격: 800$");
		break;
	case 11:
		Choicespr->setPosition(Vec2(420+147*3, 440 + ADD));
		ExplanLabel[0]->setString("오징어");
		ExplanLabel[1]->setString("아시아, 서유럽 등에서 생산되는 해산물이다.\n식용과 더불어 먹물을 잉크 대용으로 사용한다.");
		ExplanLabel[2]->setString("한 상자당 가격: 450$");
		break;
	case 12:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("다이아몬드");
		ExplanLabel[1]->setString("아프리카 지역에서 주로 생산되는 보석이다.\n가장 대표적인 보석으로 부의 상징이 되기도 한다.");
		ExplanLabel[2]->setString("1개당 가격: 8000$");
		break;
	case 13:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("루비");
		ExplanLabel[1]->setString("아프리카 지역에서 주로 생산되는 보석이다.\n붉은 빛이 나며 다이아몬드 다음으로 가장 귀중하다고 여겨진다.");
		ExplanLabel[2]->setString("1개당 가격: 5000$");
		break;
	case 14:
		Choicespr->setPosition(Vec2(420 + 147 * 2, 440 + ADD));
		ExplanLabel[0]->setString("에메랄드");
		ExplanLabel[1]->setString("아프리카 지역에서 주로 생산되는 보석이다.\n초록 빛을 내며 어두운 밤에도 빛을 내는 신비함으로 인해 호신용으로 사용하기도 한다.");
		ExplanLabel[2]->setString("1개당 가격: 1500$");
		break;
	case 15:
		Choicespr->setPosition(Vec2(420 + 147 * 3, 440 + ADD));
		ExplanLabel[0]->setString("진주");
		ExplanLabel[1]->setString("조개에서 희귀하게 얻을 수 있는 보석이다.\n다양한 모양이 존재하며 예쁜 모양일수록 가격이 증가한다.");
		ExplanLabel[2]->setString("1개당 가격: 3000$");
		break;
	case 16:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("철");
		ExplanLabel[1]->setString("아메리카, 유럽 지역에서 많이 생산되는 금속이다.\n가공이 쉬워 여러 물건을 만드는데 사용된다.");
		ExplanLabel[2]->setString("1kg당 가격: 300$");
		break;
	case 17:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("금");
		ExplanLabel[1]->setString("아프리카 지역에서 많이 생산되는 금속이다.\n부의 상징으로 각종 치장품에 많이 사용된다.");
		ExplanLabel[2]->setString("1kg당 가격: 2000$");
		break;
	case 18:
		Choicespr->setPosition(Vec2(420 + 147 * 2, 440 + ADD));
		ExplanLabel[0]->setString("은");
		ExplanLabel[1]->setString("아프리카, 아메리카, 유럽 등 다양한 지역에서 생산되는 금속이다.\n치장품에도 사용 되며, 화폐대용으로 사용되기도 한다.");
		ExplanLabel[2]->setString("1kg당 가격: 800$");
		break;
	case 19:
		Choicespr->setPosition(Vec2(420 + 147 * 3, 440 + ADD));
		ExplanLabel[0]->setString("구리");
		ExplanLabel[1]->setString("아프리카 지역에서 생산되는 금속이다.\n동상이나 종, 대포 등을 만들 때 사용된다.");
		ExplanLabel[2]->setString("1kg당 가격: 400$");
		break;
	case 20:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("가죽");
		ExplanLabel[1]->setString("다양한 지역에서 생산하는 옷감이다.\n동물의 껍질이며 가공 기술이 부족해동 사용할 수 있다.");
		ExplanLabel[2]->setString("1필당 가격: 500$");
		break;
	case 21:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("비단");
		ExplanLabel[1]->setString("중국에서 주로 생산되는 옷감이다.\n최고의 천이라 불리며 부의 상징인 옷감이다.");
		ExplanLabel[2]->setString("1필당 가격: 1000$");
		break;
	case 22:
		Choicespr->setPosition(Vec2(420 + 147 * 2, 440 + ADD));
		ExplanLabel[0]->setString("면");
		ExplanLabel[1]->setString("많은 지역에서 다양하게 생산되는 옷감이다.\n낮은 가격으로 인해 보편화된 옷감이다.");
		ExplanLabel[2]->setString("1필당 가격: 450$");
		break;
	case 23:
		Choicespr->setPosition(Vec2(420 + 147 * 3, 440 + ADD));
		ExplanLabel[0]->setString("리넨");
		ExplanLabel[1]->setString("가죽을 가공하여 만든 옷감이다.\n갑옷 등의 두꺼운 재질의 옷을 만드는데 사용된다.");
		ExplanLabel[2]->setString("1필당 가격: 600$");
		break;
	}
}

void Inventory::IconCreate(LayerColor * layer)
{
	Icon[0] = Sprite::create();
	Icon[1] = Sprite::create();
	Icon[2] = Sprite::create();
	Icon[3] = Sprite::create();
	Icon[4] = Sprite::create("truck/agricultural/rice.png");
	Icon[5] = Sprite::create("truck/agricultural/Potato.png");
	Icon[6] = Sprite::create("truck/agricultural/wheat.png");
	Icon[7] = Sprite::create("truck/agricultural/S_onion.png");
	Icon[8] = Sprite::create("truck/seafood/clam.png");
	Icon[9] = Sprite::create("truck/seafood/fish.png");
	Icon[10] = Sprite::create("truck/seafood/lobster.png");
	Icon[11] = Sprite::create("truck/seafood/squid.png");
	Icon[12] = Sprite::create("truck/jewel/diamond.png");
	Icon[13] = Sprite::create("truck/jewel/ruby.png");
	Icon[14] = Sprite::create("truck/jewel/emerald.png");
	Icon[15] = Sprite::create("truck/jewel/pearl.png");
	Icon[16] = Sprite::create("truck/mineral/iron.png");
	Icon[17] = Sprite::create("truck/mineral/gold.png");
	Icon[18] = Sprite::create("truck/mineral/silver.png");
	Icon[19] = Sprite::create("truck/mineral/copper.png");
	Icon[20] = Sprite::create("truck/cloth/skin.png");
	Icon[21] = Sprite::create("truck/cloth/silk.png");
	Icon[22] = Sprite::create("truck/cloth/cloth.png");
	Icon[23] = Sprite::create("truck/cloth/linen.png");
	for (int i = 0; i < 24; i++)
	{
		Icon[i]->setScale(SCALE);
	}

	///////설명구간//////
	Bgexplan = Sprite::create("Chest/information.png");
	Bgexplan->setPosition(Vec2(640, 230+ ADD));
	Bgexplan->setScale(SCALE);
	InventoryLayer->addChild(Bgexplan);// 설며배경
	MAXbar = Sprite::create("ShipMove/Hpbar01.png");
	MAXbar->setAnchorPoint(Vec2(0, 0.5));
	MAXbar->setPosition(Vec2(345, 125));
	MAXbar->setScaleX(((float)UserDefault::getInstance()->getIntegerForKey("HMAX")/ UserDefault::getInstance()->getIntegerForKey("MAX")));
	InventoryLayer->addChild(MAXbar);
	for (int a = 0; a < 3; a++)
	{
		InventoryLayer->addChild(ExplanLabel[a]);
	}
	for (int a = 0; a < 6; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			Icon[a * 4 + i]->setPosition(Vec2(420 + i * 147, 440 + ADD));
			Icon[a * 4 + i]->setScale(0.25);
			invenmaterial[a]->addChild(Icon[a * 4 + i]);

			CountLabel[a * 4 + i] = Label::create("x0", "fonts/JejuGothic-Regular.ttf", 25);
			CountLabel[a * 4 + i]->setColor(Color3B(255, 255, 255));
			CountLabel[a * 4 + i]->setPosition(Vec2(445 + i * 147, 400 + ADD));
			invenmaterial[a]->addChild(CountLabel[a * 4 + i]);
		}
	}
	for (int i = 0; i < 24; i++)
	{
		ChangeLabel(i);
	}
}

