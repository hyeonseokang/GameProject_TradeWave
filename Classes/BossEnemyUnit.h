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
	virtual void hitani(); //�´� �ִϸ��̼�
	virtual void atkani(); //������ �ִϸ��̼�
	virtual void dieani(); //�״� �ִϸ��̼�

	virtual void ex();
	//Animate* animate[6];

};