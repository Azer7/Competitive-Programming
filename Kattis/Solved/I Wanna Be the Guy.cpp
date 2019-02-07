// I Wanna Be the Guy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int totalLevels = 0;
	int p = 0;
	int q = 0;

	vector<int> Levels;
	vector<int> SolvableLevels; // 1 , 2 , 3 , 2 , 4

	cin >> totalLevels;


	for (int i = 1; i <= totalLevels; i++)
	{
		Levels.push_back(i); // will be 1 , 2 , 3 , 4
	}

	for (int z = 0; z < 2; z++)
	{

		cin >> p;

		int x = 0;

		for (int i = 0; i < p; i++)
		{
			cin >> x;

			SolvableLevels.push_back(x);
		}
	}

	int amountOfSolvableLevels = SolvableLevels.size();

	bool levelIsSolvable = false;
	int totalAmountOfSolvedLevels = 0;

	for (int i = 0; i < totalLevels; i++)
	{
		levelIsSolvable = false;

		for (int x = 0; x < amountOfSolvableLevels; x++)
		{
			if (Levels[i] == SolvableLevels[x])
			{
				levelIsSolvable = true;
			}
		}

		if (levelIsSolvable == true)
		{
			totalAmountOfSolvedLevels++;
		}
	}

	if (totalAmountOfSolvedLevels == totalLevels)
	{
		cout << "I become the guy.";
	}
	else
	{
		cout << "Oh, my keyboard!";
	}

	return 0;
}