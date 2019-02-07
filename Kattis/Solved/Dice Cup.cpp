// Dice Cup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int dieOne = 0, dieTwo = 0;
	int biggerDie = 0, smallerDie = 0;

	cin >> dieOne >> dieTwo;

	if (dieOne > dieTwo)
	{
		biggerDie = dieOne;
		smallerDie = dieTwo;
	}
	else
	{
		biggerDie = dieTwo;
		smallerDie = dieOne;
	}

	for (int i = smallerDie + 1; i <= biggerDie + 1; i++)
	{
		cout << i;

		if (i != biggerDie + 1)
			cout << " ";
	}

		return 0;
}

