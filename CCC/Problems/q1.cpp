#pragma region Setup Code
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
#include <limits>

#define PI 3.1415926535897932

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

int main() {
	inputFile();
	//inputs file
	string input;
	cin >> input;
	int vs = 0;
	int hs = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'V') {
			vs++;
		}
		else {
			hs++;
		}
	}
	vs = vs % 2;
	hs = hs % 2;

	if (vs && hs) {
		cout << "4 3" << endl << "2 1";
		return 0;
	}
	if (vs) {
		cout << "2 1" << endl << "4 3";
		return 0;
	}
	if (hs) {
		cout << "3 4" << endl << "1 2";
		return 0;
	}
	cout << "1 2" << endl << "3 4";
	return 0;
}