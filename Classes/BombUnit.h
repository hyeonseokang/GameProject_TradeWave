#pragma once
#include "Unit.h"
USING_NS_CC;
class BombUnit : public Unit
{
public:

	int hptest = 0;

	BombUnit(Layer *layer , int red);

	virtual void hpbar(Layer *layer);

	virtual void walkani();  //�ȴ� �ִϸ��̼�
	virtual void hitani(); //�´� �ִϸ��̼�
	virtual void atkani(); //������ �ִϸ��̼�
	virtual void dieani(); //�״� �ִϸ��̼�
	virtual void ex();
	//Animate* animate[6];

};