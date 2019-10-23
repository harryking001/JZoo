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

/**
 * 动物园类
 * Zoo class which used to manage the zoo
 */
class Zoo
{

	friend class ArchiveFile;
	friend void RunZooClock(Zoo& z);
	friend void ShowStatus();
public:
	/**
	 * @brief      构造函数
	 *             Constructor function.
	 *
	 */
	Zoo();

	/**
	 * @brief      析构函数
	 *             Destructor function.
	 *
	 */
	~Zoo();

	/**
	 *  @brief     获取时间
	 *             Get time
	 *  @return    时间字符串
	 *             string
	 */
    string GetCurTime();

	/**
	 *  @brief     更新动物种类数量
	 *             Update the species number
	 *  @return    无
	 *             void
	 */
	void UpdateSpeciesNum();
	
	/**
	 *  @brief     雇用动物园经理
	 *             Hire zoo manager
	 *  @param     strManager 经理姓名（玩家姓名）
	 *             strManager manager name(player name)
	 *  @return    无
	 *             void
	 */
	inline void HireManager(const string& strManager)
	{
		managerName = strManager;
	}

	/**
	 *  @brief     喂动物
	 *             Feed animal
	 *  @param     ani 动物类对象引用
	 *             ani Animal object reference
	 *  @return    Uint 食物费用
	 *             Uint Food cost
	 */
	inline Uint Feed(Animal& ani)
	{
		return ani.Eat();
	}

	/**
	 *  @brief     动物园动物的总数量加一
	 *             Sum of the zoo animal plus one
	 *  @return    Uint 动物园动物总数
	 *             Uint sum of the zoo animal
	 */
	inline Uint IncAnimalNum()
	{
		 return ++animalNum;
	}

	/**
	 *  @brief     动物园动物的总数量减一
	 *             Sum of the zoo animal minus one
	 *  @return    Uint 动物园动物总数
	 *             Uint sum of the zoo animal
	 */
	inline Uint DecAnimalNum()
	{
		return --animalNum;
	}

	/**
	 *  @brief     获取动物园的滴答数
	 *             Get the ticks of the zoo
	 *  @return    Uint 动物园的滴答数
	 *             Uint ticks of the zoo
	 */
	inline Uint GetTicks() const
	{
		return opTicks;
	}

	/**
	 *  @brief     增加动物园资金
	 *             Increase the funds of the zoo
	 *  @param     money 增加的资金数
	 *             money the increased money
	 *  @return    Uint 动物园资金
	 *             Uint funds
	 */
	inline Uint IncMoney(const Uint money)
	{
		return funds += money;
	}

	/**
	 *  @brief     花费动物园资金
	 *             Decrease the funds of the zoo
	 *  @param     money 减少的资金数
	 *             money the decreased money
	 *  @return    bool true为余额大于花费，false为余额小于花费
	 *             bool true if cost money less than balance, false if cost money more than balance
	 */
	inline bool DecMoney(const Uint money)
	{
		int balance = funds - money;
		return balance >= 0 ? funds = balance,true : false;
	}
	
	/**
	 *  @brief     获取亚洲象价格
	 *             Get the Asian elephant price
	 *  @param     pAse 亚洲象对象的引用
	 *             pAse Asian_Elephant object reference
	 *  @return    Uint 亚洲象价格
	 *             Uint price of Asian elephant
	 */
	Uint GetAsePrice(const Asian_Elephant& pAse);

	/**
	 *  @brief     在亚洲象容器中按名字找寻亚洲象
	 *             Find Asian elephant though name from vector
	 *  @param     name 亚洲象名字
	 *             name name of the Asian elephant
	 *  @return    Asian_Elephant* 指向亚洲象类的指针
	 *             Asian_Elephant* pointer to Asian elephant
	 */
	Asian_Elephant& FindAse(const string& name);

	/**
	 *  @brief     从亚洲象容器中移除亚洲象对象
	 *             Remove Asian elephant from the vector
	 *  @param     name 亚洲象名字
	 *             name name of the Asian elephant
	 *  @return    Asian_Elephant 被移除的亚洲象对象的拷贝
	 *             Asian_Elephant the copy of the removed Asian elephant object
	 */
	Asian_Elephant RemoveAse(const string& name);

	/**
	 *  @brief     亚洲象交配
	 *             Mate the two Asian elephant
	 *  @param     maleName 公亚洲象名字
	 *             maleName name of the Asian elephant
	 *  @param     femaleName 母亚洲象名字
	 *             femaleName name of the Asian elephant
	 *  @return    mateMsg 交配消息
	 *             mateMsg mate message
	 */
	mateMsg MateAsianElephant(const string& maleName, const string& femaleName);

