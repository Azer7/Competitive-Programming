// Baloni.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using namespace std;

class Balloon
{
        int height;
        int distance;
};

int main()
{
    int arrowCount = 0;
    vector<vector<int>> balloonDistances(6, -1);
    vector<vector<int>> arrowDistances(6, -1);

    int count = 0;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int height;
        cin >> height;
        balloonDistance[height - 1].push_back(i);
    }

    for (int height = balloonDistance.size() - 1; height >= 0; height--)
    {
        for(int i = 0; i < balloonDistance[height].size(); i++) {
            if (balloonDistance[height] != -1) //exists & this is the greatest height so far
            {
                if(arrowDistance[height] != -1 && arrowDistance[height] < balloonDistance[height])
                {
                    if(height > 0)
                    {
                        arrowDistance[height - 1] = balloonDistance[height];
                    }
                }
                else
                {
                    arrowCount++;
                    if(height > 0)
                    {
                        arrowDistance[height - 1] = balloonDistance[height];
                    }
                }
            }
        }
    }

    cout << arrowCount << endl;
    return 0;
}

