
/************************************************************************/
/* 

//螺旋矩阵

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
	[ 1, 2, 3 ],
	[ 4, 5, 6 ],
	[ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
	[1, 2, 3, 4],
	[5, 6, 7, 8],
	[9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/
/************************************************************************/


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.size() == 0)
			return result;
		int startI = 0, startJ = 0;
		int endI = matrix.size();
		int endJ = matrix[0].size();
		int i = 0,j = 0;
		while (true)
		{
			for (; j <endJ; ++j)  //向右走到尽头
				result.push_back(matrix[i][j]);
			++i;
			j = endJ - 1;
			if (!(i < endI))
				return result;

			for (; i < endI; ++i)  //向下走到尽头
				result.push_back(matrix[i][j]);
			i = endI - 1;
			--j;
			if (!(j >= startJ))
				return result;

			for (; j >= startJ; --j)  //向左走到尽头
 				result.push_back(matrix[i][j]); 
			--i; 
			j = startJ;
			if (!(i > startI))
				return result;

			for (; i > startI; --i)  //向上走到尽头
				result.push_back(matrix[i][j]);

			//尽头位置和起始位置更新
			++startI, ++startJ;
			--endI,--endJ;
			i = startI, j = startJ;

			if (startI >= endI || startJ >= endJ)
				break;
		}
		return result;
	}
};


int main(int argc, char* argv[])
{
	std::vector<std::vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9,10,11,12}
	};

	std::vector<std::vector<int>> matrix2 = {
		{1, 2, 3, 10, 11},
		{4, 5, 6, 11, 12},
		{7, 8, 9, 13, 14}
	};

	std::vector<std::vector<int>> matrix3 = {
		{7},
		{9},
		{6}
	};

	vector<int> result = Solution().spiralOrder(matrix2);
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
	return 0;
}