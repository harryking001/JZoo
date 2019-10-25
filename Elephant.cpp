#include "Elephant.h"



Elephant::Elephant()
{
}

Elephant::Elephant(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd) :Proboscidea(Id, Name, BirthTicks, Father, Mother, Gd)
{
}

Elephant::Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
	 Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Proboscidea(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Father, Mother, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Elephant::~Elephant()
{
}
