#pragma once
#include "Chordata.h"

//���鶯���
class Mammal :
	public Chordata
{
public:
	Mammal();
	Mammal(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd);
	Mammal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
		 Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Mammal();
	void BreastFeeding();
};

