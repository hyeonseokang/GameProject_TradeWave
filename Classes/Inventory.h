#pragma once
#include "cocos2d.h"
#include"InventoryUI.h"
class Inventory :public InventoryUI
{
public:
	void ChangeLabel(int index);
	int *hprice; //������ �ִ� ǰ�� 
	LayerColor *InventoryLayer;
	LayerColor *invenmaterial[6];
	//1-��깰 2-�ػ깰 3-�ʰ� 4-��ŷ� 5-���� 6-���� 
	void InventoryInit(Layer *layer,int *have);
	void Explan(Ref*pSender);
	Menu *IconMenu[6];
	MenuItemImage *IconButton[24];//������ Ŭ�� ��ư 
	Label *CountLabel[24];
	Sprite *Icon[24];//������
	Sprite *Choicespr;//���� ǥ�� 
	void IconCreate(LayerColor *layer);
	//���� 
	Sprite *MAXbar;//�ִ����緮 ǥ��
	Sprite *Bgexplan;
	Label* ExplanLabel[3];

};
