#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count = 0;
    vector<int> weightVariations; //to improve speed at expense of memory
    vector<bool> weight(2001, false);

    weightVariations.push_back(0);
    weight[0] = true;

    cin >> count;

    while(count--) {
        int currentWeight = 0;
        cin >> currentWeight;
        int weightCount = weightVariations.size();
        for(int i = 0; i < weightCount; i++) {
            int total = weightVariations[i] + currentWeight;
            if(total <= 2000 && !weight[total]) {
                weight[total] = true;
                weightVariations.push_back(total);
            }
        }
    }
  
    for(int i = 0; i <= 1000; i++) {
        if(weight[1000 + i]) {
			cout << 1000 + i << endl;
			return 0;
		}
		if(weight[1000 - i]) {
			cout << 1000 - i << endl;
			return 0;
		}
    }

return 0;
}

