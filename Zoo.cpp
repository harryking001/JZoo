#include "Zoo.h"

extern std::mutex mtx;

void RunZooClock(Zoo& z)
{
	while (!z.close)
	{
		mtx.lock();
		z.opTicks++;
		for (vector<Asian_Elephant>::iterator it = z.asEle_vec.begin(); it != z.asEle_vec.end(); it++)
		{
			it->Grow(z.opTicks);
			hungryMsg h = (hungryMsg)it->CheckHungry();
			string strName = "Asian elephant " + it->GetName();
			string strMsg;
			switch (h)
			{
			case HUNGRY:
				strMsg = strName + " is hungry!";
				z.zooMsg_que.push(strMsg);
				break;
			case HUNGRYWARNING:
				strMsg = strName + " is very hungry! Please feed him/her ASAP!";
				z.zooMsg_que.push(strMsg);
				break;
			case HUNGRYDIE:
				strMsg = strName + " died of hunger!";
				z.zooMsg_que.push(strMsg);
				it->Die();
				break;	
			}
            
			bool bBreed = it->CheckBreed();
			if (bBreed)
			{
				strMsg = strName + " is having baby...";
				z.zooMsg_que.push(strMsg);
			}	
		}
		mtx.unlock();
		Sleep(1000);
	}
}

Zoo::Zoo():close(false),opTicks(0),speciesNum(0),animalNum(0),funds(1000000)
{
	CreateZooClock();
}

Zoo::~Zoo()
{
	close = true;
}

string Zoo::GetCurTime()
{
	struct tm t;   //tm�ṹָ��
	time_t now;  //����time_t���ͱ���
	time(&now);      //��ȡϵͳ���ں�ʱ��
	localtime_s(&t, &now);   //��ȡ�������ں�ʱ��
	string strTime(to_string(t.tm_year + 1900)+'-' + to_string(t.tm_mon + 1) + '-' + to_string(t.tm_mday)+'-'+
	to_string(t.tm_hour)+'-'+ to_string( t.tm_min)+'-'+ to_string(t.tm_sec));
	return strTime;
}

void Zoo::UpdateSpeciesNum()
{
	speciesNum = 0;
	if (!asEle_vec.empty())
		++speciesNum;

}

Asian_Elephant * Zoo::Find(const string name)
{
	vector<Asian_Elephant>::iterator it = asEle_vec.begin();
	for (; it != asEle_vec.end(); it++)
	{
		if(it->name == name)//Zoo��Ҫ����Biological��name����
			return &*it;//��������ת��Ϊָ�루��������һ���࣬������operator*()����������ʾ��������Ӧ�Ķ�����ʹ��&��ȡ����Ԫ�ض����ָ�룩
	}
	return NULL;
}

mateMsg Zoo::MateAsianElephant(const string maleName, const string femaleName)
{
	Asian_Elephant* maleAse = Find(maleName);
	Asian_Elephant* femaleAse = Find(femaleName);
	if(maleAse && femaleAse)
	{
        //Zoo��Ҫ����Animal��name�����Լ�Asian_Elephant��MATEAGETICK��MATEINTERTICK����
		if (maleAse->gd != MALE || femaleAse->gd != FEMALE)
			return SEX_WRONG;
		else if (maleAse->ageTicks < maleAse->MATEAGETICK)
			return MALE_UNDERMATEAGE;
		else if (femaleAse->ageTicks < femaleAse->MATEAGETICK)
			return FEMALE_UNDERMATEAGE;
		else if (maleAse->mateTicks < maleAse->MATEINTERTICK)
			return MALE_NOTREADY;
		else if (femaleAse->mateTicks < femaleAse->MATEINTERTICK || femaleAse->preg == true)
			return FEMALE_NOTREADY;
		else if (femaleAse->father == maleAse->name || maleAse->mother == femaleAse->name ||
			((maleAse->father == femaleAse->father) && (maleAse->father != "Unknow")) ||
			((maleAse->mother == femaleAse->mother) && (maleAse->mother != "Unknow")))
			return INBREED;
	}
	else if(!maleAse)
	{
		return MISSING_MALE;
	}
	else if(!femaleAse)
	{
		return MISSING_FEMALE;
	}
	bool bPreg = maleAse->Mate(femaleAse);
	if(bPreg)
	{
		femaleAse->pregTicks = 0;
		femaleAse->preg = true;
		return PREGNANT;
	}
	else
		return NOTPREGNANT;
}

string Zoo::PopMsg()
{
	string strMsg = zooMsg_que.front();
	zooMsg_que.pop();
	return strMsg;
}

void Zoo::CreateZooClock()
{
	std::thread t1(::RunZooClock, std::ref(*this));
	t1.detach();
}


