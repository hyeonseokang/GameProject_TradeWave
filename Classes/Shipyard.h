#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "ScrollMenu.h"
USING_NS_CC;
USING_NS_CC_EXT;

using namespace CocosDenshion;

class Shipyard : public ScrollViewDelegate
{
public:
	ScrollView* scrollview;
	///////////////////////// ���׷��̵� ���
	int RepairCost;
	int ShipSpeedUpgradeCost;
	int ShipHpUpgradeCost;
	int ShipAtkUpgradeCost;
	int ShipSupplyUpgradeCost;
	///////////////////////// ���׷��̵� ��� ��

	int HowPopup;         // 0 ��Ų , ���׷��̵� ����â / 1 ���׷��̵� â / 2 ��Ų â
						  ////////////////////////// �˾� ���̾�
	Layer* UPLayer;
	Layer* CHLayer;
	Layer* SKLayer;

	/////////////////////////// �˾� �����ϴ� ��������Ʈ

	MenuItemImage* Close;

	Sprite* Choice;
	MenuItemImage* UpgradeChoice;
	MenuItemImage* SkinChoice;

	Sprite* Repair;
	Sprite* UpgradeSprite[5];
	MenuItemImage* RepairImage;
	MenuItemImage* UpgradeImage[4];

	Sprite* SkinBg;
	Sprite* Skin[4];
	Sprite* ShipSkin[4];
	MenuItemImage* SkinImage[4];


	Sprite* Upgrade[4];
	Sprite* UpgradeBg;

	Menu *ChoiceMenu;
	Menu *UpgradeMenu;
	Menu *SkinMenu;
	Menu *CloseMenu;
	Menu *HaveMenu;

	MenuItemImage* HaveSkin[4];
	Sprite* Install[4];
	Sprite* Max[4];

	////////////////////////////// ��
	Label *CostLabel[5];


	Label *NowHp;

	Label *AtkLabel;
	Label *AtkLabel2;

	Label *HpLabel;
	Label *HpLabel2;

	Label *SpeedLabel;
	Label *SpeedLabel2;

	Label *Supply;
	Label *Supply2;

	Label *ShipLabel[4];

	//////////////////////////////

	Shipyard(Layer*layer);
	void init();

	void Upgrade_PopUp();

	void Skin_PopUp();

	void Destroy();

	void ShipRepair();
	void MaxCheck();
	void ShipUpgrade(Ref* pSender);

	void BuySkin(Ref* pSender);
	void InstallSkin(Ref* pSender);
	void buyskin();
	void installskin();

};