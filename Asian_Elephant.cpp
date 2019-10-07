#include "Asian_Elephant.h"


Asian_Elephant::Asian_Elephant()
{
}

Asian_Elephant::Asian_Elephant(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd) : Elephant(Id, Name, BirthTicks, Father, Mother, Gd)
{
	weight = 1000;
	height = 1500;
	width = 800;
	length = 1600;
	price = BABY_ASE_PRICE;
}

Asian_Elephant::Asian_Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
	 Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
: Elephant(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Father, Mother, Weight, Height, Width, Length, Gd, HungryTicks, PregTicks, MateTicks, Preg)
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
	hungryTicks = 0;
}

Uint Asian_Elephant::Eat()
{
	hungryTicks = 0;
	return ASE_FOOD_COST;
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
	mateTicks++;
	hungryTicks++;
	if (preg)
	{
		pregTicks++;
	}
	ageTicks = Ticks - birthTicks;
	weight = ageTicks < 5000 ? 1000 + ageTicks : 1000 + 5000;
	height = ageTicks < 3000 ? 1500 + ageTicks : 1500 + 3000;
	width = ageTicks < 2000 ? 800 + ageTicks : 800 + 2000;
	length = ageTicks < 5000 ? 1600 + ageTicks : 1600 + 5000;
}

int Asian_Elephant::CheckHungry() const
{
	if (hungryTicks == HUNGRYGTICKS)
		return HUNGRY;
	else if (hungryTicks == HUNGRYWARNINGTICKS)
		return HUNGRYWARNING;
	else if (hungryTicks == HUNGRYDIETICKS)
		return HUNGRYDIE;
	else if (hungryTicks < HUNGRYGTICKS)
		return NOTHUNGRY;
	else
		return NUL;
}

bool Asian_Elephant::CheckBreed() const

{
	return pregTicks == PREGTICKS ? true:false;
}


