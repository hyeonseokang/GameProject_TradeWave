#include "Item.h"
void Item::ChangePrice(int * price)
{

	////시세 변환함수/////////
	int change = RandomHelper::random_int(-5, 5);
	change += 100;
	float change2 = 0;
	change2 = *price;
	change2 /= 100;
	change2 *= change;
	*price = change2;
}

void Item::SaveloadPirce()
{
	UserDefault::getInstance()->setIntegerForKey("LPEPPER",BasePrice[0]);
	UserDefault::getInstance()->setIntegerForKey("LGARLIC", BasePrice[1]);
	UserDefault::getInstance()->setIntegerForKey("LSUGAR", BasePrice[2]);
	UserDefault::getInstance()->setIntegerForKey("LCINNAMON", BasePrice[3]);
	UserDefault::getInstance()->setIntegerForKey("LRICE", BasePrice[4]);
	UserDefault::getInstance()->setIntegerForKey("LONION", BasePrice[5]);
	UserDefault::getInstance()->setIntegerForKey("LWHEAT", BasePrice[6]);
	UserDefault::getInstance()->setIntegerForKey("LWONION", BasePrice[7]);
	UserDefault::getInstance()->setIntegerForKey("LSHELLFISH", BasePrice[8]);
	UserDefault::getInstance()->setIntegerForKey("LFISH", BasePrice[9]);
	UserDefault::getInstance()->setIntegerForKey("LLOBSTER", BasePrice[10]);
	UserDefault::getInstance()->setIntegerForKey("LSQUID", BasePrice[11]);
	UserDefault::getInstance()->setIntegerForKey("LDIAMOND", BasePrice[12]);
	UserDefault::getInstance()->setIntegerForKey("LRUBY", BasePrice[13]);
	UserDefault::getInstance()->setIntegerForKey("LPERIDOT", BasePrice[14]);
	UserDefault::getInstance()->setIntegerForKey("LPEARL", BasePrice[15]);
	UserDefault::getInstance()->setIntegerForKey("LIRON", BasePrice[16]);
	UserDefault::getInstance()->setIntegerForKey("LGOLD", BasePrice[17]);
	UserDefault::getInstance()->setIntegerForKey("LSILVER", BasePrice[18]);
	UserDefault::getInstance()->setIntegerForKey("LCOPPER", BasePrice[19]);
	UserDefault::getInstance()->setIntegerForKey("LLEATHER", BasePrice[20]);
	UserDefault::getInstance()->setIntegerForKey("LSILK", BasePrice[21]);
	UserDefault::getInstance()->setIntegerForKey("LNOODLE", BasePrice[22]);
	UserDefault::getInstance()->setIntegerForKey("LLINEN", BasePrice[23]);
}

