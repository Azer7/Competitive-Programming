#pragma region Setup Code
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <bitset>
#include <map>
#include <unordered_map>
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

int main() {
	inputFile();
	//inputs file
	int rateCount;
	cin >> rateCount;
	
	while (rateCount != 0) {
		map<string, map<string, double>> exchangeRates;
		map<string, int> currencyToIndex;
		int exchangeCount;

		vector<string> currencyNames;
		map<string, double> currencyInit;
		for (int i = 0; i < rateCount; i++) {
			string currencyName;
			cin >> currencyName;

			currencyNames.push_back(currencyName);
			currencyInit.insert(pair<string, double>(currencyName, 0.0));
		}

		for (int i = 0; i < currencyNames.size(); i++) {
			exchangeRates.insert(pair<string, map<string, double>>(currencyNames[i], map<string, double>()));
			//better worst casevv??
			//exchangeRates.insert(pair<string, map<string, double>>(currencyNames[i], currencyInit));
		}
		//map of currencies generated
		//
		cin >> exchangeCount;

		for (int i = 0; i < exchangeCount; i++) {
			string cur1, cur2, rate;
			cin >> cur1 >> cur2 >> rate;
			unsigned long long pos;
			double rate1 = stod(rate, &pos);
			double rate2 = stod(rate.substr(pos + 1));
			double conversionRate = rate2 / rate1;

			auto mainCurrencyIt = exchangeRates.find(cur1);
			
			auto conversionIt = mainCurrencyIt->second.find(cur2);

			if (conversionIt != mainCurrencyIt->second.end()) {
				//the item exists
				if (conversionRate > conversionIt->second) {
					//if the new conversion is larger 
					
				}
				//else do nothing since that ain't makin $$ ;d
			}
		}

		cin >> rateCount;
	}


	return 0;
}