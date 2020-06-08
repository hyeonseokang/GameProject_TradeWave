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
		label[0]->setString("��");
		label[1]->setString("�ƽþ�, �ε� �������� ���������� ����Ǵ� ��깰�̴�.\n�� ���� �������� �ֽ��̴�. ");
		label[2]->setString("�� ���� ����: 200$");
		SelectLabel = L_Farming;
		SelectCategory = Category01;
		SelectLayer = FarmingLayer;
		break;
	case 3:
		label[0]->setString("����");
		label[1]->setString("�ؾ��������� ����Ǵ� �ػ깰�̴�.\n���� �丮�� ���� ���, ��� ������ Ȱ��ȴ�.");
		label[2]->setString("�� ���ڴ� ����: 400$");
		SelectLabel = L_Seafood;
		SelectCategory = Category02;
		SelectLayer = SeafoodLayer;
		break;
	case 4:
		label[0]->setString("���̾Ƹ��");
		label[1]->setString("������ī �������� �ַ� ����Ǵ� �����̴�.\n���� ��ǥ���� �������� ���� ��¡�� �Ǳ⵵ �Ѵ�.");
		label[2]->setString("1���� ����: 8000$");
		SelectLabel = L_Jewelry;
		SelectCategory = Category03;
		SelectLayer = JewelryLayer;
		break;
	case 5:
		label[0]->setString("ö");
		label[1]->setString("�Ƹ޸�ī, ���� �������� ���� ����Ǵ� �ݼ��̴�.\n������ ���� ���� ������ ����µ� ���ȴ�.");
		label[2]->setString("1kg�� ����: 300$");
		SelectLabel = L_Mineral;
		SelectCategory = Category04;
		SelectLayer = MineralLayer;
		break;
	case 6:
		label[0]->setString("����");
		label[1]->setString("�پ��� �������� �����ϴ� �ʰ��̴�.\n������ �����̸� ���� ����� �����ص� ����� �� �ִ�.");
		label[2]->setString("1�ʴ� ����: 500$");
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
