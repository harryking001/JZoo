#pragma once
#include "Elephant.h"
#include <thread>
#include <Windows.h>

//������
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
	virtual hungryMsg CheckHungry() const;
	virtual bool CheckBreed() const;
	virtual bool CheckLife() const;
private:
	/** ��С��������δ��� */
	/** Minimum mate ticks */
	static const Uint MATEAGETICK = 50;

	/** ��С�������δ��� */
	/** Minimum mate interval ticks */
	static const Uint MATEINTERTICK = 10;

	/** �����δ��� */
	/** Hungry ticks */
	static const Uint HUNGRYGTICKS = 100;

	/** ��������δ��� */
	/** Hungry warning ticks */
	static const Uint HUNGRYWARNINGTICKS = 150;

	/** �����δ��� */
	/** Hungry die ticks */
	static const Uint HUNGRYDIETICKS = 300;

	/** �������ڵδ��� */
	/** Pregnant ticks */
	static const Uint PREGTICKS = 30;

	/** �����δ��� */
	/** Life ticks */
	static const Uint LIVETICKS = 500;
};

