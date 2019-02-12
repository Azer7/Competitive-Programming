// fizzbuzz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	char ch = 'A';
	cout << ch;
	
	if (ch < 91 && ch > 64)
		ch += 32;
	cout << ch;


	Sleep(2000);
	return 0;
}