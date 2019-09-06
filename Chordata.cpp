#include "Chordata.h"



Chordata::Chordata()
{
}

Chordata::Chordata(Uint Id, string Name, Uint BirthTicks, gender Gd) :Animal(Id, Name, BirthTicks, Gd)
{
}

Chordata::Chordata(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
	bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Animal(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Chordata::~Chordata()
{
}
