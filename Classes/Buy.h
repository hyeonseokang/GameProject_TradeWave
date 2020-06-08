#pragma once
#include "cocos2d.h"
#include "TradeUI.h"
#include "cocos-ext.h"
#include "Inventory.h"
USING_NS_CC_EXT;
USING_NS_CC;
class Buy :public TradeUI
{
public:
	Inventory *inven;
	
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
public :
	void TradeInit(LayerColor *layer, int *price, int *have, int *Money,Inventory *_in);
	//��ũ�� ����ǰ///
	int ADDVec2 = 125;
	bool secretbool=false;
	int secret;
	int secretChoice = 0;
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
	Sprite *FinalMaterial;//������ ��ų��Ȱ��� �����»���
	MenuItemImage *Next; // ���� �÷���
	MenuItemImage *Back; // ���� ���̳ʽ� 
	MenuItemImage *BSbutton; //���� �����Ǹ� ��ư 


	void MaterialMenu(Ref *pSender); //���� ����
	MenuItemImage *MaterialButton[24];
	Sprite *PhotoTruck[24];
	Sprite *PhotoMaterial[24];
	Label *LabelMaterial[24];
	Label *PriceMaterial[24]; //���� ��������
	Label *LloadPrice[24]; //�ü��� ��ȭ ǥ�� 
	Sprite *loadPriceUD[24];//�ü�����ȭ ��������Ʈǥ��
	float loadPrice[24];//������
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


public:
	void Setloadprice();
};