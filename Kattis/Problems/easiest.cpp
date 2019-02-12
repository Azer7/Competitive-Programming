// easiest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int sumOfN = 0, sumOfNxM = 0;
	long currentN = 0, currentNxM = 0;
	long tempN = 0, tempNxM = 0;

	cin >> currentN;

	if (currentN)
	{
		do {
			tempN = currentN;
			
			sumOfN = 0;
			while (tempN > 0)
			{
				sumOfN += tempN % 10;
				tempN /= 10;
			}

			for (int m = 11; ; m++)
			{
				currentNxM = currentN * m;
				tempNxM = currentNxM;
					
				sumOfNxM = 0;
				while (tempNxM > 0)
				{
					sumOfNxM += tempNxM % 10;
					tempNxM /= 10;
				}

				if (sumOfN == sumOfNxM)
				{
					cout << m << endl;
					break;
				}
			}

			cin >> currentN;
		} while (currentN);
	}

	return 0;
}