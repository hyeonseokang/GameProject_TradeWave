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
	int AreaNum = 0;// ���� ���� 
	bool Push;
	///////////////////////////////// �¼��κ�
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
	Trade*trade; // ������ 
	Shipyard *shipyard;
	void BgMainMenu();
	Sprite * BgMap; // ���� �޴� �޹�� ������ 
	Sprite *BgGold; // ������� ,���̾Ƹ�� ,�������� �޹�� 
	Label * ab_label[5];
	Sprite *Pop;
	Sprite *BgArea; //���� ���� ����ǥ�� �ڽ� �޹�� 
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
	MenuItemImage *OptionButton; // �ɼ� ��ư
	MenuItemImage *TradeButton; // ������ ��ư 
	MenuItemImage *ShipyardButton; // �� ���׷��̵� ��ư ������
	MenuItemImage *EmbarkButton; // ���� ��ư
	MenuItemImage *InventoryButton; // �κ��丮 ��ư 

	void StatusLabel();
	Label *AreaLabel;
	Label *GoldLabel;
	void GoldCheck(float delta);
	Label *DiamondLabel;
	Label *DaysLabel;//���س�¥
	Label *TitleLabel;//�Īȣ

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

	//����
	int Disaster();
	LayerColor *Disaterlayer;
	LayerColor *Titlelayer;
	Label *DisLabel[6];
	void TitleOn();


	//Ʃ�丮��
	Sprite *_tutorialtalk;
	void tutorial();
	int _tutorialLevel = 0;
	Label*_talklabel;
	Sprite*spot;
	Sprite*NPC;
	LayerColor*alayer;
	ClippingNode* cliper;
	void CharacterEYE(bool _eyemod);
	//����                             //KGSH
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


	Sprite *TitleSpr[2];//Īȣ 
	MenuItemSprite * T_button;
	Menu*TitleMenu;
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	
};
