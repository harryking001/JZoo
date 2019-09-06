#include "Animal.h"



Animal::Animal()
{
}

Animal::Animal(Uint Id, string Name, Uint BirthTicks, gender Gd) :Biological(Id, Name, BirthTicks), gd(Gd), preg(false)
{ 
}

Animal::Animal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
	bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Biological(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live), weight(Weight), height(Height), width(Width), length(Length), gd(Gd), 
	hungryTicks(HungryTicks), pregTicks(PregTicks), mateTicks(MateTicks), preg(Preg)
{
}


Animal::~Animal()
{
}

void Animal::Die()
{
}

int Animal::CheckHungry()
{
	if (hungryTicks > 3000)
		return 1;
	else if (hungryTicks > 5000)
		return 2;
	else if (hungryTicks > 6000)
		return 3;
	else
		return 0;
	return 0;
}

