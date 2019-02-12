// Two Stones.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	while (true)
	{
		long long n = 0;
		std::cin >> n;
		if (n % 2 == 0)
			std::cout << "Bob";
		else
			std::cout << "Alice";
	}
    return 0;
}

