#pragma once
#include "Gloable.h"
#include <string>

using std::string;

/**
 * 生物类，包含生物基本的属性和方法
 * Biological class, include basic biological attributes and functions
 */
class Biological
{
	friend class ArchiveFile;
	friend class Zoo;
	friend void ShowStatus();
public:
	/**
	 * @brief      默认构造函数
	 *             Default constructor function
	 */
	Biological();

	/**
	 * @brief      构造函数
	 *             Constructor function
	 */
	Biological(Uint Id, string Name, Uint BirthTicks, string Father, string Mother);

	/**
	 * @brief      构造函数
	 *             Constructor function
	 */
	Biological(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother);

	/**
	 * @brief      析构函数
	 *             Destructor function
	 */
	virtual ~Biological();//即使定义了析构函数，系统还是会合成默认析构函数

	/**
	 * @brief      死亡
	 *             Die
	 */
	virtual void Die();

	/**
	 * @brief      繁殖
	 *             Breed
	 * @return     bool 成功为true，失败为false
	 *             bool true if success, false if fail
	 */
	virtual bool Breed() = 0;

	/**
	 * @brief      成长
	 *             Grow
	 */
	virtual void Grow(const Uint Ticks);

	/**
	 * @brief      设置生物编号
	 *             Set biological ID
	 */
	inline void SetId(const Uint Id) { id = Id; }

	/**
	 * @brief      命名
	 *             Naming
	 */
	inline void Naming(const string& Name) { name = Name; }

	/**
	 * @brief      获取名字
	 *             Get name
	 * @return     string 生物名字
	 *             string biological name
	 */
	inline string GetName() const { return name; }

	/**
	 * @brief      获取父亲名字
	 *             Get father name
	 * @return     string 父亲的名字
	 *             string father name
	 */
	inline string GetFatherName() const { return father; }

	/**
	 * @brief      获取母亲名字
	 *             Get mother name
	 * @return     string 母亲名字
	 *             string mother name
	 */
	inline string GetMotherName() const { return mother; }

	/**
	 * @brief      设置出生滴答
	 *             Set birth ticks
	 * @param      Ticks 出生滴答数
	 *             Ticks birth ticks
	 * @return     无
	 *             void
	 */
	inline void SetBirthTicks(const Uint Ticks) { birthTicks = Ticks; }

	/**
	 * @brief      获取出生滴答
	 *             Get birth ticks
	 * @return     Uint 滴答数
	 *             Uint birth ticks
	 */
	inline Uint GetBirthTicks() { return birthTicks; }

	/**
	 * @brief      判断生死
	 *             Get birth ticks
	 * @return     bool true为生，false为死
	 *             bool true if alive, false if dead
	 */
	virtual bool CheckLife() const = 0;

protected:
	/** 生物编号 */
	/** Biological ID */
	Uint id;

	/** 名字 */
	/** Name */
	string name;

	/** 出生地 */
	/** Birth place */
	string birthPlace;

	/** 出生滴答 */
	/** Birth ticks */
	Uint birthTicks;

	/** 年龄滴答 */
	/** Age ticks */
	Uint ageTicks;

	/** 价格 */
	/** Price */
	Uint price;

	/** 生死 */
	/** If alive */
	bool live;

	/** 父亲名字 */
	/** Father name */
	string father;

	/** 母亲名字 */
	/** Mother name */
	string mother;
};

