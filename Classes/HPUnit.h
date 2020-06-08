#pragma once
#include "Unit.h"


USING_NS_CC;
class HPUnit : public Unit
{
private:

	int hptest = 0;

public:

	//체력 추가 : 최대 체력이 늘어남 , 현재 체력 + 늘어난 체력 , 
	//유닛 사망시 : 최대 체력은 돌아옴 , 최대치 이상의 체력은 최대치로 , 최대치 이하면 그대로


	HPUnit(Layer *layer , int red);

	virtual void hpbar(Layer *layer);
	virtual void walkani();
	virtual void hitani(); //맞는 애니메이션
	virtual void atkani(); //때리는 애니메이션
	virtual void dieani(); //죽는 애니메이션
	virtual void ex();
	//Animate* animate[6];

};