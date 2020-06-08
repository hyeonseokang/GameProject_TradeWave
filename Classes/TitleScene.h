#ifndef __TitleScene_H__
#define __TitleScene_H__

#include"cocos2d.h"
USING_NS_CC;
class TitleScene : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();
	virtual bool onTouchBegan(Touch* touch, Event* unsed_event);
	// a selector callback
	void menuCloseCallback(Ref* pSender);
	void Start_changeScene(Ref* sender);
	bool enabled;

	//void LoadingCallback(Texture2D*texture);
	//void LoadingTexture();
	//int LoadingTexturenum = 0;
	//int LoadingAllTexture = 53;
	//Label *LoadingPercent;
	// implement the "static create()" method manually
	CREATE_FUNC(TitleScene);
};

#endif // __HELLOWORLD_SCENE_H__
