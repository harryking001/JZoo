#pragma once
#include "time.h"
#include <random>
#include <mutex>

#define Uint unsigned int
#define ULLong unsigned long long

/** 性别 */
/** Gender */
enum gender
{
	MALE,
	FEMALE,
	UNKNOWGD
};

/** 交配信息 */
/** Mate message */
enum mateMsg
{
	PREGNANT,
	NOTPREGNANT,
	MALE_UNDERMATEAGE,
	FEMALE_UNDERMATEAGE,
	MALE_NOTREADY,
	FEMALE_NOTREADY,
	SEX_WRONG,
	MISSING_MALE,
	MISSING_FEMALE,
	INBREED,
};

/** 饥饿信息 */
/** Hungry message */
enum hungryMsg
{
	NUL,
	NOTHUNGRY,
	HUNGRY,
	HUNGRYWARNING,
	HUNGRYDIE
};

/** 婴儿亚洲象价格 */
/** Baby Asian elephant price */
const Uint BABY_ASE_PRICE = 50000;

/** 亚洲象食物花费 */
/** Asian elephant food price */
const Uint ASE_FOOD_COST = 100;

/** 出生大象的性别概率 */
/** Gender probability of a babay elephant */
const double GENDER_PROB = 0.5;

/** 怀孕概率 */
/** Pregnant probability */
const double PREG_PROB = 0.7;

const int ERROR = -1;
const int TRUE = 1;
const int FALSE = 0;

/**
*  @brief     按照给定的概率参数判断是否发生
*             Decide if it happens through a given probability value
*  @param     p 概率
*  @return    int 错误为ERROR，发生为TRUE，未发生为FALSE
*             int ERROR if error, TRUE if happens, FALSE if not happens
*/
int IsHappened(double p);
