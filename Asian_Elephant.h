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
	friend void ShowStatus();
public:
	Asian_Elephant();
	Asian_Elephant(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd);
	Asian_Elephant(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
		 Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Asian_Elephant();
	virtual bool Breed();
	Uint Eat();
	void Excrete();
	bool Mate(const Asian_Elephant& ase);
	void Grow(const Uint Ticks);
	virtual int CheckHungry() const;
	virtual bool CheckBreed() const;
	virtual bool CheckLife() const;
private:
	static const Uint MATEAGETICK = 50;
	static const Uint MATEINTERTICK = 10;
	static const Uint HUNGRYGTICKS = 100;
	static const Uint HUNGRYWARNINGTICKS = 150;
	static const Uint HUNGRYDIETICKS = 300;
	static const Uint PREGTICKS = 30;
	static const Uint LIVETICKS = 500;
};

