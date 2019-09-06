#pragma once
#include "Elephant.h"
#include <thread>
#include <Windows.h>

//ÑÇÖÞÏó
class Asian_Elephant :
	public Elephant
{
	friend class ArchiveFile;
public:
	Asian_Elephant();
	Asian_Elephant(Uint Id, string Name, Uint BirthTicks, gender Gd);
	Asian_Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, 
		bool Live, Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Asian_Elephant();
	virtual Asian_Elephant* Breed();
	void Eat(Biological&);
	void Eat();
	void Excrete();
	bool Mate(Asian_Elephant&);
	void Grow(Uint Ticks);

private:
	const Uint MATEAGETICK = 100000;
	const Uint MATEINTERTICK = 5000;
};

