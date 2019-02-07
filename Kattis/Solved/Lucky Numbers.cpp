// Lucky Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 9;
	int total = 0;

	bool stillWorks = true;
	/*for (int i = 100; i <= 999; i++)
	{
		if ((i % 10) % 2 == 0 && i % 3 == 0)
			total++;
	}*/

	for (long long i = 100000; i <= 999999; i++)
	{
		stillWorks = true;

		if ((i % 10000) % 2 != 0)
			stillWorks = false;

		if ((i % 1000) % 3 != 0)
			stillWorks = false;

		if ((i % 100) % 4 != 0)
			stillWorks = false;

		if ((i % 10) % 5 != 0)
			stillWorks = false;

		if ((i % 1) % 6 != 0)
			stillWorks = false;


		if (stillWorks == true)
			total++;
	}
	
	return 0;
}

