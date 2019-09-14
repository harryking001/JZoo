#pragma once
#include "time.h"
#include <random>

#define Uint unsigned int
#define ULLong unsigned long long

enum gender
{
	MALE,
	FEMALE,
	UNKNOWGD
};

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

enum hungryMsg
{
	NOTHUNGRY,
	HUNGRY,
	HUNGRYWARNING,
	HUNGRYDIE
};

const Uint BABY_ASE_PRICE = 50000;
const double GENDER_PROB = 0.5;
const double PREG_PROB = 0.1;
const int ERROR = -1;
const int TRUE = 1;
const int FALSE = 0;


int IsHappened(double p)
{
	if (p < 0 || p>1)
		return ERROR;
	std::default_random_engine random(time(NULL));
	std::uniform_real_distribution<double> dis(0.0, 1.0);
	if (dis(random) <= p)
		return TRUE;
	else
		return FALSE;
}
