#include "Proboscidea.h"



Proboscidea::Proboscidea()
{
}

Proboscidea::Proboscidea(Uint Id, string Name, Uint BirthTicks, gender Gd) :Mammal(Id, Name, BirthTicks, Gd)
{
}

Proboscidea::Proboscidea(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
	bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Mammal(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}


Proboscidea::~Proboscidea()
{
}
