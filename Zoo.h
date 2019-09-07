#pragma once
#include "Asian_Elephant.h"
#include <vector>
#include <thread>
#include <Windows.h>
using std::vector;
using std::to_string;


class Zoo
{
	//friend bool ArchiveFile::Load(const Zoo& z) const;
	//friend bool ArchiveFile::Save(Zoo& z) const;
	friend class ArchiveFile;
	friend void RunZooClock(Zoo* z);
public:
	Zoo();
	~Zoo();
    string GetCurTime();
	inline void HireManager(string strManager)
	{
		managerName = strManager;
	}
	inline Uint IncAnimalNum()
	{
		 return ++animalNum;
	}
	void UpdateSpeciesNum();
	inline Uint GetTicks() const
	{
		return opTicks;
	}
	inline bool DecMoney(Uint money)
	{
		int balance = funds - money;
		return balance >= 0 ? funds = balance,true : false;
	}
	inline void PushAse(Asian_Elephant& ase)
	{
		asEle_vec.push_back(ase);
		IncAnimalNum();
	}
	Asian_Elephant* Find(const string name);
	mateMsg MateAsianElephant(const string maleName, const string femaleName);
private:
	void CreateZooClock();
private:
	string currentTime;
	bool close;
	string managerName;
	Uint speciesNum;
	Uint animalNum;
	ULLong funds;
	Uint opTicks;
	vector<Asian_Elephant> asEle_vec;
};

