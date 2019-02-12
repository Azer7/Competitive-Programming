// grassseed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double costPerMeter = 0, totalCost = 0;
	double width = 0, length = 0;
	int lawns = 0;

	cin >> costPerMeter >> lawns;

	while (lawns--)
	{
		cin >> width >> length;
		totalCost += costPerMeter * width * length;
	}

	cout.precision(7);
	cout << fixed << totalCost;

	return 0;
}