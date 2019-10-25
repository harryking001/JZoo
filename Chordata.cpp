#include "Chordata.h"



Chordata::Chordata()
{
}

Chordata::Chordata(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd) :Animal(Id, Name, BirthTicks, Father, Mother, Gd)
{
}

Chordata::Chordata(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
	 Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Animal(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Father, Mother, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Chordata::~Chordata()
{
}