void Item::PriceInit()
{
	hsetPepper(UserDefault::getInstance()->getIntegerForKey("HPEPPER"));
	hsetGarlic(UserDefault::getInstance()->getIntegerForKey("HGARLIC"));
	hsetSugar(UserDefault::getInstance()->getIntegerForKey("HSUGAR"));
	hsetCinnamon(UserDefault::getInstance()->getIntegerForKey("HCINNAMON"));
	hsetRice(UserDefault::getInstance()->getIntegerForKey("HRICE"));
	HaveMaterial[5] = UserDefault::getInstance()->getIntegerForKey("HONION");
	HaveMaterial[6] = UserDefault::getInstance()->getIntegerForKey("HWHEAT");
	HaveMaterial[7] = UserDefault::getInstance()->getIntegerForKey("HWONION");
	HaveMaterial[8] = UserDefault::getInstance()->getIntegerForKey("HSHELLFISH");
	HaveMaterial[9] = UserDefault::getInstance()->getIntegerForKey("HFISH");
	HaveMaterial[10] = UserDefault::getInstance()->getIntegerForKey("HLOBSTER");
	HaveMaterial[11] = UserDefault::getInstance()->getIntegerForKey("HSQUID");
	HaveMaterial[12] = UserDefault::getInstance()->getIntegerForKey("HDIAMOND");
	HaveMaterial[13] = UserDefault::getInstance()->getIntegerForKey("HRUBY");
	HaveMaterial[14] = UserDefault::getInstance()->getIntegerForKey("HPERIDOT");
	HaveMaterial[15] = UserDefault::getInstance()->getIntegerForKey("HPEARL");
	HaveMaterial[16] = UserDefault::getInstance()->getIntegerForKey("HIRON");
	HaveMaterial[17] = UserDefault::getInstance()->getIntegerForKey("HGOLD");
	HaveMaterial[18] = UserDefault::getInstance()->getIntegerForKey("HSILVER");
	HaveMaterial[19] = UserDefault::getInstance()->getIntegerForKey("HCOPPER");
	HaveMaterial[20] = UserDefault::getInstance()->getIntegerForKey("HLEATHER");
	HaveMaterial[21] = UserDefault::getInstance()->getIntegerForKey("HSILK");
	HaveMaterial[22] = UserDefault::getInstance()->getIntegerForKey("HNOODLE");
	HaveMaterial[23] = UserDefault::getInstance()->getIntegerForKey("HLINEN");
	if (UserDefault::getInstance()->getIntegerForKey("NOW") == 1)
	{
		setMoney(UserDefault::getInstance()->getIntegerForKey("MONEY"));

		//클래스안에 각 가격 할당 
		
		setPepper(UserDefault::getInstance()->getIntegerForKey("A1PEPPER"));
		setGarlic(UserDefault::getInstance()->getIntegerForKey("A1GARLIC"));
		setSugar(UserDefault::getInstance()->getIntegerForKey("A1SUGAR"));
		setCinnamon(UserDefault::getInstance()->getIntegerForKey("A1CINNAMON"));
		setRice(UserDefault::getInstance()->getIntegerForKey("A1RICE"));
		setOnion(UserDefault::getInstance()->getIntegerForKey("A1ONION"));
		setWheat(UserDefault::getInstance()->getIntegerForKey("A1WHEAT"));
		setWonion(UserDefault::getInstance()->getIntegerForKey("A1WONION"));
		setShellfish(UserDefault::getInstance()->getIntegerForKey("A1SHELLFISH"));
		setFish(UserDefault::getInstance()->getIntegerForKey("A1FISH"));
		setLobster(UserDefault::getInstance()->getIntegerForKey("A1LOBSTER"));
		setSquid(UserDefault::getInstance()->getIntegerForKey("A1SQUID"));
		setDiamond(UserDefault::getInstance()->getIntegerForKey("A1DIAMOND"));
		setRuby(UserDefault::getInstance()->getIntegerForKey("A1RUBY"));
		setPeridot(UserDefault::getInstance()->getIntegerForKey("A1PERIDOT"));
		setPearl(UserDefault::getInstance()->getIntegerForKey("A1PEARL"));
		setIron(UserDefault::getInstance()->getIntegerForKey("A1IRON"));
		setGold(UserDefault::getInstance()->getIntegerForKey("A1GOLD"));
		setSilver(UserDefault::getInstance()->getIntegerForKey("A1SILVER"));
		setCopper(UserDefault::getInstance()->getIntegerForKey("A1COPPER"));
		setLeather(UserDefault::getInstance()->getIntegerForKey("A1LEATHER"));
		setSilk(UserDefault::getInstance()->getIntegerForKey("A1SILK"));
		setNoodle(UserDefault::getInstance()->getIntegerForKey("A1NOODLE"));
		setLinen(UserDefault::getInstance()->getIntegerForKey("A1LINEN"));
	}
	if (UserDefault::getInstance()->getIntegerForKey("NOW") == 2)
	{
		setMoney(UserDefault::getInstance()->getIntegerForKey("MONEY"));

		//클래스안에 각 가격 할당 
		setPepper(UserDefault::getInstance()->getIntegerForKey("A2PEPPER"));
		setGarlic(UserDefault::getInstance()->getIntegerForKey("A2GARLIC"));
		setSugar(UserDefault::getInstance()->getIntegerForKey("A2SUGAR"));
		setCinnamon(UserDefault::getInstance()->getIntegerForKey("A2CINNAMON"));
		setRice(UserDefault::getInstance()->getIntegerForKey("A2RICE"));
		setOnion(UserDefault::getInstance()->getIntegerForKey("A2ONION"));
		setWheat(UserDefault::getInstance()->getIntegerForKey("A2WHEAT"));
		setWonion(UserDefault::getInstance()->getIntegerForKey("A2WONION"));
		setShellfish(UserDefault::getInstance()->getIntegerForKey("A2SHELLFISH"));
		setFish(UserDefault::getInstance()->getIntegerForKey("A2FISH"));
		setLobster(UserDefault::getInstance()->getIntegerForKey("A2LOBSTER"));
		setSquid(UserDefault::getInstance()->getIntegerForKey("A2SQUID"));
		setDiamond(UserDefault::getInstance()->getIntegerForKey("A2DIAMOND"));
		setRuby(UserDefault::getInstance()->getIntegerForKey("A2RUBY"));
		setPeridot(UserDefault::getInstance()->getIntegerForKey("A2PERIDOT"));
		setPearl(UserDefault::getInstance()->getIntegerForKey("A2PEARL"));
		setIron(UserDefault::getInstance()->getIntegerForKey("A2IRON"));
		setGold(UserDefault::getInstance()->getIntegerForKey("A2GOLD"));
		setSilver(UserDefault::getInstance()->getIntegerForKey("A2SILVER"));
		setCopper(UserDefault::getInstance()->getIntegerForKey("A2COPPER"));
		setLeather(UserDefault::getInstance()->getIntegerForKey("A2LEATHER"));
		setSilk(UserDefault::getInstance()->getIntegerForKey("A2SILK"));
		setNoodle(UserDefault::getInstance()->getIntegerForKey("A2NOODLE"));
		setLinen(UserDefault::getInstance()->getIntegerForKey("A2LINEN"));
	}
	if (UserDefault::getInstance()->getIntegerForKey("NOW") == 3)
	{
		setMoney(UserDefault::getInstance()->getIntegerForKey("MONEY"));

		//클래스안에 각 가격 할당 
		setPepper(UserDefault::getInstance()->getIntegerForKey("A3PEPPER"));
		setGarlic(UserDefault::getInstance()->getIntegerForKey("A3GARLIC"));
		setSugar(UserDefault::getInstance()->getIntegerForKey("A3SUGAR"));
		setCinnamon(UserDefault::getInstance()->getIntegerForKey("A3CINNAMON"));
		setRice(UserDefault::getInstance()->getIntegerForKey("A3RICE"));
		setOnion(UserDefault::getInstance()->getIntegerForKey("A3ONION"));
		setWheat(UserDefault::getInstance()->getIntegerForKey("A3WHEAT"));
		setWonion(UserDefault::getInstance()->getIntegerForKey("A3WONION"));
		setShellfish(UserDefault::getInstance()->getIntegerForKey("A3SHELLFISH"));
		setFish(UserDefault::getInstance()->getIntegerForKey("A3FISH"));
		setLobster(UserDefault::getInstance()->getIntegerForKey("A3LOBSTER"));
		setSquid(UserDefault::getInstance()->getIntegerForKey("A3SQUID"));
		setDiamond(UserDefault::getInstance()->getIntegerForKey("A3DIAMOND"));
		setRuby(UserDefault::getInstance()->getIntegerForKey("A3RUBY"));
		setPeridot(UserDefault::getInstance()->getIntegerForKey("A3PERIDOT"));
		setPearl(UserDefault::getInstance()->getIntegerForKey("A3PEARL"));
		setIron(UserDefault::getInstance()->getIntegerForKey("A3IRON"));
		setGold(UserDefault::getInstance()->getIntegerForKey("A3GOLD"));
		setSilver(UserDefault::getInstance()->getIntegerForKey("A3SILVER"));
		setCopper(UserDefault::getInstance()->getIntegerForKey("A3COPPER"));
		setLeather(UserDefault::getInstance()->getIntegerForKey("A3LEATHER"));
		setSilk(UserDefault::getInstance()->getIntegerForKey("A3SILK"));
		setNoodle(UserDefault::getInstance()->getIntegerForKey("A3NOODLE"));
		setLinen(UserDefault::getInstance()->getIntegerForKey("A3LINEN"));
	}
	if (UserDefault::getInstance()->getIntegerForKey("NOW") == 4)
	{
		setMoney(UserDefault::getInstance()->getIntegerForKey("MONEY"));

		//클래스안에 각 가격 할당 
		setPepper(UserDefault::getInstance()->getIntegerForKey("B1PEPPER"));
		setGarlic(UserDefault::getInstance()->getIntegerForKey("B1GARLIC"));
		setSugar(UserDefault::getInstance()->getIntegerForKey("B1SUGAR"));
		setCinnamon(UserDefault::getInstance()->getIntegerForKey("B1CINNAMON"));
		setRice(UserDefault::getInstance()->getIntegerForKey("B1RICE"));
		setOnion(UserDefault::getInstance()->getIntegerForKey("B1ONION"));
		setWheat(UserDefault::getInstance()->getIntegerForKey("B1WHEAT"));
		setWonion(UserDefault::getInstance()->getIntegerForKey("B1WONION"));
		setShellfish(UserDefault::getInstance()->getIntegerForKey("B1SHELLFISH"));
		setFish(UserDefault::getInstance()->getIntegerForKey("B1FISH"));
		setLobster(UserDefault::getInstance()->getIntegerForKey("B1LOBSTER"));
		setSquid(UserDefault::getInstance()->getIntegerForKey("B1SQUID"));
		setDiamond(UserDefault::getInstance()->getIntegerForKey("B1DIAMOND"));
		setRuby(UserDefault::getInstance()->getIntegerForKey("B1RUBY"));
		setPeridot(UserDefault::getInstance()->getIntegerForKey("B1PERIDOT"));
		setPearl(UserDefault::getInstance()->getIntegerForKey("B1PEARL"));
		setIron(UserDefault::getInstance()->getIntegerForKey("B1IRON"));
		setGold(UserDefault::getInstance()->getIntegerForKey("B1GOLD"));
		setSilver(UserDefault::getInstance()->getIntegerForKey("B1SILVER"));
		setCopper(UserDefault::getInstance()->getIntegerForKey("B1COPPER"));
		setLeather(UserDefault::getInstance()->getIntegerForKey("B1LEATHER"));
		setSilk(UserDefault::getInstance()->getIntegerForKey("B1SILK"));
		setNoodle(UserDefault::getInstance()->getIntegerForKey("B1NOODLE"));
		setLinen(UserDefault::getInstance()->getIntegerForKey("B1LINEN"));
	}
	if (UserDefault::getInstance()->getIntegerForKey("NOW") == 5)
	{
		setMoney(UserDefault::getInstance()->getIntegerForKey("MONEY"));

		//클래스안에 각 가격 할당 
		setPepper(UserDefault::getInstance()->getIntegerForKey("B2PEPPER"));
		setGarlic(UserDefault::getInstance()->getIntegerForKey("B2GARLIC"));
		setSugar(UserDefault::getInstance()->getIntegerForKey("B2SUGAR"));
		setCinnamon(UserDefault::getInstance()->getIntegerForKey("B2CINNAMON"));
		setRice(UserDefault::getInstance()->getIntegerForKey("B2RICE"));
		setOnion(UserDefault::getInstance()->getIntegerForKey("B2ONION"));
		setWheat(UserDefault::getInstance()->getIntegerForKey("B2WHEAT"));
		setWonion(UserDefault::getInstance()->getIntegerForKey("B2WONION"));
		setShellfish(UserDefault::getInstance()->getIntegerForKey("B2SHELLFISH"));
		setFish(UserDefault::getInstance()->getIntegerForKey("B2FISH"));
		setLobster(UserDefault::getInstance()->getIntegerForKey("B2LOBSTER"));
		setSquid(UserDefault::getInstance()->getIntegerForKey("B2SQUID"));
		setDiamond(UserDefault::getInstance()->getIntegerForKey("B2DIAMOND"));
		setRuby(UserDefault::getInstance()->getIntegerForKey("B2RUBY"));
		setPeridot(UserDefault::getInstance()->getIntegerForKey("B2PERIDOT"));
		setPearl(UserDefault::getInstance()->getIntegerForKey("B2PEARL"));
		setIron(UserDefault::getInstance()->getIntegerForKey("B2IRON"));
		setGold(UserDefault::getInstance()->getIntegerForKey("B2GOLD"));
		setSilver(UserDefault::getInstance()->getIntegerForKey("B2SILVER"));
		setCopper(UserDefault::getInstance()->getIntegerForKey("B2COPPER"));
		setLeather(UserDefault::getInstance()->getIntegerForKey("B2LEATHER"));
		setSilk(UserDefault::getInstance()->getIntegerForKey("B2SILK"));
		setNoodle(UserDefault::getInstance()->getIntegerForKey("B2NOODLE"));
		setLinen(UserDefault::getInstance()->getIntegerForKey("B2LINEN"));
	}
	if (UserDefault::getInstance()->getIntegerForKey("NOW") == 6)
	{
		setMoney(UserDefault::getInstance()->getIntegerForKey("MONEY"));

		//클래스안에 각 가격 할당 
		setPepper(UserDefault::getInstance()->getIntegerForKey("C1PEPPER"));
		setGarlic(UserDefault::getInstance()->getIntegerForKey("C1GARLIC"));
		setSugar(UserDefault::getInstance()->getIntegerForKey("C1SUGAR"));
		setCinnamon(UserDefault::getInstance()->getIntegerForKey("C1CINNAMON"));
		setRice(UserDefault::getInstance()->getIntegerForKey("C1RICE"));
		setOnion(UserDefault::getInstance()->getIntegerForKey("C1ONION"));
		setWheat(UserDefault::getInstance()->getIntegerForKey("C1WHEAT"));
		setWonion(UserDefault::getInstance()->getIntegerForKey("C1WONION"));
		setShellfish(UserDefault::getInstance()->getIntegerForKey("C1SHELLFISH"));
		setFish(UserDefault::getInstance()->getIntegerForKey("C1FISH"));
		setLobster(UserDefault::getInstance()->getIntegerForKey("C1LOBSTER"));
		setSquid(UserDefault::getInstance()->getIntegerForKey("C1SQUID"));
		setDiamond(UserDefault::getInstance()->getIntegerForKey("C1DIAMOND"));
		setRuby(UserDefault::getInstance()->getIntegerForKey("C1RUBY"));
		setPeridot(UserDefault::getInstance()->getIntegerForKey("C1PERIDOT"));
		setPearl(UserDefault::getInstance()->getIntegerForKey("C1PEARL"));
		setIron(UserDefault::getInstance()->getIntegerForKey("C1IRON"));
		setGold(UserDefault::getInstance()->getIntegerForKey("C1GOLD"));
		setSilver(UserDefault::getInstance()->getIntegerForKey("C1SILVER"));
		setCopper(UserDefault::getInstance()->getIntegerForKey("C1COPPER"));
		setLeather(UserDefault::getInstance()->getIntegerForKey("C1LEATHER"));
		setSilk(UserDefault::getInstance()->getIntegerForKey("C1SILK"));
		setNoodle(UserDefault::getInstance()->getIntegerForKey("C1NOODLE"));
		setLinen(UserDefault::getInstance()->getIntegerForKey("C1LINEN"));
	}
	if (UserDefault::getInstance()->getIntegerForKey("NOW") == 7)
	{
		setMoney(UserDefault::getInstance()->getIntegerForKey("MONEY"));

		//클래스안에 각 가격 할당 
		setPepper(UserDefault::getInstance()->getIntegerForKey("C2PEPPER"));
		setGarlic(UserDefault::getInstance()->getIntegerForKey("C2GARLIC"));
		setSugar(UserDefault::getInstance()->getIntegerForKey("C2SUGAR"));
		setCinnamon(UserDefault::getInstance()->getIntegerForKey("C2CINNAMON"));
		setRice(UserDefault::getInstance()->getIntegerForKey("C2RICE"));
		setOnion(UserDefault::getInstance()->getIntegerForKey("C2ONION"));
		setWheat(UserDefault::getInstance()->getIntegerForKey("C2WHEAT"));
		setWonion(UserDefault::getInstance()->getIntegerForKey("C2WONION"));
		setShellfish(UserDefault::getInstance()->getIntegerForKey("C2SHELLFISH"));
		setFish(UserDefault::getInstance()->getIntegerForKey("C2FISH"));
		setLobster(UserDefault::getInstance()->getIntegerForKey("C2LOBSTER"));
		setSquid(UserDefault::getInstance()->getIntegerForKey("C2SQUID"));
		setDiamond(UserDefault::getInstance()->getIntegerForKey("C2DIAMOND"));
		setRuby(UserDefault::getInstance()->getIntegerForKey("C2RUBY"));
		setPeridot(UserDefault::getInstance()->getIntegerForKey("C2PERIDOT"));
		setPearl(UserDefault::getInstance()->getIntegerForKey("C2PEARL"));
		setIron(UserDefault::getInstance()->getIntegerForKey("C2IRON"));
		setGold(UserDefault::getInstance()->getIntegerForKey("C2GOLD"));
		setSilver(UserDefault::getInstance()->getIntegerForKey("C2SILVER"));
		setCopper(UserDefault::getInstance()->getIntegerForKey("C2COPPER"));
		setLeather(UserDefault::getInstance()->getIntegerForKey("C2LEATHER"));
		setSilk(UserDefault::getInstance()->getIntegerForKey("C2SILK"));
		setNoodle(UserDefault::getInstance()->getIntegerForKey("C2NOODLE"));
		setLinen(UserDefault::getInstance()->getIntegerForKey("C2LINEN"));
	}

	for (int a = 0; a < 24; a++)
	{
		ChangePrice(&(BasePrice[a]));
	}
}

