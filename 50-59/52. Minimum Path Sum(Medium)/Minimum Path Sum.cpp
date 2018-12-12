/************************************************************************/
/* 

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
[1,3,1],
[1,5,1],
[4,2,1]
]
Output: 7
Explanation: Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.

*/
/************************************************************************/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		vector<vector<int>> result(grid);
		int m = result.size();
		int n = result[0].size();
		for (int i = 1; i < m; ++i)
			result[i][0] += result[i - 1][0];
		for (int j = 1; j < n; ++j)
			result[0][j] += result[0][j - 1];
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				result[i][j] = std::min(result[i - 1][j], result[i][j - 1]) + result[i][j];
		return result[m - 1][n - 1];
	}
};

int main()
{
	vector<vector<int>> grid = {
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};
	cout << Solution().minPathSum(grid);
	return 0;
}