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
	struct tm t;   //tm结构指针
	time_t now;  //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时间
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
		if(it->name == name)//Zoo需要访问Biological的name属性
			return &*it;//将迭代器转换为指针（迭代器是一个类，重载了operator*()操作符，表示容器中相应的对象，再使用&获取容器元素对象的指针）
	}
	return NULL;
}

MATEMSG Zoo::MateAsianElephant(const string maleName, const string femaleName)
{
	Asian_Elephant* maleAse = Find(maleName);
	Asian_Elephant* femaleAse = Find(femaleName);
	if(femaleAse && femaleAse)
	{
        //Zoo需要访问Animal的name属性以及Asian_Elephant的MATEAGETICK及MATEINTERTICK属性
		if(maleAse->gd!=MALE || femaleAse->gd!=FEMALE)
			return SEX_WRONG;
		else if(maleAse->ageTicks < maleAse->MATEAGETICK)
			return MALE_UNDERMATEAGE;
		else if(femaleAse->ageTicks < femaleAse->MATEAGETICK)
		    return FEMALE_UNDERMATEAGE;
		else if(maleAse->mateTicks < maleAse->MATEINTERTICK)
		    return MALE_NOTREADY;
		else if(femaleAse->mateTicks < femaleAse->MATEINTERTICK)
			return FEMALE_NOTREADY;
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
		maleAse->pregTicks = 0;
		maleAse->preg = true;
		return PREGNANT;
	}
	else
		return NOTPREGNANT;
}

void Zoo::CreateZooClock()
{
	std::thread t1(::RunZooClock,this);
	t1.detach();
}


