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
#include <limits>
#include <iomanip>

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

double getLength(int paperNumber) {
	double A2Length = powl(2, -0.75); //sideLength of A2
	double A2Width = powl(2, -1.25);
	double sideLength = 0;
	if (paperNumber % 2 == 0) { //if even it's just half
		sideLength = A2Length / pow(2, (paperNumber / 2) - 1); // half fraction
	}
	else { //odd
		sideLength = A2Width / pow(2, ((paperNumber - 1) / 2) - 1);
	}

	return sideLength;
}

int main() {
	inputFile();
	//inputs file
	int largest;
	cin >> largest;

	int needPaper[30];
	int hasPaper[30];
	needPaper[0] = 1; //need one A1

	int i;
	bool possible = false;
	for (i = 1; i < largest; i++) {
		int count;
		cin >> count;

		hasPaper[i] = count;
		needPaper[i] = needPaper[i - 1] * 2 - count; //double the previous!
		//check if already have enough paper

		if (needPaper[i] <= 0) {
			hasPaper[i] += needPaper[i];//don't go overboard
			possible = true;
			break; //can calculate float
		}
	}

	if (!possible) {
		cout << "impossible" << endl;
		return 0;
	}

	//possible, calculate float
	double tape = 0;
	for (int b = i; b >= 1; b--) {  //loop back and add the totals
		int toTape = hasPaper[b] / 2; //number of pages to tape
		tape += toTape * getLength(b + 1);
		hasPaper[b - 1] += toTape;
	}

	cout << fixed << setprecision(15);
	cout << tape << endl;
	return 0;
}