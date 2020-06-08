#pragma once
#include "cocos2d.h"

USING_NS_CC;

class SingleTon
{
private:
	static SingleTon *instant;
	SingleTon();
	~SingleTon();
public:
	static SingleTon * getinstance();
private:
	int _tutorial = 0;
	int _area;
	int shells;
	Vec2 ship_pos;
	Vec2 cam_pos;
	bool BeBack = false;
	int _titlemedal;//Īȣ
	int time;

	bool BGM = true;
	bool EFFECT = true;
public:
	bool getBGM()const;
	void setBGM(bool _BGM);
	bool getEFFECT()const;
	void setEFFECT(bool _EFFECT);
	int getTutorial()const;
	void setTutorial(int _tutorialN);
	int getTitle()const;
	bool setTitle(int _title);

	int getArea()const;
	void setArea(int __area);
	Vec2 getPos()const;
	void setPos(Vec2 pos);
	bool getBack()const;
	void setBack(bool back);
	Vec2 getCamPos()const;
	void setCamPos(Vec2 pos);
	int getShell()const;
	void setShell(int num);
	int getTime()const;
	void setTime(int t);
};