void Item::setDisaster(int _num)
{
	switch (_num)
	{
	case 1:
		Typhoon();
		log("Typhoon");
		break;
	case 2:
		Drought();
		log("Drought");
		break;
	case 3:
		Plague();
		log("Plague");
		break;
	case 4:
		Flood();
		log("Flood");
		break;
	}
}

void Item::Typhoon()
{
	setPepper(getPepper() + (getPepper()*0.2));
	setGarlic(getGarlic() + (getGarlic()*0.2));
	setSugar(getSugar() + (getSugar()*0.2));
	setCinnamon(getCinnamon() + (getCinnamon()*0.2));

	setRice(getRice() + (getRice()*0.4));
	setOnion(getOnion() + (getOnion()*0.4));
	setWheat(getWheat() + (getWheat()*0.4));
	setWonion(getWonion() + (getWonion()*0.4));

	setShellfish(getShellfish() + (getShellfish()*0.2));
	setFish(getFish() + (getFish()*0.2));
	setLobster(getLobster() + (getLobster()*0.2));
	setSquid(getSquid() + (getSquid()*0.2));

	setDiamond(getDiamond() + (getDiamond()*0.1));
	setRuby(getRuby() + (getRuby()*0.1));
	setPeridot(getPeridot() + (getPeridot()*0.1));
	setPearl(getPearl() + (getPearl()*0.1));

	setIron(getIron() + (getIron()*0.1));
	setGold(getGold() + (getGold()*0.1));
	setSilver(getSilver() + (getSilver()*0.1));
	setCopper(getCopper() + (getCopper()*0.1));

	setLeather(getLeather() + (getLeather()*0.3));
	setSilk(getSilk() + (getSilk()*0.3));
	setNoodle(getNoodle() + (getNoodle()*0.3));
	setLinen(getLinen() + (getLinen()*0.3));
}

