#include "Mammal.h"



Mammal::Mammal()
{
}

Mammal::Mammal(Uint Id, string Name, Uint BirthTicks, gender Gd) :Chordata(Id, Name, BirthTicks, Gd)
{
}

Mammal::Mammal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
	bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Chordata(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Mammal::~Mammal()
{
}

void Mammal::BreastFeeding()
{
}
