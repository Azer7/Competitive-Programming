#pragma region SetupFiles

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>

#define PI 3.1415926535897932
#define INT_MAX std::numeric_limits<int>::max()
#define LONGLONG_MAX std::numeric_limits<long long>::max()

using namespace std;

void inputFile() {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
	freopen("../input/input.txt", "r", stdin);
#pragma warning(pop)
#endif
}

#pragma endregion

int getFactor (int n) {
	bool isPrime = true;
	for (int i = 2; i*i <= n; ++i)
	{
		if (n % i == 0)
		{
			return i; 
		}
	}
	return n;
}

int main() {
	//inputFile();
	//inputs file
	
	int q;
	cin >> q;
	if (q == 1) {
		cout << "no" << endl;
		return 0;
	}
	int factor = getFactor(q);
	while (q % factor == 0) {
		q /= factor;
	}
	 
	if (q == 1) {
		cout << "yes";
	}
	else {
		cout << "no";
	}

	cout << endl;
	return 0;
}