void Item::Drought()
{
	setPepper((getPepper()*0.8));
	setGarlic((getGarlic()*0.8));
	setSugar((getSugar()*0.8));
	setCinnamon((getCinnamon()*0.8));

	setRice(getRice() + (getRice()*0.5));
	setOnion(getOnion() + (getOnion()*0.5));
	setWheat(getWheat() + (getWheat()*0.5));
	setWonion(getWonion() + (getWonion()*0.5));

	setShellfish(getShellfish() + (getShellfish()*0.2));
	setFish(getFish() + (getFish()*0.2));
	setLobster(getLobster() + (getLobster()*0.2));
	setSquid(getSquid() + (getSquid()*0.2));

	setDiamond((getDiamond()*0.8));
	setRuby((getRuby()*0.8));
	setPeridot((getPeridot()*0.8));
	setPearl((getPearl()*0.8));

	setIron(getIron() + (getIron()*0.1));
	setGold(getGold() + (getGold()*0.1));
	setSilver(getSilver() + (getSilver()*0.1));
	setCopper(getCopper() + (getCopper()*0.1));

	setLeather(getLeather() + (getLeather()*0.1));
	setSilk(getSilk() + (getSilk()*0.1));
	setNoodle(getNoodle() + (getNoodle()*0.1));
	setLinen(getLinen() + (getLinen()*0.1));
}

