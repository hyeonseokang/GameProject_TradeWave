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
	label[0]->setString("기획자\n이은행");
	label[1]->setString("킹왕짱프로그래머\n강현서");
	label[2]->setString("따까리프로그래머\n신무현");
	label[3]->setString("짱프로그래머\n권준엽");
	label[4]->setString("광부\n전현진");
	label[5]->setString("그래픽\n오종석");
	label[6]->setString("그래픽\n서애진");
	label[7]->setString("장소협찬\n한국게임과학고등학교");
	label[8]->setString("투자지원\n부모님");
	label[9]->setString("참고자료\n네이버,구글");
	label[10]->setString("크레딧노래\n1학년의 아이도루 정민석");
	label[11]->setString("도움주신분\n㈜호미선생님들");


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

	NameLabel[0][0]->setString("기획자\n이은행");
	NameLabel[1][0]->setString("프로그래머\n강현서");
	NameLabel[2][0]->setString("프로그래머\n신무현");
	NameLabel[3][0]->setString("프로그래머\n권준엽");
	NameLabel[0][1]->setString("프로그래머\n전현진");
	NameLabel[1][1]->setString("그래픽\n오종석");
	NameLabel[2][1]->setString("그래픽\n서애진");


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
