#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    string open;
    while (cin >> open) {
        string state;
        while (cin >> state) {
            map<string, double> entrance;
            map<string, double> cost;
        
            if (state == "CLOSE") {
                map<string, double>::iterator it;
                for (it = cost.begin(); it != cost.end(); it++) {
                    cout << it->first << it->second << endl;
                }
            }
            else {
                string name;
                double time;
                cin >> name >> time;

                if (state == "ENTER") {
                    entrance[name] = time;
                } else {
                    if (cost.find(name) != cost.end()) {
                        cost[name] += (time - entrance[name]) / (double)10;
                    } else {
                        cost[name] = (time - entrance[name]) / (double)10;
                    }

                }
            }
        }
    }
  
    return 0;
}