void Item::Plague()
{
	setPepper(getPepper() + (getPepper()*0.2));
	setGarlic(getGarlic() + (getGarlic()*0.2));
	setSugar(getSugar() + (getSugar()*0.2));
	setCinnamon(getCinnamon() + (getCinnamon()*0.2));

	setRice(getRice() + (getRice()*0.3));
	setOnion(getOnion() + (getOnion()*0.3));
	setWheat(getWheat() + (getWheat()*0.3));
	setWonion(getWonion() + (getWonion()*0.3));

	setShellfish(getShellfish() + (getShellfish()*0.2));
	setFish(getFish() + (getFish()*0.2));
	setLobster(getLobster() + (getLobster()*0.2));
	setSquid(getSquid() + (getSquid()*0.2));

	setDiamond((getDiamond()*0.7));
	setRuby((getRuby()*0.7));
	setPeridot((getPeridot()*0.7));
	setPearl((getPearl()*0.7));

	setIron(getIron() + (getIron()*0.1));
	setGold(getGold() + (getGold()*0.1));
	setSilver(getSilver() + (getSilver()*0.1));
	setCopper(getCopper() + (getCopper()*0.1));

	setLeather(getLeather() + (getLeather()*0.2));
	setSilk(getSilk() + (getSilk()*0.2));
	setNoodle(getNoodle() + (getNoodle()*0.2));
	setLinen(getLinen() + (getLinen()*0.2));
}

