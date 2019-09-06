#include "Zoo.h"

void RunZooClock(Zoo* z)
{
	while (!z->close)
	{
		z->opTicks++;
		for (vector<Asian_Elephant>::iterator it = z->asEle_vec.begin(); it != z->asEle_vec.end(); it++)
		{
			it->Grow(z->opTicks);
		}
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

Asian_Elephant & Zoo::Find(const string name)
{
	vector<Asian_Elephant>::iterator it = asEle_vec.begin();
	for (; it != asEle_vec.end(); it++)
	{
		if(it->)
	}
}

void Zoo::CreateZooClock()
{
	std::thread t1(RunZooClock,this);
	t1.detach();
}


