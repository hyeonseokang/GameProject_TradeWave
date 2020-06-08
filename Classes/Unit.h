#pragma once
#include "cocos2d.h"
#include "Slider.h"

USING_NS_CC;

/////////////////////
//EnemyUnit -> �⺻ ����        // ��ȭ �� -> �⺻ ���� ���
//BossEnemyUnit -> ���ݷ� ����  // ��ȭ �� -> ���� ������ �� & �� ���� ���ݷ�
//HPUnit -> ü�� ���� ����      // ��ȭ �� -> ü�� ������ �� & �� ���� ü��
//BombUnit -> �ӵ� ����         // ��ȭ �� -> �ӵ� ������ �� & �� ���� �ӵ�


class Unit
{
protected:
	int atk;  //���ݷ�
	int hp;   //ü��
	int kahp; //������ �ʴ� ü�� , �� �ִ� ü��

	RepeatForever* Walk;

	bool hpboss; //ü�� ������ �޾Ҵ°�?

	int abc;   //�̵� ����
	bool dashtest = false; //�뽬���̳�?
	bool hpbuff;    //ü�� ������ �ִ°� , �ƴѰ�


	bool atktest = false; //�������ΰ� , �ƴѰ�
	bool walktest = false; //�ȴ����ΰ� , �ƴѰ�
	
	bool end = false;  //�����ߴ°�
	bool tower;  //Ÿ������ �ƴ���
	bool timer = true;  //���� ������


public:
	void fight(int updown, int unitnum, int a); 	//�̵�
	virtual void walkani() {};		//�ȴ�
	virtual void hitani() {};		//�´�
	virtual void atkani() {};		//������
	virtual void dieani() {};		//�״�
	virtual void ex() {};			//���� ������

	void hpapply(int judge);

	virtual void hpbar(Layer *layer) {};

	Animation* animation;
	Animation* Dashanimation;
	Animate* dashanimate;
	Animate* dashanimate2;

	Animate* walkanimate;
	Animate* hitanimate; //�´� �ִϸ��̼�
	Animate* atkanimate; //������ �ִϸ��̼�
	Animate* dieanimate;
	Sprite *sprite;
	UIProgressBar * progressBar; // �ھ� ü�¹�

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