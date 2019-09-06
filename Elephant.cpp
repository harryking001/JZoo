#include "Elephant.h"



Elephant::Elephant()
{
}

Elephant::Elephant(Uint Id, string Name, Uint BirthTicks, gender Gd) :Proboscidea(Id, Name, BirthTicks, Gd)
{
}

Elephant::Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
	bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Proboscidea(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Elephant::~Elephant()
{
}
