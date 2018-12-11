
/************************************************************************/
/*

//不同路径II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
[0,0,0],
[0,1,0],
[0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/
/************************************************************************/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> result(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
		result[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
		for (int i = 1; i < result.size(); ++i)
		{
			//首行
			if (obstacleGrid[i - 1][0] == 1 || obstacleGrid[i][0] == 1)
				break;
			result[i][0] = 1;
		}
		for (int j = 1; j < result[0].size(); ++j)
		{
			//首列
			if (obstacleGrid[0][j - 1] == 1 || obstacleGrid[0][j] == 1)
				break;
			result[0][j] = 1;
		}
		//print(result);
		for (int i = 1; i < result.size(); ++i)
			for (int j = 1; j < result[i].size(); ++j)
				if (obstacleGrid[i][j] != 1) //无障碍
					result[i][j] = result[i - 1][j] + result[i][j - 1];
		return result[result.size() - 1][result[0].size() - 1];
	}

private:
	void print(const vector<vector<int>>& result)
	{
		for (int i = 0; i < result.size(); ++i)
			for (int j = 0; j < result[0].size(); ++j)
				cout << result[i][j] << " ";
			cout << endl;
	}
};


int main(int argc, char* argv[])
{
	vector<vector<int>> obstacleGrid = {
		{1},
		//{1, 0}
		/*{0,0,0},
		{0,1,0},
		{0,0,0}*/
	};
	cout << Solution().uniquePathsWithObstacles(obstacleGrid);
	return 0;
}