void Item::Flood()
{
	setPepper(getPepper() + (getPepper()*0.2));
	setGarlic(getGarlic() + (getGarlic()*0.2));
	setSugar(getSugar() + (getSugar()*0.2));
	setCinnamon(getCinnamon() + (getCinnamon()*0.2));

	setRice(getRice() + (getRice()*0.2));
	setOnion(getOnion() + (getOnion()*0.2));
	setWheat(getWheat() + (getWheat()*0.2));
	setWonion(getWonion() + (getWonion()*0.2));

	setShellfish(getShellfish() + (getShellfish()*0.2));
	setFish(getFish() + (getFish()*0.2));
	setLobster(getLobster() + (getLobster()*0.2));
	setSquid(getSquid() + (getSquid()*0.2));

	setDiamond(getDiamond() + (getDiamond()*0.2));
	setRuby(getRuby() + (getRuby()*0.2));
	setPeridot(getPeridot() + (getPeridot()*0.2));
	setPearl(getPearl() +(getPearl()*0.2));

	setIron(getIron() + (getIron()*0.2));
	setGold(getGold() + (getGold()*0.2));
	setSilver(getSilver() + (getSilver()*0.2));
	setCopper(getCopper() + (getCopper()*0.2));

	setLeather(getLeather() + (getLeather()*0.2));
	setSilk(getSilk() + (getSilk()*0.2));
	setNoodle(getNoodle() + (getNoodle()*0.2));
	setLinen(getLinen() + (getLinen()*0.2));
}

