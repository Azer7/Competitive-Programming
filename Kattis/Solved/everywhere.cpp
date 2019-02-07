// everywhere.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cases = 0, cities = 0, citiesVisited = 0;
	string currentCity;
	string cityList[101] = { "" };
	cin >> cases;

	while (cases--)
	{
		citiesVisited = 0;
		cin >> cities;
		while (cities--)
		{
			cin >> currentCity;
			bool contains = false;
			for (int i = 0; i < citiesVisited; i++)
			{
				if (cityList[i] == currentCity)
					contains = true;
			}

			if (!contains)
			{
				cityList[citiesVisited] = currentCity;
				citiesVisited++;
			}
		}
		cout << citiesVisited;
		if (cases)
			cout << endl;
	}

	return 0;
}