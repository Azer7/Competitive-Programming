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
int maxPerDay;
int days;
int max(vector<int> score, int start, int end) {
	int max = 0;
	if (end > score.size()) {
		for (int i = start; i < end; i++) {
			if (score[i] > max)
				max = score[i];
		}
	}
	else {
		for (int i = start; i < score.size(); i++) {
			if (score[i] > max)
				max = score[i];
		}
	}

	return max;
}

int recursion(vector<int> score, int countLeft, int position) {
	int maxScore = 0;
	for (int i = 0; i <= countLeft && position + maxPerDay - i - 1 < maxPerDay * days ; i++) {
		
		int curScore = max(score, position, position + maxPerDay - i);
		curScore += recursion(score, countLeft - i, position + maxPerDay - i);
		if (curScore > maxScore)
			maxScore = curScore;
	}

	return maxScore;
}

int main() {
	inputFile();
	//inputs file

	int count;
	
	vector<int> score;
	int rollingTotal = 0;
	cin >> count >> maxPerDay;
	days = ceil((double)count / (double)maxPerDay);
	for (int i = 0; i < count; i++) {
		int input;
		cin >> input;
		score.push_back(input);
	}

	int roomForError = maxPerDay - (count % maxPerDay); //how many spaces to spare
	
	cout <<  recursion(score, roomForError, 0);
	return 0;
}