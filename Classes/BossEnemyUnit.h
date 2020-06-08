#pragma once
#include "Unit.h"


USING_NS_CC;
class BossEnemyUnit : public Unit
{
private:
	int hptest = 0;

public:

	BossEnemyUnit(Layer *layer , int red);

	virtual void hpbar(Layer *layer);
	virtual void walkani();
	virtual void hitani(); //맞는 애니메이션
	virtual void atkani(); //때리는 애니메이션
	virtual void dieani(); //죽는 애니메이션

	virtual void ex();
	//Animate* animate[6];

};