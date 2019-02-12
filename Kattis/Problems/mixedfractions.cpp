// mixedfractions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int numerator = 0, denominator = 0, mixedVal = 0;
	cin >> numerator >> denominator;
	while (!(numerator == 0 && denominator == 0))
	{
		mixedVal = numerator / denominator;
		cout << mixedVal << " " << numerator - (mixedVal * denominator) << " / " << denominator << endl;
		cin >> numerator >> denominator;
	}

    return 0;
}