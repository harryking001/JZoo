#pragma once
#include "Asian_Elephant.h"
#include <vector>
#include <queue>
#include <thread>
#include <Windows.h>
using std::vector;
using std::queue;
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
	inline Uint Feed(Animal& ani)
	{
		return ani.Eat();
	}
	inline Uint IncAnimalNum()
	{
		 return ++animalNum;
	}
	inline Uint DecAnimalNum()
	{
		return --animalNum;
	}
	void UpdateSpeciesNum();
	inline Uint GetTicks() const
	{
		return opTicks;
	}
	inline void IncMoney(Uint money)
	{
		int balance = funds + money;
	}
	inline bool DecMoney(Uint money)
	{
		int balance = funds - money;
		return balance >= 0 ? funds = balance,true : false;
	}
	inline void PushAse(Asian_Elephant& ase)
	{
		asEle_vec.push_back(ase);
	}
	inline void PopAse()
	{
		asEle_vec.pop_back();
		DecAnimalNum();
	}
	inline bool PushFetAse(Asian_Elephant fetAse)
	{
		aseFetus_que.push(fetAse);
		return true;
	}
	inline Asian_Elephant PopFetAse()
	{
		Asian_Elephant ase = aseFetus_que.front();
		aseFetus_que.pop();
		return ase;
	}
	Asian_Elephant* Find(const string name);
	mateMsg MateAsianElephant(const string maleName, const string femaleName);
	string PopMsg();
	inline bool IsMsgEmpty() const
	{
		return zooMsg_que.empty();
	}
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
	queue<Asian_Elephant> aseFetus_que;
	queue<string> zooMsg_que;
};

