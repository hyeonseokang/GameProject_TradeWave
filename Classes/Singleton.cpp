#include"Singleton.h"
SingleTon::SingleTon()
{

}
SingleTon::~SingleTon()
{
}
SingleTon * SingleTon::getinstance()
{
	if (instant == NULL)
		instant = new SingleTon();
	return instant;
}
bool SingleTon::getBGM() const
{
	return BGM;
}
void SingleTon::setBGM(bool _BGM)
{
	BGM = _BGM;
}
bool SingleTon::getEFFECT() const
{
	return EFFECT;
}
void SingleTon::setEFFECT(bool _EFFECT)
{
	EFFECT = _EFFECT;
}
int SingleTon::getTutorial() const
{
	return _tutorial;
}
void SingleTon::setTutorial(int _tutorialN)
{
	_tutorial = _tutorialN;
}
int SingleTon::getTitle() const
{
	return _titlemedal;
}

bool SingleTon::setTitle(int _title)
{
	if (_title < 0 || _title>4)
		return false;
	_titlemedal = _title;
	return true;
}
int SingleTon::getArea() const
{
	return _area;
}

void SingleTon::setArea(int __area)
{
	_area = __area;
}

Vec2 SingleTon::getPos() const
{
	return ship_pos;
}

void SingleTon::setPos(Vec2 pos)
{
	ship_pos = pos;
}

bool SingleTon::getBack() const
{
	return BeBack;
}

void SingleTon::setBack(bool back)
{
	BeBack = back;
}

Vec2 SingleTon::getCamPos() const
{
	return cam_pos;
}

void SingleTon::setCamPos(Vec2 pos)
{
	cam_pos = pos;
}

int SingleTon::getShell() const
{
	return shells;
}

void SingleTon::setShell(int num)
{
	shells = num;
}

int SingleTon::getTime() const
{
	return time;
}

void SingleTon::setTime(int t)
{
	time = t;
}
