#pragma once
#include "Unit.h"


USING_NS_CC;
class HPUnit : public Unit
{
private:

	int hptest = 0;

public:

	//ü�� �߰� : �ִ� ü���� �þ , ���� ü�� + �þ ü�� , 
	//���� ����� : �ִ� ü���� ���ƿ� , �ִ�ġ �̻��� ü���� �ִ�ġ�� , �ִ�ġ ���ϸ� �״��


	HPUnit(Layer *layer , int red);

	virtual void hpbar(Layer *layer);
	virtual void walkani();
	virtual void hitani(); //�´� �ִϸ��̼�
	virtual void atkani(); //������ �ִϸ��̼�
	virtual void dieani(); //�״� �ִϸ��̼�
	virtual void ex();
	//Animate* animate[6];

};