#include "Biological.h"



Biological::Biological()
{
}

Biological::Biological(Uint Id, string Name, Uint BirthTicks, string Father, string Mother):id(Id), name(Name), birthPlace("Shanghai"), birthTicks(BirthTicks), 
ageTicks(0), live(true), father(Father), mother(Mother)
{

}

Biological::Biological(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother)
	:id(Id), name(Name), birthPlace(BirthPlace), birthTicks(BirthTicks), ageTicks(AgeTicks), price(Price), live(Live), father(Father), mother(Mother)
{
}


Biological::~Biological()
{
	live = false;
}

void Biological::Die()
{
	live = false;
}

void Biological::Grow(Uint Ticks)
{
	ageTicks = Ticks;

}
