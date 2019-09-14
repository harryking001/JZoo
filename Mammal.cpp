#include "Mammal.h"



Mammal::Mammal()
{
}

Mammal::Mammal(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd) :Chordata(Id, Name, BirthTicks, Father, Mother, Gd)
{
}

Mammal::Mammal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother, 
	Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Chordata(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Father, Mother, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Mammal::~Mammal()
{
}

void Mammal::BreastFeeding()
{
}
