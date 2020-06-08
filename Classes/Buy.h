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
	
	int *bprice; // 가격 
	int *hprice; //가지고 있는 품목 
	int *money; //돈
	LayerColor *TradeLayer; // 교역소 사고파는 레이어
	ScrollView *scrollview;
	LayerColor *ScrollLayer;
	LayerColor *FarmingMaterial;
	LayerColor *SeafoodMaterial;
	LayerColor *JewelryMaterial;
	LayerColor *MineralMaterial;
	LayerColor *ClothMaterial;
public :
	void TradeInit(LayerColor *layer, int *price, int *have, int *Money,Inventory *_in);
	//시크릿 교역품///
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
	LayerColor *FinalLayer;//최종 레이어
	Sprite *MAXbar; //적재량 표시 게이지
	Sprite *BgFinal; //최종 스프라이트
	Menu *FinalMenu;
	MenuItemImage *FinalClose; //레이어닫기 
	Label *MaterialLabel; // 무엇을 사거나 판매하는지 설명 라벨
	Label *CountLabel; // 몇개를 사거나 판매하는지 설명 라벨 
	Sprite *CountSprite; // CountLabel 밑의 뿌려주는 스프라이트 
	Label *MoneyCountLabel; //얼마 설명 라벨 Count * bprice 
	Sprite *Photo; //무엇을 사거나팔껀지 설명사진 
	Sprite *FinalMaterial;//무엇을 사거나팔건지 나오는사진
	MenuItemImage *Next; // 갯수 플러스
	MenuItemImage *Back; // 갯수 마이너스 
	MenuItemImage *BSbutton; //최종 구매판매 버튼 


	void MaterialMenu(Ref *pSender); //쟤료 선택
	MenuItemImage *MaterialButton[24];
	Sprite *PhotoTruck[24];
	Sprite *PhotoMaterial[24];
	Label *LabelMaterial[24];
	Label *PriceMaterial[24]; //지금 가격포시
	Label *LloadPrice[24]; //시세율 변화 표시 
	Sprite *loadPriceUD[24];//시세율변화 스프라이트표시
	float loadPrice[24];//전가격
	// 향신료 
	void FarmingMenu(LayerColor *layer);
	Menu *FarmingBmenu;
	// 농산물
	void SeafoodMenu(LayerColor *layer);
	Menu *SeafoodBmenu;
	// 해산물
	void JewelryMenu(LayerColor *layer);
	Menu *JewelryBmenu;
	// 보석
	void MineralMenu(LayerColor *layer);
	Menu *MineralBmenu;
	// 광석
	void ClothMenu(LayerColor *layer);      
	Menu *ClothBmenu;
	// 옷감


public:
	void Setloadprice();
};