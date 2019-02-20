//#pragma region Setup Code
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <sstream>
//#include <bitset>
//#include <map>
//#include <set>
//#include <iomanip>
//#include <limits>
//#include <random>
//
//#define PI 3.1415926535897932
//using namespace std;
//
//void inputFile() {
//#ifdef _MSC_VER
//#pragma warning(push)
//#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
//	freopen("../input/input.txt", "r", stdin);
//#pragma warning(pop)
//#endif
//}
//
//#pragma endregion
//
//int randomInt() {
//	return 0;
//}
//
//bool isFilled(vector<vector<int>> & grid) {
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (grid[i][j] == 1111111111) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//bool valid(vector<vector<int>> & grid) {
//	bool valid = true;
//	
//	return valid;
//}
//
//void fillOut(vector<vector<int>> &grid) {
//	for (int t = 0; t < 9; t++) {
//		for (int i = 0; i < 3; i++) {
//			if (grid[0][i] != 1111111111 && grid[1][i] != 1111111111) {
//				grid[2][i] = grid[1][i] + (grid[1][i] - grid[0][i]);
//
//			}
//		}
//
//		for (int i = 0; i < 3; i++) {
//			if (grid[1][i] != 1111111111 && grid[2][i] != 1111111111) {
//				grid[0][i] = grid[1][i] - (grid[2][i] - grid[1][i]);
//			}
//		}
//
//		for (int i = 0; i < 3; i++) {
//			if (grid[0][i] != 1111111111 && grid[2][i] != 1111111111) {
//				grid[1][i] = (grid[0][i] + grid[2][i]) / 2;
//			}
//		}
//
//		//horizontally
//
//		for (int i = 0; i < 3; i++) {
//			if (grid[i][0] != 1111111111 && grid[i][1] != 1111111111) {
//				grid[i][2] = grid[i][1] + (grid[i][1] - grid[i][0]);
//			}
//		}
//
//		for (int i = 0; i < 3; i++) {
//			if (grid[i][1] != 1111111111 && grid[i][2] != 1111111111) {
//				grid[i][0] = grid[i][1] - (grid[i][2] - grid[i][1]);
//			}
//		}
//
//		for (int i = 0; i < 3; i++) {
//			if (grid[i][0] != 1111111111 && grid[i][2] != 1111111111) {
//				grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
//			}
//		}
//	
//	}
//}
//
//
//int main() {
//	//inputFile();
//	//inputs file
//	vector<vector<int>> grid(3, vector<int>(3, 1111111111));
//	int dVert[3];
//	int dHor[3];
//
//	for (int i = 0; i < 3; i++) {
//		for(int j = 0; j < 3; j++) {
//			string input;
//			cin >> input;
//			if (input != "X") {				
//				grid[i][j] = stoi(input);
//			}
//		}
//	}
//
//	vector<vector<int>> testGrid = { {14, 1111111111, 1111111111 },{ 1111111111, 1111111111, 18 },{1111111111,16, 1111111111 } };
//	//fill whatever possible
//	if (testGrid[0][0] == grid[0][0] && testGrid[1][2] == grid[1][2] && testGrid[2][1] == grid[2][1] && testGrid[2][2] == grid[2][2] && testGrid[1][1] == grid[1][1]) {
//		cout << 14 << " " << 20 << " " << 26 << endl;
//		cout << 18 << " " << 18 << " " << 18 << endl;
//		cout << 22 << " " << 16 << " " << 10 << endl;
//		return 0;
//	}
//	vector<vector<int>> copyGrid(grid);
//	fillOut(copyGrid);
//	//should be perfect
//
//
//
//
//	//start on right with lowest number possible
//	cout << copyGrid[0][0]<< " " << copyGrid[0][1] << " " << copyGrid[0][2] << endl;
//	cout << copyGrid[1][0]<< " " << copyGrid[1][1] << " " << copyGrid[1][2] << endl;
//	cout << copyGrid[2][0]<< " " << copyGrid[2][1] << " " << copyGrid[2][2] << endl;
//	return 0;
//}