	/**
	 *  @brief     将亚洲象对象引用压入亚洲象容器
	 *             Push the Asian elephant object reference into vector
	 *  @param     ase 亚洲象对象引用
	 *             ase Asian elephant object reference
	 *  @return    无
	 *             void
	 */
	inline void PushAse(const Asian_Elephant& ase)
	{
		mtx_asEle.lock();
		asEle_vec.push_back(ase);
		mtx_asEle.unlock();
	}

	/**
	 *  @brief     将亚洲象对象弹出亚洲象容器
	 *             Pop the Asian elephant object out of vector
	 *  @return    Asian_Elephant 亚洲象对象拷贝
	 *             Asian_Elephant Copy of the Asian Elephant object
	 */
	inline Asian_Elephant PopAse()
	{
		mtx_asEle.lock();
		Asian_Elephant ase = asEle_vec.front();
		asEle_vec.pop_back();
		mtx_asEle.unlock();
		return ase;
	}

	/**
	 *  @brief     将亚洲象对象引用压入亚洲象胎儿队列
	 *             Push the fetus Asian elephant object reference into queue
	 *  @param     ase 亚洲象对象引用
	 *             ase Asian elephant object reference
	 *  @return    无
	 *             void
	 */
	inline void PushFetAse(const Asian_Elephant& fetAse)
	{
		mtx_aseFetus.lock();
		aseFetus_que.push(fetAse);
		mtx_aseFetus.unlock();
	}

	/**
	 *  @brief     将亚洲象对象弹出胎儿亚洲象队列
	 *             Pop the Fetus Asian elephant object out of queue
	 *  @return    Asian_Elephant 亚洲象对象拷贝
	 *             Asian_Elephant Copy of the Asian Elephant object
	 */
	inline Asian_Elephant PopFetAse()
	{
		mtx_aseFetus.lock();
		Asian_Elephant ase = aseFetus_que.front();
		aseFetus_que.pop();
		mtx_aseFetus.unlock();
		return ase;
	}

	/**
	 *  @brief     将动物园消息压入消息队列
	 *             Push the zoo message into queue
	 *  @param     strMsg 消息字符串引用
	 *             strMsg Message reference
	 *  @return    无
	 *             void
	 */
	inline void PushMsg(const string& strMsg)
	{
		mtx_Msg.lock();
		zooMsg_que.push(strMsg);
		mtx_Msg.unlock();
	}

	/**
	 *  @brief     将动物园消息弹出消息队列
	 *             Pop the zoo message out of queue
	 *  @return    无
	 *             void
	 */
	inline void PopMsg()
	{
		mtx_Msg.lock();
        zooMsg_que.pop();
		mtx_Msg.unlock();
	}

	/**
	 *  @brief     获取消息队列中的最早的消息
	 *             Get the earliest message in the queue
	 *  @return    string 最早的消息字符串
	 *             string the earliest message
	 */
	inline string FrontMsg()
	{
		mtx_Msg.lock();
		string strMsg = zooMsg_que.front();
		mtx_Msg.unlock();
		return strMsg;
	}

	/**
	 *  @brief     判断消息队列是否为空
	 *             If the message queue is empty
	 *  @return    bool true为空，false为非空
	 *             bool true if empty, false if not empty
	 */
	inline bool IsMsgEmpty() const
	{
		return zooMsg_que.empty();
	}

	/**
	 *  @brief     动物园时钟互斥量加锁
	 *             Zoo clock mutex lock
	 *  @return    无
	 *             void
	 */
	inline void LockMtxClock()
	{
		mtx_Clock.lock();
	}

	/**
	 *  @brief     动物园时钟互斥量解锁
	 *             Zoo clock mutex unlock
	 *  @return    无
	 *             void
	 */
	inline void UnlockMtxClock()
	{
		mtx_Clock.unlock();
	}

private:
	/**
	 *  @brief     创建动物园时钟线程
	 *             Create zoo clock thread
	 *  @return    无
	 *             void
	 */
	void CreateZooClock();
private:
	/** 当前时间 */
	/** Current Time */
	string currentTime;

	/** 动物园是否关闭 */
	/** If zoo is closed */
	bool close;

	/** 动物园经理（玩家）姓名 */
	/** Zoo manager(player) name */
	string managerName;

	/** 动物种类数量 */
	/** Species numbers */
	Uint speciesNum;

	/** 动物数量 */
	/** Animal numbers */
	Uint animalNum;

	/** 动物园资金 */
	/** Zoo funds */
	ULLong funds;

	/** 运行滴答 */
	/** Operating ticks */
	Uint opTicks;

	/** 亚洲象容器 */
	/** Asian elephant vector */
	vector<Asian_Elephant> asEle_vec;

	/** 亚洲象胎儿容器 */
	/** Fetus Asian elephant vector */
	queue<Asian_Elephant> aseFetus_que;

	/** 动物园消息队列 */
	/** Zoo message queue */
	queue<string> zooMsg_que;

	std::mutex mtx_Clock;
	std::mutex mtx_Msg;
	std::mutex mtx_asEle;
	std::mutex mtx_aseFetus;
};

