#pragma once
#include "Gloable.h"
#include <string>

using std::string;

class Biological
{
	friend class ArchiveFile;
	friend class Zoo;
	friend void ShowStatus();
public:
	Biological();
	Biological(Uint Id, string Name, Uint BirthTicks, string Father, string Mother);
	Biological(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother);
	virtual ~Biological();//即使定义了析构函数，系统还是会合成默认析构函数
	virtual void Die();
	virtual bool Breed() = 0;
	virtual void Grow(const Uint Ticks);
	inline void SetId(const Uint Id) { id = Id; }
	inline void Naming(const string& Name) { name = Name; }
	inline string GetName() const { return name; }
	inline string GetFatherName() const { return father; }
	inline string GetMotherName() const { return mother; }
	inline void SetBirthTicks(const Uint Ticks) { birthTicks = Ticks; }
	inline Uint GetBirthTicks() { return birthTicks; }
	virtual bool CheckLife() const = 0;
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

