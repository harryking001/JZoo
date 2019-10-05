#pragma once
#include "time.h"
#include <random>
#include <mutex>

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
	NUL,
	NOTHUNGRY,
	HUNGRY,
	HUNGRYWARNING,
	HUNGRYDIE
};

const Uint BABY_ASE_PRICE = 50000;
const Uint ASE_FOOD_COST = 100;
const double GENDER_PROB = 0.5;
const double PREG_PROB = 0.2;
const int ERROR = -1;
const int TRUE = 1;
const int FALSE = 0;

//std::mutex mtx;

int IsHappened(double p);
