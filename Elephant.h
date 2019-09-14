#pragma once
#include "Proboscidea.h"

//Ïó¿Æ
class Elephant :
	public Proboscidea
{
public:
	Elephant();
	Elephant(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd);
	Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
		Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Elephant();

private:

};

