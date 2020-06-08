#pragma once
#include "cocos2d.h"
#include "Slider.h"

USING_NS_CC;

/////////////////////
//EnemyUnit -> 기본 해적        // 강화 시 -> 기본 스텟 상승
//BossEnemyUnit -> 공격력 해적  // 강화 시 -> 공격 버프를 줌 & 더 강한 공격력
//HPUnit -> 체력 버프 해적      // 강화 시 -> 체력 버프를 줌 & 더 강한 체력
//BombUnit -> 속도 해적         // 강화 시 -> 속도 버프를 줌 & 더 빠른 속도


class Unit
{
protected:
	int atk;  //공격력
	int hp;   //체력
	int kahp; //변하지 않는 체력 , 즉 최대 체력

	RepeatForever* Walk;

	bool hpboss; //체력 버프를 받았는가?

	int abc;   //이동 방향
	bool dashtest = false; //대쉬중이냐?
	bool hpbuff;    //체력 버프를 주는가 , 아닌가


	bool atktest = false; //공격중인가 , 아닌가
	bool walktest = false; //걷는중인가 , 아닌가
	
	bool end = false;  //도착했는가
	bool tower;  //타워인지 아닌지
	bool timer = true;  //공격 딜레이


public:
	void fight(int updown, int unitnum, int a); 	//이동
	virtual void walkani() {};		//걷는
	virtual void hitani() {};		//맞는
	virtual void atkani() {};		//때리는
	virtual void dieani() {};		//죽는
	virtual void ex() {};			//공격 딜레이

	void hpapply(int judge);

	virtual void hpbar(Layer *layer) {};

	Animation* animation;
	Animation* Dashanimation;
	Animate* dashanimate;
	Animate* dashanimate2;

	Animate* walkanimate;
	Animate* hitanimate; //맞는 애니메이션
	Animate* atkanimate; //때리는 애니메이션
	Animate* dieanimate;
	Sprite *sprite;
	UIProgressBar * progressBar; // 코어 체력바

	virtual void Brr() {};

	int Gethp();
	void Sethp(int _hp);

	int Getkahp();
	void Setkahp(int _kahp);

	bool Getend();
	void Setend(bool _end);

	int Getatk();
	void Setatk(int _atk);

	bool Gettimer();
	void Settimer(bool _timer);


	bool Gethpboss();
	void Sethpboss(bool _hpboss);


	bool Gethpbuff();



	int Getabc();

	void Create(int _x, int _y, Layer *layer);
	void Destroy();

};