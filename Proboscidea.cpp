#include "Proboscidea.h"



Proboscidea::Proboscidea()
{
}

Proboscidea::Proboscidea(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd) :Mammal(Id, Name, BirthTicks, Father, Mother, Gd)
{
}

Proboscidea::Proboscidea(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother, 
	Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Mammal(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Father, Mother, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Proboscidea::~Proboscidea()
{
}
