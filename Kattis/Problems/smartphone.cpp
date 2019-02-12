// smartphone.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int cases;
	int minimumKeypresses = 0;
	cin >> cases;

	while (cases--)
	{
		string wantedWord;
		string suggestion[3];

		string currentWord;
		cin >> wantedWord >> currentWord >> suggestion[0] >> suggestion[1] >> suggestion[2];

		int temp = wantedWord.length() - currentWord.length();
		minimumKeypresses = abs(temp);

		if (wantedWord == currentWord)
			minimumKeypresses = 0;

		int keypresses = 1;
		for (int y = 0; y < 3; y++)
		{
			keypresses = 1;
			for (int i = 0; i < wantedWord.length(); i++)
			{
				if (suggestion[y].length() > i)
				{
					if (suggestion[y][i] != wantedWord[i])
					{
						keypresses += (suggestion[y].length() - i) + wantedWord.length() - i;

					}
				}
			}
			if (keypresses == 1)
				keypresses += suggestion[y].length() - wantedWord.length();
			if (keypresses < minimumKeypresses)
				minimumKeypresses = keypresses;
		}
		cout << minimumKeypresses << endl;

	}

	return 0;
}

