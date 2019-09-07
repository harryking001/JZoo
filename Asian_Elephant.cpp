#include "Asian_Elephant.h"


Asian_Elephant::Asian_Elephant()
{
}

Asian_Elephant::Asian_Elephant(Uint Id, string Name, Uint BirthTicks, gender Gd) : Elephant(Id, Name, BirthTicks, Gd)
{
	weight = 1000;
	height = 1500;
	width = 800;
	length = 1600;
	price = BABY_ASE_PRICE;
}

Asian_Elephant::Asian_Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
	bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
: Elephant(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
{
}

Asian_Elephant::~Asian_Elephant()
{
}

Asian_Elephant * Asian_Elephant::Breed()
{
	if (!preg)
		return NULL;
	preg = false;
	pregTicks = 0;
	Asian_Elephant* pAsEle = new Asian_Elephant();
	return pAsEle;
}

void Asian_Elephant::Eat(Biological &)
{
}

void Asian_Elephant::Eat()
{
	hungryTicks = 0;
}

void Asian_Elephant::Excrete()
{
}

bool Asian_Elephant::Mate(Asian_Elephant* ase)
{
	bool bPreg = false;
	if (gd != ase->gd && ageTicks> MATEAGETICK && ase->ageTicks > MATEAGETICK)
	{
		mateTicks = 0;
		bPreg = ::IsHappened(PREG_PROB);
	}
	else
	{
		return false;
	}
	return bPreg;
}

void Asian_Elephant::Grow(Uint Ticks)
{
	ageTicks = Ticks;
	hungryTicks++;
	if (preg)
	{
		pregTicks++;
	}
	ageTicks = Ticks - birthTicks;
	weight = 1000 + ageTicks;
	height = 1500 + ageTicks;
	width = 800 + ageTicks;
	length = 1600 + ageTicks;
}

int Asian_Elephant::CheckHungry() const
{
	if (hungryTicks > HUNGRYGTICKS)
		return HUNGRY;
	else if (hungryTicks > HUNGRYWARNINGTICKS)
		return HUNGRYWARNING;
	else if (hungryTicks > HUNGRYDIETICKS)
		return HUNGRYDIE;
	else
		return NOTHUNGRY;
}


