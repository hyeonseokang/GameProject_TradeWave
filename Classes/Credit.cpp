#include "Credit.h"
#pragma execution_character_set("utf-8")
#include"SimpleAudioEngine.h"
Scene * Credit::createScene()
{
	Scene *scene = Scene::create();
	Credit *layer = Credit::create();
	scene->addChild(layer);	return scene;
}

bool Credit::init()
{
	if (!LayerColor::initWithColor(Color4B::BLACK))
	{
		return false;
	}
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/minseok.mp3", true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	this->setKeyboardEnabled(true);

	count_A = -1; count_B = 0;

	auto title = Sprite::create("Title/TradeWave.png");
	title->setPosition(Vec2(640,360));
	title->runAction(Sequence::create(DelayTime::create(1),FadeOut::create(1),nullptr));
	this->addChild(title);
	auto c_layer = Layer::create();
	c_layer->runAction(Sequence::create(DelayTime::create(2), MoveBy::create(8, Vec2(0, 3120))
		, CallFunc::create([&] {this->schedule(schedule_selector(Credit::update),1); }), nullptr));
	this->addChild(c_layer);
	ParticleGalaxy*fire[12];
	for (int i = 0; i <= 11; i++)
	{
		fire[i] = ParticleGalaxy::create();
		fire[i]->setDuration(-1);
		fire[i]->setSpeed(100);
		fire[i]->setPosition(Vec2(640, -i * 200 - 100));
		fire[i]->setGravity(Vec2(500,500));
		c_layer->addChild(fire[i]);

		label[i] = Label::createWithTTF("","fonts/JejuGothic-Regular.ttf",35,Size(500,100),TextHAlignment::CENTER);
		label[i]->enableBold();
		label[i]->enableGlow(Color4B::BLUE);
		label[i]->setPosition(Vec2(640,-i*200-100));
		c_layer->addChild(label[i]);
	}
	label[0]->setString("��ȹ��\n������");
	label[1]->setString("ŷ��¯���α׷���\n������");
	label[2]->setString("������α׷���\n�Ź���");
	label[3]->setString("¯���α׷���\n���ؿ�");
	label[4]->setString("����\n������");
	label[5]->setString("�׷���\n������");
	label[6]->setString("�׷���\n������");
	label[7]->setString("�������\n�ѱ����Ӱ��а���б�");
	label[8]->setString("��������\n�θ��");
	label[9]->setString("�����ڷ�\n���̹�,����");
	label[10]->setString("ũ�����뷡\n1�г��� ���̵��� ���μ�");
	label[11]->setString("�����ֽź�\n��ȣ�̼����Ե�");


	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			NameSpr[i][j] = Sprite::create();
			NameSpr[i][j]->setPosition(Vec2(256*(i+1),-300*(j+1)+850));
			NameSpr[i][j]->setOpacity(0);
			this->addChild(NameSpr[i][j],5);
			NameLabel[i][j] = Label::createWithTTF("", "fonts/JejuGothic-Regular.ttf", 35, Size(200, 100), TextHAlignment::CENTER);
			NameLabel[i][j]->setOpacity(0);
			NameLabel[i][j]->enableBold();
			NameLabel[i][j]->enableGlow(Color4B::RED);
			NameLabel[i][j]->setPosition(Vec2(68,-50));
			NameSpr[i][j]->addChild(NameLabel[i][j]);
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		NameSpr[i][1]->setPositionX(NameSpr[i][1]->getPositionX() + 128);
	}
	NameSpr[0][0]->setTexture("credit/bird.png");
	NameSpr[1][0]->setTexture("credit/bull.png");
	NameSpr[2][0]->setTexture("credit/cat.png");
	NameSpr[3][0]->setTexture("credit/cow.png");
	NameSpr[0][1]->setTexture("credit/dog.png");
	NameSpr[1][1]->setTexture("credit/duck.png");
	NameSpr[2][1]->setTexture("credit/fish.png");

	NameLabel[0][0]->setString("��ȹ��\n������");
	NameLabel[1][0]->setString("���α׷���\n������");
	NameLabel[2][0]->setString("���α׷���\n�Ź���");
	NameLabel[3][0]->setString("���α׷���\n���ؿ�");
	NameLabel[0][1]->setString("���α׷���\n������");
	NameLabel[1][1]->setString("�׷���\n������");
	NameLabel[2][1]->setString("�׷���\n������");


	return true;
}

void Credit::update(float dt)
{
	count_A++;
	if (count_A == 4)
	{
		count_A = 0;
		count_B++;
	}
	NameSpr[count_A][count_B]->runAction(FadeIn::create(2));
	NameLabel[count_A][count_B]->runAction(FadeIn::create(2));
	Particle_manager(1, NameSpr[count_A][count_B]->getPosition());
	if (count_A == 2 && count_B == 1)
		this->unscheduleAllSelectors();
}

void Credit::Particle_manager(int num, Vec2 pos)
{
	/*ParticleExplosion *p_1 = ParticleExplosion::create();
	ParticleFire	  *p_2 = ParticleFire::create();
	ParticleFireworks *p_3 = ParticleFireworks::create();
	ParticleFlower	  *p_4 = ParticleFlower::create();
	ParticleGalaxy	  *p_5 = ParticleGalaxy::create();
	ParticleMeteor	  *p_6 = ParticleMeteor::create();
	ParticleRain	  *p_7 = ParticleRain::create();
	ParticleSmoke	  *p_8 = ParticleSmoke::create();
	ParticleSnow	  *p_9 = ParticleSnow::create();
	ParticleSpiral	  *p_10 = ParticleSpiral::create();
	ParticleSun		  *p_11 = ParticleSun::create();*/
	ParticleExplosion *p_1 = ParticleExplosion::create();
	p_1->setSpeed(1000);
	ParticleSun	  *p_2 = ParticleSun::create();
	ParticleSpiral	  *p_3 = ParticleSpiral::create();
	switch (num)
	{
	case 1:
		p_1->setPosition(pos);
		this->addChild(p_1,1);
		break;
	case 2:
		
		p_2->setPosition(pos);
		this->addChild(p_2,1);
		break;
	case 3:
		
		p_3->setPosition(pos);
		this->addChild(p_3,1);
		break;
	}

}

bool Credit::onTouchBegan(Touch * touch, Event * event)
{
	count_A++;
	if (count_A == 4)
	{
		count_A = 0;
		count_B++;
	}
	NameSpr[count_A][count_B]->runAction(FadeIn::create(2));
	NameLabel[count_A][count_B]->runAction(FadeIn::create(2));
	Particle_manager(1, NameSpr[count_A][count_B]->getPosition());
	if (count_A == 2 && count_B == 1)
		this->setTouchEnabled(false);
	return true;
}

void Credit::onTouchEnded(Touch * touch, Event * unused_event)
{
}

void Credit::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		Director::getInstance()->popScene();
		break;

	}
	
}
