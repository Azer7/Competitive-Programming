// Bijele.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int val = 0;

	for (int i = 0; i < 2; i++)
	{
		cin >> val;
		cout << 1 - val << " ";
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> val;
		cout << 2 - val << " ";
	}

	cin >> val;
	cout << 8 - val;

	return 0;
}

