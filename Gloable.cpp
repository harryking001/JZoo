#include "Gloable.h"

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