int Item::getMoney() const
{
	return money;
}

void Item::setMoney(int Newmoney)
{
	money = Newmoney;
}

int Item::getPepper() const
{
	return BasePrice[0];
}

int Item::getGarlic() const
{
	return BasePrice[1];
}

int Item::getSugar() const
{
	return BasePrice[2];
}

int Item::getCinnamon() const
{
	return BasePrice[3];
}

int Item::getRice() const
{
	return BasePrice[4];
}

int Item::getOnion() const
{
	return BasePrice[5];
}

int Item::getWheat() const
{
	return BasePrice[6];
}

int Item::getWonion() const
{
	return BasePrice[7];
}

int Item::getShellfish() const
{
	return BasePrice[8];
}

int Item::getFish() const
{
	return BasePrice[9];
}

int Item::getLobster() const
{
	return BasePrice[10];
}

int Item::getSquid() const
{
	return BasePrice[11];
}

int Item::getDiamond() const
{
	return BasePrice[12];
}

int Item::getRuby() const
{
	return BasePrice[13];
}

int Item::getPeridot() const
{
	return BasePrice[14];
}

int Item::getPearl() const
{
	return BasePrice[15];
}

int Item::getIron() const
{
	return BasePrice[16];
}

int Item::getGold() const
{
	return BasePrice[17];
}

