// oddities.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int cases = 0;
	int value = 0;
	cin >> cases;

	while (cases--)
	{
		cin >> value;

		cout << value;
		if (value % 2 == 0)
			cout << " is even" << endl;
		else
			cout << " is odd" << endl;
	}

	return 0;
}

