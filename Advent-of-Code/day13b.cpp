#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
int TURN_LEFT = 0;
int TURN_RIGHT = 2;

int *addr;

class Car
{
  public:
    Car(char);
    void turn(int *);
    int direction;
    int turnCount;
    bool hasMoved;
};

Car::Car(char cahr)
{
    turnCount = 0;
    hasMoved = false;

    switch (cahr) // 1:U 2:R 3:D 4:L
    {
    case '<':
        direction = 3; // LEFT
        break;
    case '>':
        direction = 1; // RIGHT
        break;
    case '^':
        direction = 0; // UP
        break;
    case 'v':
        direction = 2; // DOWN
        break;
    }
}

void Car::turn(int *turnDir)
{
    switch (*turnDir)
    {
    case 0:
        direction += 3; // turn left
        break;
    case 1:
        //go straight
        break;
    case 2:
        direction += 1; //Right
        break;
    }
    direction %= 4;

    if (turnDir == &turnCount)
    {
        turnCount++;
        turnCount %= 3;
    }
}

vector<vector<Car *>> cars(150, vector<Car *>(150));
vector<vector<char>> map(150, vector<char>(150));
// vector<vector<Car *>> cars(6, vector<Car *>(14));

// vector<vector<char>> map(6, vector<char>(14));

std::pair<int, int> getCrash()
{
    while (true)
    {
        vector<pair<Car *, pair<int, int>>> movedCars;
        for (int i = 0; i < cars.size(); i++)
        {
            for (int j = 0; j < cars[i].size(); j++)
            {
                if (cars[i][j] && !cars[i][j]->hasMoved)
                {
                    //check movement
                    int xMove = 0;
                    int yMove = 0;
                    switch (cars[i][j]->direction)
                    {
                    case UP:
                        yMove = -1;
                        break;
                    case RIGHT:
                        xMove = 1;
                        break;
                    case DOWN:
                        yMove = 1;
                        break;
                    case LEFT:
                        xMove = -1;
                        break;
                    }
                    //is there a car there?
                    if (cars[i + yMove][j + xMove])
                    {
                        cars[i][j] = 0x0;
                        cars[i + yMove][j + xMove] = 0x0;
                    }
                    else
                    {
                        //move
                        cars[i + yMove][j + xMove] = cars[i][j];
                        //turn
                        if (map[i + yMove][j + xMove] == '+')
                        {
                            addr = &cars[i][j]->turnCount;
                            cars[i][j]->turn(&cars[i][j]->turnCount); //1: right 3:left
                        }
                        else if (map[i + yMove][j + xMove] == '/')
                        {
                            if (cars[i][j]->direction == UP || cars[i][j]->direction == DOWN) //if going up or down
                            {
                                cars[i][j]->turn(&TURN_RIGHT); //turn right
                            }
                            else if (cars[i][j]->direction == RIGHT || cars[i][j]->direction == LEFT) //if going right of left
                            {
                                cars[i][j]->turn(&TURN_LEFT); //turn left
                            }
                        }
                        else if (map[i + yMove][j + xMove] == '\\')
                        {
                            if (cars[i][j]->direction == UP || cars[i][j]->direction == DOWN) //if going up or down
                            {
                                cars[i][j]->turn(&TURN_LEFT); //turn left
                            }
                            else if (cars[i][j]->direction == RIGHT || cars[i][j]->direction == LEFT) //if going right of left
                            {
                                cars[i][j]->turn(&TURN_RIGHT); //turn right
                            }
                        }
                        cars[i][j]->hasMoved = true;
                        movedCars.push_back(pair<Car *, pair<int,int>>(cars[i][j], pair<int, int>(j, i)));
                        cars[i][j] = 0x0; //RESET VALUE
                    }
                }
            }
        }

        for (pair<Car *, pair<int, int>> car : movedCars)
        {
            car.first->hasMoved = false;
        }

        if(movedCars.size() == 1) {
            return pair<int, int> (movedCars[0].second.first, movedCars[0].second.second); 
        }
        // for (int i = 0; i < cars.size(); i++)
        // {
        //     for (int j = 0; j < cars[i].size(); j++)
        //     {
        //         if (cars[i][j])
        //             cout << "C";
        //         else
        //             cout << map[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // cout << endl;
    }

    return pair<int, int>(-1, -1);
}

int main()
{
    std::ifstream fin("./input/input13.txt");

    // std::ifstream fin("./input/debug13.txt");

    for (int row = 0; row < 150; row++)
    {
        string line;
        getline(fin, line);
        for (int col = 0; col < 150; col++)
        {
            if (line[col] == '<' || line[col] == '>')
            {
                cars[row][col] = new Car(line[col]);
                map[row][col] = '-';
            }
            else if (line[col] == '^' || line[col] == 'v')
            {
                cars[row][col] = new Car(line[col]);
                map[row][col] = '|';
            }
            else
            {
                map[row][col] = line[col];
            }
        }
    }

    std::pair<int, int> crashLocation = getCrash();

    return 0;
}