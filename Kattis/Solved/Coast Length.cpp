// Coast Length.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <istream>
#include <Windows.h>
#include <vector>

using namespace std;

int main()
{
	int rows, columns;
	vector<vector<short>> map;
	vector<short[3]> pathStack;

	cin >> rows >> columns;


	map.push_back({});
	for (int i = 0; i < columns + 2; i++)
		map[0].push_back(9);

	char currentMapTile;
	for (int row = 1; row <= rows; row++)
	{
		map.push_back({});
		map[row].push_back(9);  //0 is land |1 is unchecked |2 is right checked  |3 is down checked  |4 is left checked  |5 is all checked |9 is sea
		for (int column = 0; column < columns; column++)
		{

			cin.get(currentMapTile);
			if (currentMapTile == '\n')
				cin.get(currentMapTile);

			map[row].push_back(-1*(currentMapTile - 48));
		}
		map[row].push_back(9);
	}

	Sleep(5000);
	return 0;
}

