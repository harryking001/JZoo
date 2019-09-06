#pragma once
#include "Biological.h"

//¶¯Îï½ç
class Animal :
	public Biological
{
	friend class ArchiveFile;
public:
	Animal();
	Animal(Uint Id, string Name, Uint BirthTicks, gender Gd);
	Animal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
		bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Animal();
	virtual void Die();
	virtual void Eat(Biological&) = 0;
	virtual void Eat() = 0;
	virtual void Excrete() = 0;
	//virtual bool Mate(Animal&) = 0;
	virtual int CheckHungry();
	virtual inline bool CheckPreg() { return preg; }
protected:
	Uint weight;
	Uint height;
	Uint width;
	Uint length;
	gender gd;
	Uint hungryTicks;
	Uint pregTicks;
	Uint mateTicks;
	bool preg;
};

