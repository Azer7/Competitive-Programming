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
	freopen("../Input/input.txt", "r", stdin);
#pragma warning(pop)
#endif
}

#pragma endregion

void outputVector(vector<vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << endl;
		for (int j = 0; j < vec[0].size(); j++) {
			cout << vec[i][j] << " ";
		}
	}
}

int main() {
	inputFile();
	//inputs file

	int count;

	cin >> count;
	vector<vector<int>> fenceCombos(count, vector<int>(count, 0));

	vector<int> indexToLength(count, 0);

	for (int i = 0; i < count; i++) {
		int length;
		cin >> length;
		indexToLength[i] = length;
	}
	sort(indexToLength.begin(), indexToLength.end());

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++) {
			if (i != j)
				fenceCombos[i][j] = indexToLength[i] + indexToLength[j];
		}
	}
	outputVector(fenceCombos);

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++) {
			fenceCombos[i][j] = indexToLength[i] + indexToLength[j];
		}
	}


	return 0;
}