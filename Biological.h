#pragma once
#include "Gloable.h"
#include <string>

using std::string;

class Biological
{
	friend class ArchiveFile;
	friend class Zoo;
	friend void RunZooClock(Zoo* z);
public:
	Biological();
	Biological(Uint Id, string Name, Uint BirthTicks);
	Biological(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live);
	virtual ~Biological();//��ʹ����������������ϵͳ���ǻ�ϳ�Ĭ����������
	virtual void Die();
	virtual Biological* Breed() = 0;
	virtual void Grow(Uint Ticks);
protected:
	Uint id;
	string name;
	string birthPlace;
	Uint birthTicks;
	Uint ageTicks;
	Uint price;
	bool live;
};

