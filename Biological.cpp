#include "Biological.h"



Biological::Biological()
{
}

Biological::Biological(Uint Id, string Name, Uint BirthTicks):id(Id), name(Name), birthPlace("Shanghai"), birthTicks(BirthTicks), ageTicks(0), live(true)
{

}

Biological::Biological(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live)
	:id(Id), name(Name), birthPlace(BirthPlace), birthTicks(BirthTicks), ageTicks(AgeTicks), price(Price), live(Live)
{
}


Biological::~Biological()
{
	live = false;
}

void Biological::Die()
{
	this->~Biological();
}

void Biological::Grow(Uint Ticks)
{
	ageTicks = Ticks;

}
