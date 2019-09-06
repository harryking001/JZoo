#pragma once
#include "Mammal.h"

//³¤±ÇÄ¿
class Proboscidea :
	public Mammal
{
public:
	Proboscidea();
	Proboscidea(Uint Id, string Name, Uint BirthTicks, gender Gd);
	Proboscidea(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
		bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Proboscidea();
};

