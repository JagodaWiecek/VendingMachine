#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "class.h"

void Cash::SetMoney(const double& money)
{
	Cash::money = money;
}
double Cash::GetMoney()
{
	return money;
}
bool Cash::Check()
{
	for (int i = 0; i < 6; i++)
	{
		if (GetMoney() == tab[i])
			return true;
	}

	return false;
}
Cash::Cash()
{
}
Cash::~Cash()
{
}