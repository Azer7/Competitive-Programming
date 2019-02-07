// Making a string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

int alph = 0;
long long total = 0;
long long changed = 0;
vector<long long> recur;
vector<long long> track;

int main()
{
	cin >> alph; // takes in 3 

	//takes in variables  2 2 5 vvvvv
	for (int i = 0; i < alph; i++)
	{
		int a = 0;
		cin >> a;
		recur.push_back(a);
	} 
	//--------------------------------

	for (int i = 0; i < alph; i++) // this loops through all 3 totals
	{		
		do
		{
			changed = 0; //means does not contain the value

			for (int a = 0; a < track.size(); a++)
			{      
				if (track[a] == recur[i]) changed++;
			}

			if (changed > 0) recur[i] = recur[i] - 1;
		} while (changed > 0 && recur[i] != 0);

		total = total + recur[i];
		track.push_back(recur[i]);
	}

	cout << total << endl;

	int wait = 0;
	cin >> wait;
	
    return 0;
}

