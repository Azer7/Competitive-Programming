// jackpot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i < 32662; i += 2) {
		int k = floor(sqrt((i)));
		bool prime = true;
		for (int y = 0; y < primes.size(); y++)
		{
			if (primes[y] > k)
				break;
			else if (i % primes[y] == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime == true)
			primes.push_back(i);
	}

	int cases = 0; //less that 100
	cin >> cases;

	while (cases--) {
		long long LCM = 1;
		int wheels[5] = { 0 };
		int wheelAmount = 0;
		cin >> wheelAmount;

		for (int i = 0; i < wheelAmount; i++) {
			cin >> wheels[i];
		}

		for (int i = 0; i < primes.size(); i++) {
			int largestMult = 0;
			for (int y = 0; y < wheelAmount; y++) {
				int currentMult = 0;
				for (currentMult = 0; wheels[y] % primes[i] == 0; currentMult++)
					wheels[y] /= primes[i];
				if (currentMult > largestMult)
					largestMult = currentMult;
			}

			int totalMult = 1;
			for (int y = 0; y < largestMult; y++)
				totalMult *= primes[i];

			LCM *= totalMult;

			if (LCM > 1000000000) {
				cout << "More than a billion.";
				break;
			}
		}
		if (LCM <= 1000000000) {
			for (int y = 0; y < wheelAmount; y++) {
				if (LCM <= 1000000000)
					LCM *= wheels[y];
				else {
					cout << "More than a billion.";
					break;
				}
			}
			if (LCM <= 1000000000)
				cout << LCM;
		}
	}
	return 0;
}