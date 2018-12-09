/************************************************************************/
/*

Spiral Matrix II

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]

*/
/************************************************************************/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result;
		for (int i = 0; i < n; ++i)
			result.push_back(vector<int>(n));

		int i = 0, j = -1;
		int num = 1;
		while (n > 0)
		{
			//循环插值
			for (int x = 0; x < n; ++x) //go right 需要走n步
				result[i][++j] = num++;

			for (int x = 0; x < n - 1; ++x) //go down 需要走n-1步
				result[++i][j] = num++;

			for (int x = 0; x < n - 1; ++x) //go left 需要走n-1步
				result[i][--j] = num++;

			for (int x = 0; x < n - 2; ++x) //go up 需要走n-2步
				result[--i][j] = num++;

			n -= 2;
		}
		return result;
	}
};

int main(int argc, char* argv[])
{

	vector<vector<int>> result = Solution().generateMatrix(5);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result.size(); ++j)
		{
			cout << result[i][j] << " ";
		}	
		cout << std::endl;
	}
		

	return 0;
}