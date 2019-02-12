// Ants.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int testCases = 0;
	cin >> testCases;
	while (testCases--)
	{
		int poleLen = 0;
		int ants = 0;
		int longestDist = 0;
		int shortestDist = 0;
		cin >> poleLen >> ants;
		while (ants--)
		{
			int position = 0;
			cin >> position;
			if (poleLen - position < position)
			{
				if (poleLen - position > shortestDist)
					shortestDist = poleLen - position;
			}
			else
			{
				if (position > shortestDist)
					shortestDist = position;
			}

			if (poleLen - position > position)
			{
				if (poleLen - position > longestDist)
					longestDist = poleLen - position;
			}
			else
			{
				if (position > longestDist)
					longestDist = position;
			}
		}
		cout << shortestDist << " " << longestDist << endl;
	}

	return 0;
}