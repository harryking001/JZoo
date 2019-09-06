#pragma once
#include "Chordata.h"

//²¸Èé¶¯Îï¸Ù
class Mammal :
	public Chordata
{
public:
	Mammal();
	Mammal(Uint Id, string Name, Uint BirthTicks, gender Gd);
	Mammal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
		bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Mammal();
	void BreastFeeding();
};

