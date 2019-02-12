#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ant
{
public:
    bool exist;
    char direction;
};

int leftFirstSearch()
{
    int upp


    return 0;
}

int rightFirstSearch()
{

    return 0;
}

int getDirectionCount(vector<Ant> &ants, int position)
{
    int total = 0;

    for (int i = position + 1; i < ants.size(); i++)
    {
        if (ants[i].exist && ants[i].direction == 'L')
            total--;
    }
    for (int i = position - 1; i >= 0; i--)
    {
        if (ants[i].exist && ants[i].direction == 'R')
            total++;
    }
    return total;
}

int main()
{
    int pipeSize = 0;
    int antCount = 0;
    while (cin >> pipeSize >> antCount)
    {
        vector<Ant> ants(pipeSize);
        int leftMost = 9999999;
        int rightMost = -1;

        for (int i = 0; i < antCount; i++)
        {
            int position;
            char direction;
            cin >> position >> direction;
            ants[position].exist = true;
            ants[position].direction = direction;

            if (direction == 'L')
            {
                if (position > rightMost)
                    rightMost = position;
            }
            else
            {
                if (position < leftMost)
                    leftMost = position;
            }
        }
        int leftToRightTime = -1;
        int rightToLeftTime = -1;
        if (leftMost <= 99999)
            leftToRightTime = pipeSize - leftMost;

        if (rightMost >= 0)
            rightToLeftTime = rightMost;


        if (leftToRightTime > rightToLeftTime)
        {
            cout << "The last ant will fall down in " << leftToRightTime;
            cout << " seconds - started at " << leftFallSearch() << ".";
        }
        else if (leftToRightTime < rightToLeftTime)
        {
            cout << "The last ant will fall down in " << rightToLeftTime;
            cout << " seconds - started at " << rightFallSearch() << ".";
        }
        else
        {
            int leftToRightPos = leftFallSearch();
            int rightToLeftPos = rightFallSearch();

            cout << "The last ant will fall down in " << rightToLeftTime << " seconds - started at ";
            if (leftToRightPos < rightToLeftPos)
                cout << leftToRightPos << " and " << rightToLeftPos << ".";
            else
                cout << rightToLeftPos << " and " << leftToRightPos << ".";
        }
        cout << endl;
    }

// your code goes here
    return 0;
}
