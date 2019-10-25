#pragma once
#include "time.h"
#include <random>
#include <mutex>

#define Uint unsigned int
#define ULLong unsigned long long

/** �Ա� */
/** Gender */
enum gender
{
	MALE,
	FEMALE,
	UNKNOWGD
};

/** ������Ϣ */
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

/** ������Ϣ */
/** Hungry message */
enum hungryMsg
{
	NUL,
	NOTHUNGRY,
	HUNGRY,
	HUNGRYWARNING,
	HUNGRYDIE
};

/** Ӥ��������۸� */
/** Baby Asian elephant price */
const Uint BABY_ASE_PRICE = 50000;

/** ������ʳ�ﻨ�� */
/** Asian elephant food price */
const Uint ASE_FOOD_COST = 100;

/** ����������Ա���� */
/** Gender probability of a babay elephant */
const double GENDER_PROB = 0.5;

/** ���и��� */
/** Pregnant probability */
const double PREG_PROB = 0.7;

const int ERROR = -1;
const int TRUE = 1;
const int FALSE = 0;

/**
*  @brief     ���ո����ĸ��ʲ����ж��Ƿ���
*             Decide if it happens through a given probability value
*  @param     p ����
*  @return    int ����ΪERROR������ΪTRUE��δ����ΪFALSE
*             int ERROR if error, TRUE if happens, FALSE if not happens
*/
int IsHappened(double p);
