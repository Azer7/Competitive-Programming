// Autori.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	string output;

	cin >> input;

	output += input[0];

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '-')
		{
			output += input[i + 1];
		}
	}

	cout << output;
    return 0;
}

