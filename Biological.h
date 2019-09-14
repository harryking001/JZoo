#pragma once
#include "Gloable.h"
#include <string>

using std::string;

class Biological
{
	friend class ArchiveFile;
	friend class Zoo;
public:
	Biological();
	Biological(Uint Id, string Name, Uint BirthTicks, string Father, string Mother);
	Biological(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother);
	virtual ~Biological();//即使定义了析构函数，系统还是会合成默认析构函数
	virtual void Die();
	virtual Biological* Breed() = 0;
	virtual void Grow(Uint Ticks);
	inline string GetName() const { return name; }
protected:
	Uint id;
	string name;
	string birthPlace;
	Uint birthTicks;
	Uint ageTicks;
	Uint price;
	bool live;
	string father;
	string mother;
};

