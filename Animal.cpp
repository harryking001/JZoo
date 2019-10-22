#include "Animal.h"



Animal::Animal():gd(UNKNOWGD), hungryTicks(0), pregTicks(0), mateTicks(0), preg(false)
{
}

Animal::Animal(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd) :Biological(Id, Name, BirthTicks, Father, Mother), 
gd(Gd), hungryTicks(0), pregTicks(0), mateTicks(0), preg(false)
{ 
}

Animal::Animal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
	 Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg)
	:Biological(Id, Name, BirthPlace, BirthTicks, AgeTicks, Price, Live, Father, Mother), weight(Weight), height(Height), width(Width), length(Length), gd(Gd), 
	hungryTicks(HungryTicks), pregTicks(PregTicks), mateTicks(MateTicks), preg(Preg)
{
}


Animal::~Animal()
{
}



