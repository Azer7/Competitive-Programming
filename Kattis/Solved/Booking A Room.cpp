// Booking A Room.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int rooms = 0;
	int bookedRooms = 0;
	vector<int> roomNumbers;

	cin >> rooms >> bookedRooms;

	if (bookedRooms == rooms)
		cout << "too late";
	else
	{
		int roomNumber = 0;
		for (int i = 0; i < bookedRooms; i++)
		{
			cin >> roomNumber;
			roomNumbers.push_back(roomNumber);
		}

		for (int i = 1; i <= rooms; i++)
		{
			bool booked = false;
			for (int y = 0; y < roomNumbers.size(); y++)
			{
				if (roomNumbers[y] == i)
				{
					booked = true;
					break;
				}
			}

			if (booked == false)
			{
				cout << i;
				return 0;
			}
		}
	}

    return 0;
}

