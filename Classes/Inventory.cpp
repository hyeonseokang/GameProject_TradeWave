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
	ExplanLabel[0] = Label::create("����", "fonts/JejuGothic-Regular.ttf", 35, Size(600, 200), TextHAlignment::LEFT);
	ExplanLabel[0]->setColor(Color3B(255, 255, 255));
	ExplanLabel[0]->setAnchorPoint(Vec2(0, 0.5));
	ExplanLabel[0]->setPosition(Vec2(360, 295-85 + ADD));
	ExplanLabel[1] = Label::create("�پ��� �������� �����ϴ� �ʰ��̴�.\n������ �����̸� ���� ����� �����ص� ����� �� �ִ�."
		, "fonts/JejuGothic-Regular.ttf", 20, Size(600, 200), TextHAlignment::LEFT);
	ExplanLabel[1]->setColor(Color3B(255, 255, 255));
	ExplanLabel[1]->setAnchorPoint(Vec2(0, 0.5));
	ExplanLabel[1]->setPosition(Vec2(360, 295 - 135 + ADD));
	ExplanLabel[2] = Label::create("1�ʴ� ����: 500$", "fonts/JejuGothic-Regular.ttf", 35, Size(600, 200), TextHAlignment::LEFT);
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
		ExplanLabel[0]->setString("��");
		ExplanLabel[1]->setString("�ƽþ�, �ε� �������� ���������� ����Ǵ� ��깰�̴�.\n�� ���� �������� �ֽ��̴�. ");
		ExplanLabel[2]->setString("�� ���� ����: 200$");
		break;
	case 5:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("����");
		ExplanLabel[1]->setString("�پ��� �������� ���� ����Ǵ� ��깰�̴�.\n��ǥ���� ��Ȳ�۹��� �ķ� ���� ������ �ؼҽ�Ű�µ� ū �⿩�� �ϰ� �ִ�.");
		ExplanLabel[2]->setString("�� �����ϴ� ����: 150$");
		break;
	case 6:
		Choicespr->setPosition(Vec2(420 + 147*2, 440 + ADD));
		ExplanLabel[0]->setString("��");
		ExplanLabel[1]->setString("�Ƹ޸�ī���� �ַ� ����Ǹ� Ÿ ���������� ������ Ȱ���ϴ�.\n�Ƹ޸�ī, ���� ������ �ֽ����� ���ȴ�.");
		ExplanLabel[2]->setString("�� �����ϴ� ����: 180$");
		break;
	case 7:
		Choicespr->setPosition(Vec2(420 + 147*3, 440 + ADD));
		ExplanLabel[0]->setString("��");
		ExplanLabel[1]->setString("�߱����� ���Ǹ� ����ǿ����� �� �Һ����� �ʴ� ���깰�̴�.\n�������� ���� �پ��� ���� ���� ���� ������ �ֱ⿡ �������� �丮�� ���а� ���δ�.");
		ExplanLabel[2]->setString("�� �ܴ� ����: 250$");
		break;
	case 8:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("����");
		ExplanLabel[1]->setString("�ؾ��������� ����Ǵ� �ػ깰�̴�.\n���� �丮�� ���� ���, ��� ������ Ȱ��ȴ�.");
		ExplanLabel[2]->setString("�� ���ڴ� ����: 400$");
		break;
	case 9:
		Choicespr->setPosition(Vec2(420+147, 440 + ADD));
		ExplanLabel[0]->setString("����");
		ExplanLabel[1]->setString("�پ��� �������� ���� �����ϴ� �ػ깰�̴�.\n�ƽþ�, ���� �� �������� �������� �����Ѵ�.");
		ExplanLabel[2]->setString("�� ���ڴ� ����: 350$");
		break;
	case 10:
		Choicespr->setPosition(Vec2(420+147*2, 440 + ADD));
		ExplanLabel[0]->setString("�ٴ尡��");
		ExplanLabel[1]->setString("�̱� ���ȿ��� ���� ����Ǵ� �ػ깰�̴�.\n������������ Ư�� ��޿丮�� ��޵ȴ�.");
		ExplanLabel[2]->setString("�� ���ڴ� ����: 800$");
		break;
	case 11:
		Choicespr->setPosition(Vec2(420+147*3, 440 + ADD));
		ExplanLabel[0]->setString("��¡��");
		ExplanLabel[1]->setString("�ƽþ�, ������ ��� ����Ǵ� �ػ깰�̴�.\n�Ŀ�� ���Ҿ� �Թ��� ��ũ ������� ����Ѵ�.");
		ExplanLabel[2]->setString("�� ���ڴ� ����: 450$");
		break;
	case 12:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("���̾Ƹ��");
		ExplanLabel[1]->setString("������ī �������� �ַ� ����Ǵ� �����̴�.\n���� ��ǥ���� �������� ���� ��¡�� �Ǳ⵵ �Ѵ�.");
		ExplanLabel[2]->setString("1���� ����: 8000$");
		break;
	case 13:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("���");
		ExplanLabel[1]->setString("������ī �������� �ַ� ����Ǵ� �����̴�.\n���� ���� ���� ���̾Ƹ�� �������� ���� �����ϴٰ� ��������.");
		ExplanLabel[2]->setString("1���� ����: 5000$");
		break;
	case 14:
		Choicespr->setPosition(Vec2(420 + 147 * 2, 440 + ADD));
		ExplanLabel[0]->setString("���޶���");
		ExplanLabel[1]->setString("������ī �������� �ַ� ����Ǵ� �����̴�.\n�ʷ� ���� ���� ��ο� �㿡�� ���� ���� �ź������� ���� ȣ�ſ����� ����ϱ⵵ �Ѵ�.");
		ExplanLabel[2]->setString("1���� ����: 1500$");
		break;
	case 15:
		Choicespr->setPosition(Vec2(420 + 147 * 3, 440 + ADD));
		ExplanLabel[0]->setString("����");
		ExplanLabel[1]->setString("�������� ����ϰ� ���� �� �ִ� �����̴�.\n�پ��� ����� �����ϸ� ���� ����ϼ��� ������ �����Ѵ�.");
		ExplanLabel[2]->setString("1���� ����: 3000$");
		break;
	case 16:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("ö");
		ExplanLabel[1]->setString("�Ƹ޸�ī, ���� �������� ���� ����Ǵ� �ݼ��̴�.\n������ ���� ���� ������ ����µ� ���ȴ�.");
		ExplanLabel[2]->setString("1kg�� ����: 300$");
		break;
	case 17:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("��");
		ExplanLabel[1]->setString("������ī �������� ���� ����Ǵ� �ݼ��̴�.\n���� ��¡���� ���� ġ��ǰ�� ���� ���ȴ�.");
		ExplanLabel[2]->setString("1kg�� ����: 2000$");
		break;
	case 18:
		Choicespr->setPosition(Vec2(420 + 147 * 2, 440 + ADD));
		ExplanLabel[0]->setString("��");
		ExplanLabel[1]->setString("������ī, �Ƹ޸�ī, ���� �� �پ��� �������� ����Ǵ� �ݼ��̴�.\nġ��ǰ���� ��� �Ǹ�, ȭ�������� ���Ǳ⵵ �Ѵ�.");
		ExplanLabel[2]->setString("1kg�� ����: 800$");
		break;
	case 19:
		Choicespr->setPosition(Vec2(420 + 147 * 3, 440 + ADD));
		ExplanLabel[0]->setString("����");
		ExplanLabel[1]->setString("������ī �������� ����Ǵ� �ݼ��̴�.\n�����̳� ��, ���� ���� ���� �� ���ȴ�.");
		ExplanLabel[2]->setString("1kg�� ����: 400$");
		break;
	case 20:
		Choicespr->setPosition(Vec2(420, 440 + ADD));
		ExplanLabel[0]->setString("����");
		ExplanLabel[1]->setString("�پ��� �������� �����ϴ� �ʰ��̴�.\n������ �����̸� ���� ����� �����ص� ����� �� �ִ�.");
		ExplanLabel[2]->setString("1�ʴ� ����: 500$");
		break;
	case 21:
		Choicespr->setPosition(Vec2(420 + 147, 440 + ADD));
		ExplanLabel[0]->setString("���");
		ExplanLabel[1]->setString("�߱����� �ַ� ����Ǵ� �ʰ��̴�.\n�ְ��� õ�̶� �Ҹ��� ���� ��¡�� �ʰ��̴�.");
		ExplanLabel[2]->setString("1�ʴ� ����: 1000$");
		break;
	case 22:
		Choicespr->setPosition(Vec2(420 + 147 * 2, 440 + ADD));
		ExplanLabel[0]->setString("��");
		ExplanLabel[1]->setString("���� �������� �پ��ϰ� ����Ǵ� �ʰ��̴�.\n���� �������� ���� ����ȭ�� �ʰ��̴�.");
		ExplanLabel[2]->setString("1�ʴ� ����: 450$");
		break;
	case 23:
		Choicespr->setPosition(Vec2(420 + 147 * 3, 440 + ADD));
		ExplanLabel[0]->setString("����");
		ExplanLabel[1]->setString("������ �����Ͽ� ���� �ʰ��̴�.\n���� ���� �β��� ������ ���� ����µ� ���ȴ�.");
		ExplanLabel[2]->setString("1�ʴ� ����: 600$");
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

	///////������//////
	Bgexplan = Sprite::create("Chest/information.png");
	Bgexplan->setPosition(Vec2(640, 230+ ADD));
	Bgexplan->setScale(SCALE);
	InventoryLayer->addChild(Bgexplan);// ������
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

