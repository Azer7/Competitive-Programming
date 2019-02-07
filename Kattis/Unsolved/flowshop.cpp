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
	freopen("../input/input.txt", "r", stdin);
#pragma warning(pop)
#endif
}

int outputCount = 1;

void consoleVector(vector<vector<int>> vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[0].size(); j++) {
			cout << " " << vec[i][j];
		}
		cout << endl;
	}
}

void propagate(int timeToUse, vector<vector<int>> &rows, int rowIndex, int colIndex, vector<int>& rowTime) {
	for (; colIndex < rows[0].size() && rows[rowIndex][colIndex] == 0; ++colIndex);
	//this should never land on 0 because outputCount should not let it however it could

	while (timeToUse > 0) { //on row rowIndex propagate rightwards --> 
		//if can use up time then go for it otherwise need to wait and process down
		if (rows[rowIndex - 1][colIndex] == 0) { //doesn't have to wait for things to complete
			if (rowIndex - 1 >= outputCount) {
				//get rid of a number
				int time = rows[rowIndex][colIndex];
				rowTime[rowIndex] += time;

				rows[rowIndex][colIndex] = 0; //set distance left to 0 after adding it to the time total;

				timeToUse -= time;
				//pass the time upwards
				propagate(time, rows, rowIndex - 1, colIndex + 1, rowTime);
			}
		}
		else
		{
			//clear up top by scanning up and doing minimum and substracting by time taken (use up a tad of the time)
			int i = rowIndex;
			for (; rows[i-1][colIndex] != 0; i--);

			//subtract that row time
			timeToUse -= rows[i][colIndex];
			rowTime[rowIndex] += rows[i][colIndex];
		}
		
		consoleVector(rows);

		colIndex++;
		if (colIndex > rows[0].size() - 1) {
			cout << rowTime[rowIndex];
			outputCount++;
			timeToUse = 0; //exit as done
		}
	}

}

int main() {
	inputFile();
	//inputs file

	int rowCount;
	int stages;

	cin >> rowCount >> stages;

	vector<int> rowTime(rowCount + 1, 0);
	vector<vector<int>> rows(rowCount + 1, vector<int>(stages, 0));

	for (int i = 1; i < rowCount + 1; i++) {
		for (int j = 0; j < stages; j++) {
			int input;
			cin >> input;
			rows[i][j] = input;
		}
	}

	//int i = stages - 1;
	//for (int row = outputCount; row < rowCount; row++) { // loops through and finds the latest in first row wise
	//	for (; i > 0 && rows[row][i] != 0; i--);
	//	if (rows[row][i] == 0)
	//		i++;
	//}
	////currently index where worker is at
	//
	propagate(INT_MAX, rows, rows.size() - 1, 0, rowTime);





	return 0;
}