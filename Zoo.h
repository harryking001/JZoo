#pragma once
#include "Asian_Elephant.h"
#include <vector>
#include <queue>
#include <stack>
#include <thread>
#include <Windows.h>
using std::vector;
using std::queue;
using std::stack;
using std::to_string;


class Zoo
{
	//friend bool ArchiveFile::Load(const Zoo& z) const;
	//friend bool ArchiveFile::Save(Zoo& z) const;
	friend class ArchiveFile;
	friend void RunZooClock(Zoo& z);
	friend void ShowStatus();
public:
	Zoo();
	~Zoo();
    string GetCurTime();
	
	void UpdateSpeciesNum();

	Asian_Elephant* Find(const string name);

	mateMsg MateAsianElephant(const string maleName, const string femaleName);

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
		mtx_asEle.lock();
		asEle_vec.push_back(ase);
		mtx_asEle.unlock();
	}

	inline void PopAse()
	{
		mtx_asEle.lock();
		asEle_vec.pop_back();
		mtx_asEle.unlock();
	}

	inline bool PushFetAse(Asian_Elephant fetAse)
	{
		mtx_aseFetus.lock();
		aseFetus_que.push(fetAse);
		mtx_aseFetus.unlock();
		return true;
	}

	inline Asian_Elephant PopFetAse()
	{
		mtx_aseFetus.lock();
		Asian_Elephant ase = aseFetus_que.front();
		aseFetus_que.pop();
		mtx_aseFetus.unlock();
		return ase;
	}

	inline void PushMsg(string strMsg)
	{
		mtx_Msg.lock();
		zooMsg_que.push(strMsg);
		mtx_Msg.unlock();
	}

	inline void PopMsg()
	{
		mtx_Msg.lock();
        zooMsg_que.pop();
		mtx_Msg.unlock();
	}

	inline string FrontMsg()
	{
		mtx_Msg.lock();
		string strMsg = zooMsg_que.front();
		mtx_Msg.unlock();
		return strMsg;
	}

	inline bool IsMsgEmpty() const
	{
		return zooMsg_que.empty();
	}

	inline void LockMtxClock()
	{
		mtx_Clock.lock();
	}

	inline void UnlockMtxClock()
	{
		mtx_Clock.unlock();
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

	std::mutex mtx_Clock;
	std::mutex mtx_Msg;
	std::mutex mtx_asEle;
	std::mutex mtx_aseFetus;
};

