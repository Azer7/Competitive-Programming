// Cold-puter Science.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iter = 0;
	int total = 0;

	string inputNum;

	cin >> iter;

	while (iter--)
	{
		cin >> inputNum;
		if (inputNum[0] == '-')
			total++;
	}

	cout << total;
    return 0;
}