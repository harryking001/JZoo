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
 * ����԰��
 * Zoo class which used to load and save zoo information
 */
class Zoo
{

	friend class ArchiveFile;
	friend void RunZooClock(Zoo& z);
	friend void ShowStatus();
public:
	/**
	 * @brief      ���캯��
	 *             Constructor function.
	 *
	 */
	Zoo();

	/**
	 * @brief      ��������
	 *             Destructor function.
	 *
	 */
	~Zoo();

	/**
	 *  @brief     ��ȡʱ��
	 *             Get time
	 *  @return    ʱ���ַ���
	 *             string
	 */
    string GetCurTime();

	/**
	 *  @brief     ���¶���������
	 *             Update the species number
	 *  @return    ��
	 *             void
	 */
	void UpdateSpeciesNum();
	
	/**
	 *  @brief     ���ö���԰����
	 *             Hire zoo manager
	 *  @param     strManager �������������������
	 *             strManager manager name(player name)
	 *  @return    ��
	 *             void
	 */
	inline void HireManager(const string& strManager)
	{
		managerName = strManager;
	}

	/**
	 *  @brief     ι����
	 *             Feed animal
	 *  @param     ani animal��ָ��
	 *             ani pointer to class animal
	 *  @return    Uint ʳ�����
	 *             Uint Food cost
	 */
	inline Uint Feed(Animal* ani)
	{
		return ani->Eat();
	}

	/**
	 *  @brief     ����԰�������������һ
	 *             Sum of the zoo animal plus one
	 *  @return    Uint ����԰��������
	 *             Uint sum of the zoo animal
	 */
	inline Uint IncAnimalNum()
	{
		 return ++animalNum;
	}

	/**
	 *  @brief     ����԰�������������һ
	 *             Sum of the zoo animal minus one
	 *  @return    Uint ����԰��������
	 *             Uint sum of the zoo animal
	 */
	inline Uint DecAnimalNum()
	{
		return --animalNum;
	}

	/**
	 *  @brief     ��ȡ����԰�ĵδ���
	 *             Get the ticks of the zoo
	 *  @return    Uint ����԰�ĵδ���
	 *             Uint ticks of the zoo
	 */
	inline Uint GetTicks() const
	{
		return opTicks;
	}

	/**
	 *  @brief     ���Ӷ���԰�ʽ�
	 *             Increase the funds of the zoo
	 *  @param     money ���ӵ��ʽ���
	 *             money the increased money
	 *  @return    ��
	 *             void
	 */
	inline void IncMoney(const Uint money)
	{
		funds += money;
	}

	/**
	 *  @brief     ���ٶ���԰�ʽ�
	 *             Decrease the funds of the zoo
	 *  @param     money ���ٵ��ʽ���
	 *             money the decreased money
	 *  @return    ��
	 *             void
	 */
	inline bool DecMoney(const Uint money)
	{
		int balance = funds - money;
		return balance >= 0 ? funds = balance,true : false;
	}
	
	/**
	 *  @brief     ��ȡ������۸�
	 *             Get the Asian elephant price
	 *  @param     pAse ���������ָ��
	 *             pAse pointer to Asian_Elephant
	 *  @return    Uint ������۸�
	 *             Uint price of Asian elephant
	 */
	Uint GetAsePrice(Asian_Elephant* pAse);

	/**
	 *  @brief     �������������а�������Ѱ������
	 *             Find Asian elephant though name from vector
	 *  @param     name ����������
	 *             name name of the Asian elephant
	 *  @return    Asian_Elephant* ָ�����������ָ��
	 *             Asian_Elephant* pointer to Asian elephant
	 */
	Asian_Elephant* FindAse(const string& name);

	/**
	 *  @brief     ���������������Ƴ����������
	 *             Remove Asian elephant from the vector
	 *  @param     name ����������
	 *             name name of the Asian elephant
	 *  @return    Asian_Elephant ���Ƴ������������Ŀ���
	 *             Asian_Elephant the copy of the removed Asian elephant object
	 */
	Asian_Elephant RemoveAse(const string& name);

	/**
	 *  @brief     ��������
	 *             Mate the two Asian elephant
	 *  @param     maleName ������������
	 *             maleName name of the Asian elephant
	 *  @param     femaleName ĸ����������
	 *             femaleName name of the Asian elephant
	 *  @return    mateMsg ������Ϣ
	 *             mateMsg mate message
	 */
	mateMsg MateAsianElephant(const string& maleName, const string& femaleName);

	/**
	 *  @brief     ���������������ѹ������������
	 *             Push the Asian elephant object reference into vector
	 *  @param     ase �������������
	 *             ase Asian elephant object reference
	 *  @return    ��
	 *             void
	 */
	inline void PushAse(const Asian_Elephant& ase)
	{
		mtx_asEle.lock();
		asEle_vec.push_back(ase);
		mtx_asEle.unlock();
	}

	/**
	 *  @brief     ����������󵯳�����������
	 *             Pop the Asian elephant object out of vector
	 *  @return    ��
	 *             void
	 */
	inline void PopAse()
	{
		mtx_asEle.lock();
		asEle_vec.pop_back();
		mtx_asEle.unlock();
	}

	/**
	 *  @brief     ���������������ѹ��������̥������
	 *             Push the fetus Asian elephant object reference into queue
	 *  @param     ase �������������
	 *             ase Asian elephant object reference
	 *  @return    ��
	 *             void
	 */
	inline void PushFetAse(const Asian_Elephant& fetAse)
	{
		mtx_aseFetus.lock();
		aseFetus_que.push(fetAse);
		mtx_aseFetus.unlock();
	}

	/**
	 *  @brief     ����������󵯳�̥�����������
	 *             Pop the Fetus Asian elephant object out of queue
	 *  @return    Asian_Elephant ��������󿽱�
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
	 *  @brief     ������԰��Ϣѹ����Ϣ����
	 *             Push the zoo message into queue
	 *  @param     strMsg ��Ϣ�ַ�������
	 *             strMsg Message reference
	 *  @return    ��
	 *             void
	 */
	inline void PushMsg(const string& strMsg)
	{
		mtx_Msg.lock();
		zooMsg_que.push(strMsg);
		mtx_Msg.unlock();
	}

	/**
	 *  @brief     ������԰��Ϣ������Ϣ����
	 *             Pop the zoo message out of queue
	 *  @return    ��
	 *             void
	 */
	inline void PopMsg()
	{
		mtx_Msg.lock();
        zooMsg_que.pop();
		mtx_Msg.unlock();
	}

	/**
	 *  @brief     ��ȡ��Ϣ�����е��������Ϣ
	 *             Get the earliest message in the queue
	 *  @return    string �������Ϣ�ַ���
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
	 *  @brief     �ж���Ϣ�����Ƿ�Ϊ��
	 *             If the message queue is empty
	 *  @return    bool trueΪ�գ�falseΪ�ǿ�
	 *             bool true if empty, false if not empty
	 */
	inline bool IsMsgEmpty() const
	{
		return zooMsg_que.empty();
	}

	/**
	 *  @brief     ����԰ʱ�ӻ���������
	 *             Zoo clock mutex lock
	 *  @return    ��
	 *             void
	 */
	inline void LockMtxClock()
	{
		mtx_Clock.lock();
	}

	/**
	 *  @brief     ����԰ʱ�ӻ���������
	 *             Zoo clock mutex unlock
	 *  @return    ��
	 *             void
	 */
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