int Item::getSilver() const
{
	return BasePrice[18];
}

int Item::getCopper() const
{
	return BasePrice[19];
}

int Item::getLeather() const
{
	return BasePrice[20];
}

int Item::getSilk() const
{
	return BasePrice[21];
}

int Item::getNoodle() const
{
	return BasePrice[22];
}

int Item::getLinen() const
{
	return BasePrice[23];
}

int Item::hgetPepper() const
{
	return HaveMaterial[0];
}

int Item::hgetGarlic() const
{
	return HaveMaterial[1];
}

int Item::hgetSugar() const
{
	return HaveMaterial[2];
}

int Item::hgetCinnamon() const
{
	return HaveMaterial[3];
}

int Item::hgetRice() const
{
	return HaveMaterial[4];
}

void Item::setPepper(int NewPepper)
{
	BasePrice[0] = NewPepper;
}

void Item::setGarlic(int NewGarlic)
{
	BasePrice[1] = NewGarlic;
}

void Item::setSugar(int NewSugar)
{
	BasePrice[2] = NewSugar;
}

void Item::setCinnamon(int NewCinnamon)
{
	BasePrice[3] = NewCinnamon;
}

void Item::setRice(int NewRice)
{
	BasePrice[4] = NewRice;
}

void Item::setOnion(int NewOnion)
{
	BasePrice[5] = NewOnion;
}

void Item::setWheat(int NewWheat)
{
	BasePrice[6] = NewWheat;
}

void Item::setWonion(int NewWonion)
{
	BasePrice[7] = NewWonion;
}

void Item::setShellfish(int NewShellfish)
{
	BasePrice[8] = NewShellfish;
}

void Item::setFish(int NewFish)
{
	BasePrice[9] = NewFish;
}

void Item::setLobster(int NewLobster)
{
	BasePrice[10] = NewLobster;
}

void Item::setSquid(int NewSquid)
{
	BasePrice[11] = NewSquid;
}

void Item::setDiamond(int NewDiamond)
{
	BasePrice[12] = NewDiamond;
}

void Item::setRuby(int NewRuby)
{
	BasePrice[13] = NewRuby;
}

void Item::setPeridot(int NewPeridot)
{
	BasePrice[14] = NewPeridot;
}

void Item::setPearl(int NewPearl)
{
	BasePrice[15] = NewPearl;
}

void Item::setIron(int NewIron)
{
	BasePrice[16] = NewIron;
}

void Item::setGold(int NewGold)
{
	BasePrice[17] = NewGold;
}

void Item::setSilver(int NewSilver)
{
	BasePrice[18] = NewSilver;
}

void Item::setCopper(int NewCopper)
{
	BasePrice[19] = NewCopper;
}

void Item::setLeather(int NewLeather)
{
	BasePrice[20] = NewLeather;
}

void Item::setSilk(int NewSilk)
{
	BasePrice[21] = NewSilk;
}

void Item::setNoodle(int NewNoodle)
{
	BasePrice[22] = NewNoodle;
}

void Item::setLinen(int NewLinen)
{
	BasePrice[23] = NewLinen;
}

void Item::hsetPepper(int NewPepper)
{
	HaveMaterial[0] = NewPepper;
}

void Item::hsetGarlic(int NewGarlic)
{
	HaveMaterial[1] = NewGarlic;
}

void Item::hsetSugar(int NewSugar)
{
	HaveMaterial[2] = NewSugar;
}

void Item::hsetCinnamon(int NewCinnamon)
{
	HaveMaterial[3] = NewCinnamon;
}

void Item::hsetRice(int NewRice)
{
	HaveMaterial[4] = NewRice;
}