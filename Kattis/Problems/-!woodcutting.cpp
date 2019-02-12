#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
    int cases;
    std::cin >> cases;

    while (cases--) {
        std::vector<double> customerTimes;
        long long customers;
        std::cin >> customers;
        
        for (int i = 0; i < customers; i++) {
            customerTimes.push_back(0);
            int pieces;
            std::cin >> pieces;
            while (pieces--) {
                int pieceSize;
                std::cin >> pieceSize;
                customerTimes[i] += pieceSize;
            } 
        }
        std::sort(customerTimes.begin(), customerTimes.end());

        double runningTime = 0;
		double totalTime = 0;
        for (int i = 0; i < customerTimes.size(); i++) {
			runningTime += customerTimes[i];
			totalTime += runningTime;
        }
        std::cout << std::fixed << std::setprecision(10);
        std::cout << totalTime / (double)customers << '\n';
    }

    return 0;
}