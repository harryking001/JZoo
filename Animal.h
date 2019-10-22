#pragma once
#include "Biological.h"

//¶¯Îï½ç
class Animal :
	public Biological
{
	friend class ArchiveFile;
	friend class Zoo;
	friend void ShowStatus();
public:
	Animal();
	Animal(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd);
	Animal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
		Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Animal();
	virtual Uint Eat() = 0;
	virtual void Excrete() = 0;
	//virtual bool Mate(Animal&) = 0;
	virtual int CheckHungry() const = 0;
	virtual inline bool IsPreg() const{ return preg; }
	virtual bool CheckBreed() const = 0;
	inline void SetGender(const gender& gend) { gd = gend; }
	inline gender GetGender() { return gd; }
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

