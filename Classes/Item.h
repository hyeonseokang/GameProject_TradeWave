#pragma once
#include  "cocos2d.h"
USING_NS_CC;

class Item
{
protected:
	int BasePrice[24]; //기본시세 
	int HaveMaterial[24]; //가지고있는 재료 
	int money; // 돈 
public:
	void ChangePrice(int *price);
	void SaveloadPirce();
	void PriceInit();
public:
	void setDisaster(int _num);
	void Typhoon();
	void Drought();
	void Plague();
	void Flood();

	int getMoney() const;
	void setMoney(int Newmoney);

	int getPepper() const;
	int getGarlic() const;
	int getSugar() const;
	int getCinnamon() const;
	int getRice() const;
	int getOnion() const;
	int getWheat() const;
	int getWonion() const;
	int getShellfish() const;
	int getFish() const;
	int getLobster() const;
	int getSquid() const;
	int getDiamond() const;
	int getRuby() const;
	int getPeridot() const;
	int getPearl() const;
	int getIron() const;
	int getGold() const;
	int getSilver() const;
	int getCopper() const;
	int getLeather() const;
	int getSilk() const;
	int getNoodle() const;
	int getLinen() const;
	int hgetPepper() const;
	int hgetGarlic() const;
	int hgetSugar() const;
	int hgetCinnamon() const;
	int hgetRice() const;

	void setPepper(int NewPepper);
	void setGarlic(int NewGarlic);
	void setSugar(int NewSugar);
	void setCinnamon(int NewCinnamon);
	void setRice(int NewRice);
	void setOnion(int NewOnion);
	void setWheat(int NewWheat);
	void setWonion(int NewWonion);
	void setShellfish(int NewShellfish);
	void setFish(int NewFish);
	void setLobster(int NewLobster);
	void setSquid(int NewSquid);
	void setDiamond(int NewDiamond);
	void setRuby(int NewRuby);
	void setPeridot(int NewPeridot);
	void setPearl(int NewPearl);
	void setIron(int NewIron);
	void setGold(int NewGold);
	void setSilver(int NewSilver);
	void setCopper(int NewCopper);
	void setLeather(int NewLeather);
	void setSilk(int NewSilk);
	void setNoodle(int NewNoodle);
	void setLinen(int NewLinen);
	void hsetPepper(int NewPepper);
	void hsetGarlic(int NewGarlic);
	void hsetSugar(int NewSugar);
	void hsetCinnamon(int NewCinnamon);
	void hsetRice(int NewRice);
};

