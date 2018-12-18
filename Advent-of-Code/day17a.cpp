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

#define PI 3.1415926535897932

using namespace std;

void inputFile() {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
	freopen("../input/day17.txt", "r", stdin);
#pragma warning(pop)
#endif	
}


vector<vector<char>> map(2000, vector<char>(2000, (char)'.'));

int main() {
	inputFile();
	//input data into cin
	int i = 0;
	string s;
	do {
		getline(cin, s);
		i++;
	} while (cin.peek() >= 0);




	return 0;
}