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

#define PI 3.1415926535897932

using namespace std;

void inputFile() {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
	freopen("../input/day17.txt", "r", stdin);
#pragma warning(pop)
#endif	
}

class Tile
{
public:
	Tile();
	bool isWall = false;
	bool isWater = false;
	bool isDeadEnd = false;
};

Tile::Tile()
{
}

vector<vector<Tile>> tMap(2000, vector<Tile>(2000));
int maximumY = 0;
int waterCount = 0;

vector<Tile*> deadVec;
bool dfsDeadEnds(int x, int y) 
{	//return true if hit a dead end, false if endless
  	//currently on unknown tile at (x,y) could be water or solid
  	if (tMap[y][x].isWall || tMap[y][x].isDeadEnd) //check full dead end
  	{
  		return true; //dead end = "# or ~"
 	} 
	else if (tMap[y][x].isWater) 
	{
		return false; //not dead end but ending
	}



}

int main() {
	inputFile();
	//input data into cin
	do {
		string input;
		bool isX = false;

		getline(cin, input);

		if (input[0] == 'x') {
			isX = true;
		}
		int position, start, end;

		position = stoi(input.substr(2, input.find(",") - 2));
		start = stoi(input.substr(input.find("=", 4) + 1, input.find("..", 4) - input.find("=", 4) - 1));
		end = stoi(input.substr(input.find("..", 4) + 2, -1));

		for (int i = start; i <= end; i++) {
			if (isX) {
				tMap[i][position].isWall = true;
				if (i > maximumY)
					maximumY = i;
			}
			else
			{
				tMap[position][i].isWall = true;
				if (position > maximumY)
					maximumY = position;
			}
		}

	} while (cin.peek() >= 0);
	dfsDeadEnds(500, 1);
	return 0;
}