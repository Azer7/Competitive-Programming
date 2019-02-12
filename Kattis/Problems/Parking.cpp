// Parking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int price[4] = { 0 };
	int amountOfParkedTrucks = 0;
	int largestTime = 0;

	int totalCost = 0;

	int truckTime[3][2] = { 0 };

	cin >> price[1] >> price[2] >> price[3];

	for (int i = 0; i < 3; i++)
	{
		for (int y = 0; y < 2; y++)
		{
			int time = 0;
			cin >> time;
			if (time > largestTime)
				largestTime = time;

			truckTime[i][y] = time;
		}
	}

	for (int i = 1; i <= largestTime; i++)
	{
		for (int enter = 0; enter < 3; enter++)
		{
			if (truckTime[enter][0] == i)
				amountOfParkedTrucks++;
		}

		for (int exit = 0; exit < 3; exit++)
		{
			if (truckTime[exit][1] == i)
				amountOfParkedTrucks--;
		}

		totalCost += price[amountOfParkedTrucks];
	}

	cout << totalCost;
		return 0;
}

