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
//#define INT_MAX 2147483648
//#define LLONG_MAX 9,223,372,036,854,775,807

using namespace std;

void inputFile() {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
	freopen("../input/input.txt", "r", stdin);
#pragma warning(pop)
#endif
}

void recurseMap(vector<vector<char>> &map, int row, int col, vector<vector<int>> &takenVec, int movesTaken) {
	if (map[row][col] == 'W' || map[row][col] == 'C' || map[row][col] == 'N') {
		return;
	}

	if (!(takenVec[row][col] == -1 || movesTaken < takenVec[row][col])) {
		return; //if been there before no point
	}

	takenVec[row][col] = movesTaken;

	if (map[row][col] == 'U') {
		recurseMap(map, row - 1, col, takenVec, movesTaken);
	}
	else if (map[row][col] == 'R') {
		recurseMap(map, row, col + 1, takenVec, movesTaken);
	}
	else if (map[row][col] == 'D') {
		recurseMap(map, row + 1, col, takenVec, movesTaken);
	}
	else if (map[row][col] == 'L') {
		recurseMap(map, row, col - 1, takenVec, movesTaken);
	}
	else {
		//regular recurse
		//up
		recurseMap(map, row - 1, col, takenVec, movesTaken + 1);
		//right
		recurseMap(map, row, col + 1, takenVec, movesTaken + 1);
		//down
		recurseMap(map, row + 1, col, takenVec, movesTaken + 1);
		//left
		recurseMap(map, row, col - 1, takenVec, movesTaken + 1);
	}
}

int main() {
	inputFile();
	//inputs file

	int rows, cols;
	int startRow, startCol;

	cin >> rows >> cols;
	vector<vector<char>> originalMapVec(rows, vector<char>(cols, 0));
	vector<vector<int>> movesTakenVec(rows, vector<int>(cols, -1));

	for (int i = 0; i < rows; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < cols; j++) {
			originalMapVec[i][j] = line[j];
			if (line[j] == 'S') {
				startRow = i;
				startCol = j;
			}
		}
	}
	//process cameras

	vector<vector<char>> mapVec(originalMapVec);
	for (int i = 1; i < rows - 1; i++) {
		for (int j = 1; j < cols - 1; j++) {
			if (mapVec[i][j] == 'C') {
				//up
				for (int ofs = 0; mapVec[i - ofs][j] != 'W'; ofs++) {
					if (mapVec[i - ofs][j] == '.' || mapVec[i - ofs][j] == 'S')
						mapVec[i - ofs][j] = 'N';
				}
				//right
				for (int ofs = 0; mapVec[i][j + ofs] != 'W'; ofs++) {
					if (mapVec[i][j + ofs] == '.' || mapVec[i][j + ofs] == 'S')
						mapVec[i][j + ofs] = 'N';
				}
				//down
				for (int ofs = 0; mapVec[i + ofs][j] != 'W'; ofs++) {
					if (mapVec[i + ofs][j] == '.' || mapVec[i+ofs][j] == 'S')
						mapVec[i + ofs][j] = 'N';
				}
				//left
				for (int ofs = 0; mapVec[i][j - ofs] != 'W'; ofs++) {
					if (mapVec[i][j - ofs] == '.' || mapVec[i][j - ofs] == 'S')
						mapVec[i][j - ofs] = 'N';
				}
			}
		}
	}

	recurseMap(mapVec, startRow, startCol, movesTakenVec, 0);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (originalMapVec[i][j] == '.') {
					cout << movesTakenVec[i][j] << endl;
			}
		}
	}

	return 0;
}