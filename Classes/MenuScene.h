#pragma once
#include"Trade.h"
#include"Inventory.h"
#include"cocos2d.h"
#include"Shipyard.h"
#include "Slider.h"

USING_NS_CC;

class MenuScene : public Layer
{
private:

public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MenuScene);

	UIProgressBar *progressBar;

	void menuCloseCallback(Ref* pSender);
	int AreaNum = 0;// 지역 들어가기 
	bool Push;
	///////////////////////////////// 승선부분
	void Bounce();

	ProgressTimer*HpProgress;

	Sprite* hp_font;
	float hp;
	float f_hp;
	Sprite*hp_bar; Sprite*hp_back;
	MoveBy *moveby;
	EaseIn *jump;
	EaseOut *jump2;
	MoveBy *moveby2;
	Sequence* Seq;
	RepeatForever* rep;
	//////////////////////////////////
	MenuItemImage*Belltten;
	Trade*trade; // 교역소 
	Shipyard *shipyard;
	void BgMainMenu();
	Sprite * BgMap; // 메인 메뉴 뒷배경 지도맵 
	Sprite *BgGold; // 보유골드 ,다이아몬드 ,항해일자 뒷배경 
	Label * ab_label[5];
	Sprite *Pop;
	Sprite *BgArea; //현재 거주 국가표시 박스 뒷배경 
	LayerColor *Optionlayer;
	void OptionCreate();
	Sprite* BgOption;
	bool BGM = true;
	bool effectBGM = true;
	void BGMonoff(Ref *pSender);
	Sprite* Check1;
	Sprite* Check2;
	MenuItemImage* closeoption;
	Menu *Close;
	Menu *BelltenMenu;
	Menu* insignia_Menu;
	void BgMainButton();
	Menu*MainMenu;
	MenuItemImage *OptionButton; // 옵션 버튼
	MenuItemImage *TradeButton; // 교역소 버튼 
	MenuItemImage *ShipyardButton; // 배 업그레이드 버튼 조선소
	MenuItemImage *EmbarkButton; // 항해 버튼
	MenuItemImage *InventoryButton; // 인벤토리 버튼 

	void StatusLabel();
	Label *AreaLabel;
	Label *GoldLabel;
	void GoldCheck(float delta);
	Label *DiamondLabel;
	Label *DaysLabel;//항해날짜
	Label *TitleLabel;//어떤칭호

	void OtherUI();
	Layer* insignia_Layer;

	void UI_push_pull(Ref* sender);
	void EmbarkON();
	bool EmbarkTF = false;
	void EmbarkCreate();
	MenuItemImage*EmbarkBack;
	void EmabrkMenuR(Ref*pSender);
	Sprite *SelectEmbark;
	Sprite *EmbarkA1;
	Sprite *EmbarkA2;
	Sprite *EmbarkA3;
	Sprite *EmbarkB1;
	Sprite *EmbarkB2;
	Sprite *EmbarkC1;
	Sprite *EmbarkC2;
	Menu *EmbarkMenu;
	MenuItemSprite*SelecMenu;
	MenuItemSprite*EmbarkA1B;
	MenuItemSprite*EmbarkA2B;
	MenuItemSprite*EmbarkA3B;
	MenuItemSprite*EmbarkB1B;
	MenuItemSprite*EmbarkB2B;
	MenuItemSprite*EmbarkC1B;
	MenuItemSprite*EmbarkC2B;
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);

	//재해
	int Disaster();
	LayerColor *Disaterlayer;
	LayerColor *Titlelayer;
	Label *DisLabel[6];
	void TitleOn();


	//튜토리얼
	Sprite *_tutorialtalk;
	void tutorial();
	int _tutorialLevel = 0;
	Label*_talklabel;
	Sprite*spot;
	Sprite*NPC;
	LayerColor*alayer;
	ClippingNode* cliper;
	void CharacterEYE(bool _eyemod);
	//뉴스                             //KGSH
	void News();
	void secondsnews30(float dt);
	void newslabel();
	Sprite*Bgnews;
	Sprite*BgMap2;
	Sprite*BgMap3;
	Label*NewsLabel;
	int num = 0;


	bool opened;
	void down();


	Sprite *TitleSpr[2];//칭호 
	MenuItemSprite * T_button;
	Menu*TitleMenu;
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	
};
