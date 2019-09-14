#pragma once
#include "Elephant.h"
#include <thread>
#include <Windows.h>

//ÑÇÖÞÏó
class Asian_Elephant :
	public Elephant
{
	friend class ArchiveFile;
	friend class Zoo;
public:
	Asian_Elephant();
	Asian_Elephant(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd);
	Asian_Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
		 Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Asian_Elephant();
	virtual Asian_Elephant* Breed();
	void Eat(Biological&);
	void Eat();
	void Excrete();
	bool Mate(Asian_Elephant*);
	void Grow(Uint Ticks);
	virtual int CheckHungry() const;
	virtual bool CheckBreed() const;
private:
	static const Uint MATEAGETICK = 100000;
	static const Uint MATEINTERTICK = 5000;
	static const Uint HUNGRYGTICKS = 3000;
	static const Uint HUNGRYWARNINGTICKS = 5000;
	static const Uint HUNGRYDIETICKS = 6000;
	static const Uint PREGTICKS = 10000;
};

