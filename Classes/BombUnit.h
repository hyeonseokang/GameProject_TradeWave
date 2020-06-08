#pragma once
#include "Unit.h"
USING_NS_CC;
class BombUnit : public Unit
{
public:

	int hptest = 0;

	BombUnit(Layer *layer , int red);

	virtual void hpbar(Layer *layer);

	virtual void walkani();  //걷는 애니메이션
	virtual void hitani(); //맞는 애니메이션
	virtual void atkani(); //때리는 애니메이션
	virtual void dieani(); //죽는 애니메이션
	virtual void ex();
	//Animate* animate[6];

};