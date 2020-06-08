#pragma once
#pragma execution_character_set("utf-8")

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Ship.h"
#include "Handle.h" 
#include "Priate_ship.h"
#include "Cannon.h"
#include "Singleton.h"
#include "Obstacle.h"

USING_NS_CC;

using namespace std;
class SailScene : public LayerColor
{
public:
	bool tutorialship = false;
	static Scene* createScene();
	CREATE_FUNC(SailScene);
	virtual bool init();
	//래이어
	Layer * inter_layer;
	Layer * back_layer;
	Layer * ship_layer;
	LayerColor * black;
	Layer * p_ship_layer;
	LayerColor * caution_layer;
	//대포알 벡터
	Cannon *can;
	//맵 및 오브젝트
	Obstacle *obs[8][20];
	int distance;
	Sprite*Background[21]; 
	Sprite*Dock; Sprite*success;
	Sprite*progress; Sprite*Pro_ship;
	Sprite*hp_bar; Sprite*hp_back;
	Sprite*abc;
	Sprite*arrow;
	Label*def;
	Label*end[4];
	Label*cheat_label;
	int b_count;
	ProgressTimer*HpProgress;
	ProgressTimer*p_HpProgress;
	ProgressTimer*Reload;
	ProgressTimer*ExpProgress;
	//생성
	Priate_ship*p_ship;
	Ship*ship;
	Handle*handle;
	//카메라
	Camera*main_cam; Camera*hud_cam;

	// #변수
	Vec2 BeganTouchPos; Vec2 EndedTouchPos;
	float hp; float p_hp;
	float f_hp;
	float began_pos;
	float H_angle;
	float S_angle;
	float S_speed;
	float angle;
	float length;
	int time;
	int damaged;
	int can_damge;
	bool p_dead;
	bool left; bool right;
	bool unbeatable;
	bool touched;
	bool can_active;
	bool BeBack;
	bool can_touched;
	bool can_delay;
	bool save;
	bool cheat1;
	bool cheat2;
	bool finish;
	// #그냥 함수
	Vec2 moving(Vec2 pos,float angle,float speed);
	void p_enabled(bool enabled);
	void pirate_set();
	void ship_damaged(int dmg, float dur);
	bool crash(Rect A, Rect B);
	bool CircleCollision(Vec2 point1, float fRad1, Vec2 point2, float fRad2);
	bool CircleVsRectCollision(Vec2 target1, Vec2 target2, float radian1, Rect rect2);

	// #스케줄
	void timer(float dt);
	void main_update(float dt);

	// #터치
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);

	//칭호
	int LoadEXP = 0;
	int addExp = 10;
	void setExp();


	//튜토리얼
	bool handlebool = true;
	Sprite *_tutorialtalk;
	void tutorial();
	int _tutorialLevel = 0;
	Label*_talklabel;
	Sprite*spot;
	Sprite*NPC;
	LayerColor*alayer;
	ClippingNode* cliper;
	bool cannontutorial = false;
	void CharacterEYE(bool _eyemod);
	void MainMenuGo(float dt);
	void BgmCh(float dt);


	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	//virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
};