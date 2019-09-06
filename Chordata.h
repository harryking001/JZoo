#pragma once
#include "Animal.h"

//¼¹Ë÷¶¯ÎïÃÅ
class Chordata :
	public Animal
{
public:
	Chordata();
	Chordata(Uint Id, string Name, Uint BirthTicks, gender Gd);
	Chordata(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
		bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Chordata();
};

