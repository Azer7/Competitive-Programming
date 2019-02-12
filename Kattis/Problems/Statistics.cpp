// Statistics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	for(int counter = 1; cin >> n; counter++)
	{

		vector<int> values;
		string input;
		getline(cin, input);
		stringstream parse(input);

		string value;
		int intValue = 0;

		while (parse >> value) 
		{
			stringstream convert(value);
			convert >> intValue;
			values.push_back(intValue);
		}


		long long smallestValue = 0;
		long long largestValue = 0;

		smallestValue = largestValue = values[0];

		for (int i = 0; i < values.size(); i++)
		{
			if (values[i] < smallestValue)
				smallestValue = values[i];
			if (values[i] > largestValue)
				largestValue = values[i];
		}

		cout << "Case " << counter << ": " << smallestValue << " " << largestValue << " " << largestValue - smallestValue << endl;
	}

    return 0;
}

