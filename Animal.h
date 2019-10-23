#pragma once
#include "Biological.h"

//动物界
class Animal :
	public Biological
{
	friend class ArchiveFile;
	friend class Zoo;
	friend void ShowStatus();
public:
	Animal();
	Animal(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd);
	Animal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
		Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Animal();

	/**
	 * @brief      进食
	 *             Get birth ticks
	 * @return     Uint 食物花费
	 *             Uint birth ticks
	 */
	virtual Uint Eat() = 0;

	/**
	 * @brief      排泄
	 *             Excrete
	 */
	virtual void Excrete() = 0;

	/**
	 * @brief      检查饥饿情况
	 *             Check hungry message
	 * @return     hungryMsg 饥饿信息
	 *             hungryMsg hungry message
	 */
	virtual hungryMsg CheckHungry() const = 0;

	/**
	 * @brief      判断怀孕
	 *             Check if pregnant
	 * @return     bool true为怀孕，false为未怀孕
	 *             bool true if pregnant, false if not pregnant
	 */
	virtual inline bool IsPreg() const{ return preg; }

	/**
	 * @brief      判断是否繁殖
	 *             Check if breeding
	 * @return     bool true为准备繁殖，false为未准备繁殖
	 *             Uint true if breeding, false if not breeding
	 */
	virtual bool CheckBreed() const = 0;

	/**
	 * @brief      设置性别
	 *             Ser animal gender
	 * @param      gend 动物性别
	 *             gend animal gender
	 */
	inline void SetGender(const gender& gend) { gd = gend; }

	/**
	 * @brief      获取动物性别
	 *             Get animal gender
	 * @return     gender 动物性别
	 *             gender animal gender
	 */
	inline gender GetGender() { return gd; }
protected:
	/** 体重 */
	/** Body weight */
	Uint weight;

	/** 身高 */
	/** Body height */
	Uint height;

	/** 体宽 */
	/** Body width */
	Uint width;

	/** 身长 */
	/** Body length */
	Uint length;

	/** 性别 */
	/** Gender */
	gender gd;

	/** 饥饿滴答 */
	/** Hungry ticks */
	Uint hungryTicks;

	/** 怀孕滴答 */
	/** Pregnant ticks */
	Uint pregTicks;

	/** 交配滴答 */
	/** Mate ticks */
	Uint mateTicks;

	/** 是否怀孕 */
	/** If pregnant */
	bool preg;
};

