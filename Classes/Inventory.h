#pragma once
#include "cocos2d.h"
#include"InventoryUI.h"
class Inventory :public InventoryUI
{
public:
	void ChangeLabel(int index);
	int *hprice; //가지고 있는 품목 
	LayerColor *InventoryLayer;
	LayerColor *invenmaterial[6];
	//1-농산물 2-해산물 3-옷감 4-향신료 5-광물 6-보석 
	void InventoryInit(Layer *layer,int *have);
	void Explan(Ref*pSender);
	Menu *IconMenu[6];
	MenuItemImage *IconButton[24];//아이콘 클릭 버튼 
	Label *CountLabel[24];
	Sprite *Icon[24];//아이콘
	Sprite *Choicespr;//선택 표시 
	void IconCreate(LayerColor *layer);
	//설명 
	Sprite *MAXbar;//최대적재량 표시
	Sprite *Bgexplan;
	Label* ExplanLabel[3];

};
