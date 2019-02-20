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
//#include <math.h>
//#include <iomanip>
//#include <limits>
//
//#define PI 3.1415926535897932
//
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
//int main() {
//	inputFile();
//	//inputs file
//	vector<bool> * primes = new vector<bool>(1100000, 1);	
//	primes->at(0) = false;
//	primes->at(1) = false;
//	for (int i = 2; i*i < 1100000; i++) {
//		if (primes->at(i)) {
//			for (long long j = i * 2; j < 1100000; j += i) {
//				primes->at(j) = false;
//			}
//		}
//	}
//	
//
//	
//
//
//	int count;
//	cin >> count;
//	while (count--) {
//		int input;
//		cin >> input;
//
//		for (int i = 0; ; i++) {
//			if (primes->at(input + i) && primes->at(input + i) == primes->at(input - i)) {
//				cout << input + i << " " << input - i << endl;
//				break;
//			}
//		}
//
//	}
//
//	return 0;
//}