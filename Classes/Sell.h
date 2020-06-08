#pragma once
#include "cocos2d.h"
#include "TradeUI.h"
#include "cocos-ext.h"
#include"Inventory.h"
USING_NS_CC;
USING_NS_CC_EXT;
class Sell :public TradeUI
{
public:
	int *bprice; // ���� 
	int *hprice; //������ �ִ� ǰ�� 
	int *money; //��
	LayerColor *TradeLayer; // ������ ����Ĵ� ���̾�

	ScrollView *scrollview;
	LayerColor *ScrollLayer;
	LayerColor *FarmingMaterial;
	LayerColor *SeafoodMaterial;
	LayerColor *JewelryMaterial;
	LayerColor *MineralMaterial;
	LayerColor *ClothMaterial;
public:
	Inventory *inven;
	void TradeInit(LayerColor *layer, int *price, int *have, int *Money,Inventory *_in);
	//��ũ�� ����ǰ///
	bool secretbool = false;
	int ADDVec2 = 125;
	int secretmoney = 0;
	int secretChoice = 0;
	int havesecret = 0;
	int secret;
	Menu *SecretMenu;
	MenuItemImage *SecretButton;
	Sprite *SecretTruck;
	Sprite *Material;
	Label *SecretPrice;
	Label *SecretName;
	///////////
	void FinalBS(int Material, int Count);
	int Count = 0;
	int Materialcount = 0;
	void Final(Ref *pSender);
	LayerColor *FinalLayer;//���� ���̾�
	Sprite *MAXbar; //���緮 ǥ�� ������
	Sprite *BgFinal; //���� ��������Ʈ
	Menu *FinalMenu;
	MenuItemImage *FinalClose; //���̾�ݱ� 
	Label *MaterialLabel; // ������ ��ų� �Ǹ��ϴ��� ���� ��
	Label *CountLabel; // ��� ��ų� �Ǹ��ϴ��� ���� �� 
	Sprite *CountSprite; // CountLabel ���� �ѷ��ִ� ��������Ʈ 
	Label *MoneyCountLabel; //�� ���� �� Count * bprice 
	Sprite *Photo; //������ ��ų��Ȳ��� ������� 
	Sprite *FinalMaterial;
	MenuItemImage *Next; // ���� �÷���
	MenuItemImage *Back; // ���� ���̳ʽ� 
	MenuItemImage *BSbutton; //���� �����Ǹ� ��ư 

	Sprite *loadPriceUD[24];//�ü�����ȭ ��������Ʈǥ��
	void MaterialMenu(Ref *pSender); //���� ����
	MenuItemImage *MaterialButton[24];
	Sprite*PhotoTruck[24];
	Sprite *PhotoMaterial[24];
	Label *LabelHMaterial[24];
	Label *LabelMaterial[24];
	Label *PriceMaterial[24];
	// ��ŷ� 
	void FarmingMenu(LayerColor *layer);
	Menu *FarmingBmenu;
	// ��깰
	void SeafoodMenu(LayerColor *layer);
	Menu *SeafoodBmenu;
	// �ػ깰
	void JewelryMenu(LayerColor *layer);
	Menu *JewelryBmenu;
	// ����
	void MineralMenu(LayerColor *layer);
	Menu *MineralBmenu;
	// ����
	void ClothMenu(LayerColor *layer);
	Menu *ClothBmenu;
	// �ʰ�
	 
	void Setloadprice();
	float loadPrice[24];
	Label *LloadPrice[24]; //�ü��� ��ȭ ǥ�� 
};
