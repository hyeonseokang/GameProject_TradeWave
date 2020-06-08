#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Credit : public LayerColor
{
public:
	static Scene* createScene();
	CREATE_FUNC(Credit);
	virtual bool init();
	Label*label[20];
	Sprite*NameSpr[4][2];
	Label*NameLabel[4][2];
	int count_A, count_B;
	void update(float dt);
	void Particle_manager(int num, Vec2 pos);
	bool onTouchBegan(Touch *touch, Event *event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
};