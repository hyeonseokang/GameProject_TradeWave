#include "handle.h"

Handle::Handle(Layer * layer)
{
	lay = layer;
	handle_png = Sprite::create("ShipMove/Operate.png");
	handle_png->setPosition(Vec2(200, 200));
	lay->addChild(handle_png);
}
void Handle::setPos(float x, float y)
{
	handle_png->setPosition(Vec2(x, y));

}
void Handle::setRotate(float a)
{
	handle_png->setRotation(a);
}
float Handle::getRotate()
{
	return handle_png->getRotation();
}

